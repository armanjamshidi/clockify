#include "project.hpp"
int num_users = 0;

int s_login, a, project_setting_command, b, x, ID = 0, id = 0, selected_project;
USER users[100];
void login_menu(int command)
{
    switch (command)
    {
    case 1:
        define_new_project();
        return;
    case 2:
        Record_project_time();
        return;
    case 3:
        show_reporting();
        return;
    case 4:
        Projects_Settings();
        return;
    case 5:
        show_users_settings();
        return;
    case 6:
        logout();
        return;
    case 7:
        show_start_menu();
        return;
    default:
        break;
    }
}
void show_login_menu()
{
    cout << endl
         << "\t"
         << "..... Main Menu ....."
         << "\t\n"
         << "1. Define new project"
         << "\n"
         << "2. record project time"
         << "\n"
         << "3. reporting"
         << "\n"
         << "4. Projects Settings"
         << "\n"
         << "5. User Settings"
         << "\n"
         << "6. Log out"
         << "\n"
         << "7. Exit"
         << "\n";
    cin >> s_login;
    login_menu(s_login);
}
void show_start_menu()
{
    int Menu;
    cout << endl
         << "\t"
         << "..... Bitok App ....."
         << "\t\n"
         << "1. SignUp"
         << "\n"
         << "2. Login"
         << "\n"
         << "3. Exit" << endl;
    cin >> Menu;
    menu(Menu);
}

void menu(int command)
{
    switch (command)
    {
    case 1:
        SignUp();
        return;
    case 2:
        Login();
        return;
    case 3:
        return;
    default:
        Exit();
    }
}

void SignUp()
{
    input_name();
    id++;
}

void Login()

{
    cout << endl
         << "\t"
         << "..... Login Menu ....."
         << "\t\n";
    string username, password;
    cout << ">> enter username: ";
    cin >> username;
    ID = search_username(username);
    if (ID != -1)
    {

        cout << ">>enter password: ";
        cin >> password;
        if (users[ID].pass == password)
        {

            cout << "Welcome to your account dear " << users[ID].name << " !" << endl;
            if (users[ID].num_projects == 100)
            {
                cout << users[ID].name << ", you came here for first time \nSo let's create a project.\n";
                define_new_project();
            }
            else
            {
                show_login_menu();
            }
        }
        else
        {
            cout << "Password or Username is not correct. Try again!\n";
            Login();
        }
    }
    else
    {
        cout << "\nA user with this username is not registered in the program.\n";
    }
}

void Exit()
{
}
bool checkername(string name)
{
    char c;
    if (name.length() > 20)
    {
        cout << "error length>20";

        return false;
    }
    else
        return true;
}
bool phone_number_checker(string number)
{
    if (number.length() == 11)
    {
        int i = 0;
        while (i < number.length())
            if (number[i] >= '0' && number[i] <= '9')
            {
                if (number[0] == '0' && number[1] == '9')
                {
                    i++;
                }
                else
                {
                    cout << "use 09 as default before your phone number";
                    return false;
                }
            }
            else
            {

                cout << "wrong input";
                return false;
            }
        return true;
    }

    else //11!
    {
        cout << "wrong input";
        return false;
    }
} //finish

bool check_username(string name)
{
    if (name.length() == 7)

    {
        int i = 0;
        while (i < name.length())
            if (name[i] >= '0' && name[i] <= '9')
            {
                if (name[0] == '9')
                {
                    if ((name[6] == '3' || name[6] == '5'))
                    {
                        i++;
                    }
                    else
                    {
                        cout << " the last character of student number should be 3 or 5  "
                             << "\n";
                        return false;
                    }
                }
                else
                {
                    cout << " the first character of student number should be 9  "
                         << "\n";
                    return false;
                }
            }
            else
            {
                cout << "please enter a digit number "
                     << "\n";
                return false;
            }
        return true;
    }
    else
    {
        cout << "enter a digit number with 7 character "
             << "\n";
        return false;
    }
}
//finish
bool check_pass(string pass)
{
    bool flag_small = false, flag_numb = false, flag_capital = false;
    if (8 <= pass.length() && pass.length() <= 13)
    {
        if (is_in_subspace(pass, 'a', 'z') && is_in_subspace(pass, 'A', 'Z') && is_in_subspace(pass, '0', '9'))
            return true;
        else
        {
            cout << "wrong pass";
            return false;
        }
    }
    else
    {
        cout << "wrong pass length , The Number of characters shuold be between 8 and 13 character \n";
        return false;
    }
} //finish

