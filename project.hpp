#include <iostream>
#include <string>
#include<ctime>
using namespace std;

struct TASK
{
    string task_name, date_start, date_end;
    int total_hours = 0, total_minutes = 0, total_seconds = 0;
};
struct PROJECT
{
    string project_name;
    string admin;
    int members_number;
    int salary;
    int new_project_salary;
    int num_tasks = 100;
    TASK task[150];
};

struct USER
{
    string username,  name, pass,pass_confirm, ph_num, family;
    int num_projects =100;
    int done_task =0;
    PROJECT project[120];
};



void show_start_menu();
void menu(int command);
void SignUp();
void Login();
void Exit();
bool checkername(string name);
bool checker_phone_number(string number);
bool check_username(string name);
bool check_pass(string pass);
void input_name();
void input_family();
void input_phonenumber();
void input_username();
void input_password();
void input_confirm();
bool repeatitous_user(string username);
void logout();
void Projects_Settings();
void reporting(int command);
void Record_project_time();
void define_new_project();
void login_menu(int command);
void show_login_menu();
bool is_in_subspace(string s, char start, char end);
void desired_project();
void show_project_settings(int command);
void change_member_numbers();
void rename_admin();
void increase_salary();
int search_username(string user);
int show_project();
bool repeatitous_project(string project);
void delete_project();
void show_users_settings();
void user_settings(int command);
void username_setting();
void phoneNumber_setting();
void password_setting();
void task_time();
void summary_reporting();
void detailed_reporting();
void show_reporting();
void total_time();