bool is_in_subspace(string pass, char start, char finish)
{
    bool flag = false;

    for (int i = 0; i < pass.length(); i++)
        if (start <= pass[i] && pass[i] <= finish)
            flag = true;
    return flag;
}
void input_name()
{
    char c;
    cout << endl
         << "\t"
         << "..... Sign Up Menu ....."
         << "\t\n"
         << ">> please enter your firstname :";
    cin >> users[id].name;
    if (checkername(users[id].name))
        input_family();
    else
    {
        cout << "do you want to repeat it?y/n :";
        cin >> c;
        if (c == 'y')
            input_name();
    }
} //finish input_name

void input_family()
{
    char c;
    cout << ">>please enter your family name:";
    cin >> users[id].family;
    if (checkername(users[id].family))
        input_phonenumber();
    else
    {
        cout << "do you want to repeat it?y/n :";
        cin >> c;
        if (c == 'y')
            input_family();
    }
} //finish input_family
void input_phonenumber()
{
    char c;
    cout << ">>please enter your phone number:";
    cin >> users[id].ph_num;
    if (phone_number_checker(users[id].ph_num))
        input_username();
    else
    {
        cout << "do you want to repeat it?y/n :";
        cin >> c;
        if (c == 'y')
            input_phonenumber();
    }
} //finish input_phonenumber
void input_username()
{
    char c;
    cout << ">>please enter username:";
    cin >> users[id].username;
    if (check_username(users[id].username) == 1 && repeatitous_user(users[id].username) == 0)
    {

        input_password();
    }
    else
    {
        cout << "do you want to repeat it?y/n :";
        cin >> c;
        if (c == 'y')
            input_username();
    }
} //finish input_pusername
void input_password()
{
    ;
    char c;
    cout << ">>please enter password:";
    cin >> users[id].pass;
    if (check_pass(users[id].pass))
    {
        input_confirm();
    }
    else
    {
        cout << "do you want to repeat it?y/n :";
        cin >> c;
        if (c == 'y')
            input_password();
    }
} //finish password
void input_confirm()
{

    char c;

    cout << ">>enter password confirm:";
    cin >> users[id].pass_confirm;
    if (users[id].pass_confirm == users[id].pass)

        cout << endl
             << ":) congratualtions (:" << endl;

    else
    {
        cout << "do you want to repeat it?y/n:";
        cin >> c;
        if (c == 'y')
            input_confirm();
    }
}

int search_username(string user)
{
    for (int i = 0; i <= 100; i++)
    {
        if (i != id && (users[i].username == user))
            return i; // در صورت وجود شماره خانه را میدهد
    }
    return -1; //  نام کاربری در لیست ذخیره موجود نیست و -1 میدهد
}

bool repeatitous_user(string username)
{
    int a = 0;
    for (int i = 0; i <= id; i++)
    {
        if (users[i].username == username)
        {
            a++;
        }
    }
    if (a == 1)
        return false;
    else
        return true;
}
bool repeatitous_project(string project)
{
    int a = 0;
    for (int i = 100; i <= users[ID].num_projects; i++)
    {
        if ((users[ID].project[i].project_name == project))
        {
            a++;
        }
    }
    if (a == 1)
        return false;
    else
        return true;
}
void define_new_project()
{

    cout << endl
         << "\t"
         << "..... Define New Project ....."
         << "\t\n"
         << "1. your project name is: ";

    getline(cin, users[ID].project[users[ID].num_projects].project_name);
    getline(cin, users[ID].project[users[ID].num_projects].project_name);
    while (true)
    {
        if (repeatitous_project(users[ID].project[users[ID].num_projects].project_name) == 0)
        {
            break;
        }
        else
        {
            cout << "this project name has already been used";
            getline(cin, users[ID].project[users[ID].num_projects].project_name);
        }
    }
    cout << "2. Number of member is:";
    cin >> users[ID].project[users[ID].num_projects].members_number;
    cout << "3. project manager : ";
    cin.ignore();
    getline(cin, users[ID].project[users[ID].num_projects].admin);
    cout << "4. project salary: ";
    cin >> users[ID].project[users[ID].num_projects].salary;
    while (true)
    {
        if (users[ID].project[users[ID].num_projects].salary == 0)
        {
            cout << "0 is not acceptable , please try again";
            cin >> users[ID].project[users[ID].num_projects].salary;
        }
        else
        {
            break;
        }
    }
    cout << "\n";
    users[ID].num_projects++;

    show_login_menu();
}

void Record_project_time()
{
    PROJECT project;
    cout << endl
         << "\t"
         << "..... Record Project Time ....."
         << "\t\n";
    x = show_project();

    cout << ">> Enter the task name : ";
    cin.ignore();
    getline(cin, users[ID].project[x].task[users[ID].project[x].num_tasks].task_name);
    //time_t now = time(0);
    //char *dt = ctime(&now);
    // cout << "date :" << dt;
    // users[ID].project[x].task[users[ID].project[x].num_tasks].date_start = dt;
    // cout << "time :";
    // cin >> users[ID].project[x].task[num_tasks].time;

    users[ID].project[x].num_tasks++;
    task_time();
    //show_login_menu();
}

void task_time()
{
    cout << endl
         << "\t"
         << "..... Task Time ....."
         << "\t\n";
    string word;
    time_t start, finish;
    cout << ">>Enter the word (start) to record task time\n>>else Enter (skip) to skip: ";
    cin >> word;
    if (word == "start")
    {
        time(&start);
        char *date_start = ctime(&start);
        cout << "\nTask start time: " << date_start;
        cout << "Your task time has started!\nComplete the project and enter the word (finish) when done: ";
        cin >> word;

        if (word == "finish")
        {
            time(&finish);
            int time_taken = int(finish - start);

            char *date_end = ctime(&finish);
            cout << "Task finish time: " << date_end;

            users[ID].project[x].task[users[ID].project[x].num_tasks - 1].date_start = date_start;
            users[ID].project[x].task[users[ID].project[x].num_tasks - 1].date_end = date_end;

            int seconds, minutes, hours;
            minutes = time_taken / 60;
            seconds = time_taken % 60;
            hours = minutes / 60;
            minutes = minutes % 60;

            cout << "Time to perform this task = " << hours << " : " << minutes << " : " << seconds << endl;
            ;
            users[ID].project[x].task[users[ID].project[x].num_tasks - 1].total_hours = hours;
            users[ID].project[x].task[users[ID].project[x].num_tasks - 1].total_minutes = minutes;
            users[ID].project[x].task[users[ID].project[x].num_tasks - 1].total_seconds = seconds;

            users[ID].done_task++;
            show_login_menu();
        }

        cout << "New task successfully created !\n";
    }
    else if (word == "skip")
    {
        cout << "New task successfully created !\n";
        show_login_menu();
    }
    else
    {
        cout << "Wrong input ! Try again.\n\n";
        task_time();
    }
}
int show_project()
{
    cout << endl
         << "\t"
         << "..... Project Setting ....."
         << "\t\n";
    int x;
    for (int i = 100; i < users[ID].num_projects; i++)
        cout << i - 99 << ". " << users[ID].project[i].project_name << endl;
    cout << "\n>> Choose your project: ";
    cin >> x;
    if (x > users[ID].num_projects)
    {
        cout << "\n << Your input is wrong! please try again. >>\n";
        return show_project();
    }

    return (x + 99);
}

void show_reporting()
{
    cout << endl
         << "\t"
         << "..... Reporting ....."
         << "\t\n";
    cout << "1. Overview report\n2. Advanced report\n3. Login menu" << endl;
    int report_command;
    cin >> report_command;
    reporting(report_command);
}
void reporting(int command)
{
    switch (command)
    {
    case 1:
        summary_reporting();
        break;
    case 2:
        detailed_reporting();
        break;
    case 3:
        show_login_menu();
    default:
        cout << "Wrong input !" << endl;
        show_reporting();
        break;
    }
}
void summary_reporting()
{
    cout << endl
         << "\t"
         << "..... Summery Reporting ....."
         << "\t\n";
    cout << "Total number of projects: " << users[ID].num_projects << endl
         << "Total number of performed tests: " << users[ID].done_task << endl
         << "Total time spent on all the tasks = ";
    total_time();
    cout << endl;
    show_reporting();
}
void detailed_reporting()
{
    cout << endl
         << "\t"
         << "..... Detailed Reporting ....."
         << "\t\n";
    int project_Num = 0, task_Num = 0;
    string word1, word2;
    int hours = 0, minutes = 0, seconds = 0;
    cout << "\nadvanced reporting menu"
         << "\n"
         << "enter the name of each project and then type (end)\n(enter the word (all) if you want all the projects):\n";
    while (true)
    {
        getline(cin, word1);
        if (word1 == "all")
        {
            project_Num = users[ID].num_projects - 100;
            break;
        }
        if (word1 == "end")
        {
            break;
        }
        for (int i = 100; i <= users[ID].num_projects; i++)
        {
            if (word1 == users[ID].project[i].project_name)
            {
                project_Num++;
            }
        }
    }

    cout << "Enter the name of each task and then press Enter Key, then type (end)\n(enter the word (all) if you want all the tasks):\n";
    while (true)
    {
        getline(cin, word2);
        if (word2 == "all")
        {

            for (int i = 100; i < users[ID].num_projects; i++)
            {
                for (int j = 100; j < users[ID].project[i].num_tasks; j++)
                {
                    task_Num++;
                    hours = hours + users[ID].project[i].task[j].total_hours;
                    minutes = minutes + users[ID].project[i].task[j].total_minutes;
                    seconds = seconds + users[ID].project[i].task[j].total_seconds;
                }
            }
            break;
        }

        if ("end" == word2)
        {
            break;
        }

        for (int i = 100; i < users[ID].num_projects; i++)
        {

            for (int j = 100; j < users[ID].project[i].num_tasks; j++)
            {

                if (word2 == users[ID].project[i].task[j].task_name)
                {

                    task_Num++;
                    hours = hours + users[ID].project[i].task[j].total_hours;
                    minutes = minutes + users[ID].project[i].task[j].total_minutes;
                    seconds = seconds + users[ID].project[i].task[j].total_seconds;
                }
            }
        }
    }

    minutes = minutes + (seconds / 60);
    hours = hours + (minutes / 60);
    minutes = minutes % 60; //Remaining minutes
    seconds = seconds % 60; //Remaining seconds

    cout << "Number of projects selected: " << project_Num << endl
         << "Number of tasks selected: " << task_Num << endl
         << "Total time that spent on all tasks = " << hours << " : " << minutes << " : " << seconds << endl;
    show_reporting();
}

void total_time()
{
    int hours = 0, minutes = 0, seconds = 0;
    for (int i = 100; i <= users[ID].num_projects; i++)
    {
        for (int j = 100; j <= users[ID].project[i].num_tasks; j++)
        {
            hours = hours + users[ID].project[i].task[j].total_hours;
            minutes = minutes + users[ID].project[i].task[j].total_minutes;
            seconds = seconds + users[ID].project[i].task[j].total_seconds;
        }
    }

    minutes = minutes + (seconds / 60);
    hours = hours + (minutes / 60);
    minutes = minutes % 60;
    seconds = seconds % 60;
    cout << hours << " : " << minutes << " : " << seconds;
}

void Projects_Settings()
{

    selected_project = show_project();
    desired_project();
}

void desired_project()
{
    cout << endl
         << "\t"
         << "..... Project: " << users[ID].project[selected_project].project_name << " ....."
         << "\t\n";
    cout << "1. change the number of members"
         << "\n"
         << "2. rename the admin of project"
         << "\n"
         << "3. increase your salary "
         << "\n"
         << "4. delete project "
            "\n"
         << "5. back to main page"
         << "\n";

    cin >> project_setting_command;
    show_project_settings(project_setting_command);
}

void show_project_settings(int command)
{
    switch (command)
    {
    case 1:
        change_member_numbers();
        break;
    case 2:
        rename_admin();
        break;
    case 3:
        increase_salary();
        break;
    case 4:

        delete_project();
        break;
    case 5:
        show_login_menu();
        break;
    default:
        cout << "select again"
             << "\n";
        desired_project();
    }
}

void logout()
{
    return ;
}

void change_member_numbers()
{
    cout << endl
         << "\t"
         << "..... Change Member Numbers ....."
         << "\t\n";
    PROJECT project;
    cout << "enter the new number of members :";
    cin >> users[ID].project[users[ID].num_projects].members_number;
    desired_project();
}

void rename_admin()
{
    cout << endl
         << "\t"
         << "..... Rename Admin ....."
         << "\t\n";
    PROJECT project;
    cout << "the new project admin is : ";
    cin.ignore();
    getline(cin, users[ID].project[users[ID].num_projects].admin);
    desired_project();
} //finish

void increase_salary()
{
    cout << endl
         << "\t"
         << "..... Increase Salary ....."
         << "\t\n";
    PROJECT project;
    cout << "previous salary:";
    cout << users[ID].project[users[ID].num_projects].salary;
    cout << "Enter the new salary :";
    cin >> users[ID].project[users[ID].num_projects].new_project_salary;
    while (1)
    {
        if (users[ID].project[users[ID].num_projects].new_project_salary <= users[ID].project[users[ID].num_projects].salary)
        {
            cout << "The new salary should be higher than the previous salary ):\n>>please try again: ";
            cin >> users[ID].project[users[ID].num_projects].new_project_salary;
        }
        else
        {
            break;
        }
    }
    cout << "New salary is : " << users[ID].project[users[ID].num_projects].new_project_salary;
    desired_project();
}

void delete_project()
{
    cout << endl
         << "\t"
         << "..... Delete Project ....."
         << "\t\n";

    if (users[ID].num_projects == 101)
    {
        cout << "You only have one project and you can not delete it!\n";
        desired_project();
    }
    else
    {
        users[ID].num_projects--;
        cout << "The project completely deleted.\nNew list is:";
        for (int i = 100; i < selected_project; i++)
        {
            cout << i - 99 << ". " << users[ID].project[i].project_name << endl;
            ;
        }

        for (int i = selected_project; i < users[ID].num_projects; i++)
        {
            users[ID].project[i] = users[ID].project[i + 1];
            cout << i - 99 << ". " << users[ID].project[i].project_name << endl;
            ;
        }

        desired_project();
    }
}
void show_users_settings()
{
    cout << endl
         << "\t"
         << "..... Show User Setting ....."
         << "\t\n"
         << "1. Username\n2. Phone number\n3. Password\n4. Login menu" << endl
         << ">> Select one of the options above to make the change: ";
    int user_setting_command;
    cin >> user_setting_command;
    user_settings(user_setting_command);
}

void user_settings(int command)
{
    switch (command)
    {
    case 1:
        username_setting();
        return;
    case 2:
        phoneNumber_setting();
        return;
    case 3:
        password_setting();
        return;
    case 4:
        show_login_menu();
        return;
    default:
        cout << "Wrong input !" << endl;
        ;
        show_users_settings();
        break;
    }
}

void username_setting()
{
    cout << endl
         << "\t"
         << "..... Username Setting ....."
         << "\t\n"
         << ">> Enter the new username: ";
    cin >> users[ID].username;
    if (check_username(users[ID].username) && (repeatitous_user(users[ID].username)) == 0)
    {
        cout << "Username changed successfully !\n";
        show_users_settings();
    }
    else
    {
        cout << "this user have been already used";
        username_setting();
    }
}
void phoneNumber_setting()
{
    cout << endl
         << "\t"
         << "..... Phone Number Setting ....."
         << "\t\n"
         << ">> Enter the new phone number: ";
    cin >> users[ID].ph_num;
    phone_number_checker(users[ID].username);
    cout << "Phone number changed successfully !\n\n";
    show_users_settings();
}

void password_setting()
{
    cout << endl
         << "\t"
         << "..... Password Setting ....."
         << "\t\n"
         << ">> Enter the previous password: ";
    cin >> users[ID].pass;

    while (true)
    {
        if (users[ID].pass_confirm == users[ID].pass)
        {
            cout << ">> Enter the new password: ";
            cin >> users[ID].pass;
            check_pass(users[ID].pass);
            (users[ID].pass_confirm == users[ID].pass);
            cout << "Password changed successfully !\n\n";
            show_users_settings();
        }
        else
        {
            cout << "The previous password was incorrect.\n>> Enter again: ";
            cin >> users[ID].pass;
        }
    }
}
