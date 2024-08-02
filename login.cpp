#include <bits/stdc++.h> 
using namespace std;
void NewRegister();
bool validEmail(string);
bool validfirstname(string);
bool validlastname(string);
bool validPassword(string);
void verificationcode();
void Login();
int main()
{
    cout<<"THIS IS A LOGIN/REGISTER PAGE"<<endl;
    cout<< "Welcome!" << endl;
    cout<< "Let's begin the PROCESS.." << endl
         << endl;

    NewRegister();

    return 0;
}
void NewRegister() 
{

    string NewRegister, Username, Password, firstname, lastname, email;

    cout << "New register?  \n(Note: if you are a  NEW user type 'Yes', otherwise type 'No') \n";
    
    cin >> NewRegister; 
    cin.ignore();

    if (NewRegister == "Yes" || NewRegister == "yes" )
    {
        cout << "First name : "; 
        cin >> firstname;
        while (validfirstname(firstname) == false)
        {
            cout << "The first name is not valid please try again : " << endl;
            cin >> firstname;
        }
        cout << endl
             << "Valid first name." << endl
             << endl;


        cout << "Last name : "; 
        cin >>lastname ;
        while (validlastname(lastname) == false)
        {
            cout << "The last name is not valid please try again : " << endl;
            cin >> lastname;
        }
        cout << endl
             << "Valid last name." << endl
             << endl;

        cout << "Email : "; 
        cin >> email;
        while (validEmail(email) == false)
        {
            cout << "The email address is not valid please try again : " << endl;
            cin >> email;
        }
        cout << endl
             << "Valid email address." << endl
             << endl;

        cout << "Password : \n(Note: your password must be at least one digit,one special character, one uppercase letter, and one lowercase letter) \n"; // enter password
        cin >> Password;
        while (validPassword(Password) == false)
        {
            cout << "The password is not valid please try again : " << endl;
            cin >> Password;
        }
        cout << endl
             << "Valid password." << endl
             << endl;

        cout << "Registration completed! \n" << endl;
        verificationcode();
    }
    else if (NewRegister == "No"  ||NewRegister == "no") 
    {
		string Username, Password;
    cout << endl    << "     Log in       " << endl<< endl;
    cout << "Enter your username :" << endl;
    getline(cin, Username);

    cout << "Enter your password :" << endl;
    cin >> Password;

    cout << endl
         << "Login success!" << endl;
    }
}
bool validfirstname(string firstname) 
{
    if (firstname[0] >= 'A' && firstname[0] <= 'Z')
      return true;
	  else
	  return false;
}
bool validlastname(string lastname) 
{
    if (lastname[0] >= 'A' && lastname[0] <= 'Z')
      return true;
    
    else 
  	 return false;
       
    
}
bool validEmail(string email) 
{
    int AT = -1, dot = -1;                                                            
    int counterforAT = 0, counterforDot = 0;                                          
    if ((email[0] >= 'a' && email[0] <= 'z') || (email[0] >= 'A' && email[0] <= 'Z')) 
    {
        for (int i = 0; i < email.length(); i++)
        {
            if (email[i] == '@') 
            {
                AT = i;
                ++counterforAT;
            }

            else if (email[i] == '.') 
            {
                dot = i;
                ++counterforDot;
            }
        }
        if (AT == -1 || dot == -1) 

            return false;

        if (AT > dot) 

            return false;

        if (counterforDot > 1 || counterforAT > 1)
            return false;

        return !(dot >= (email.length() - 1));
    }
    else if (email[0] >= '0' && email[0] <= '9') 
    {
        return false;
    }
    else 
    {
        return false;
    }
}
bool validPassword(string password) 
{
    int digit = 0, uppercase = 0, lowercase = 0, specialChar = 0; 
    if (password.length() >= 8 && password.length() <= 15)
    {

        if (password.find(" ") == -1)
        {
            for (int i = 0; i < password.length(); i++)
            {
                if (password[i] >= '0' && password[i] <= '9')
                {
                    ++digit;
                }
                else if (password[i] >= 'a' && password[i] <= 'z')
                {
                    ++lowercase;
                }
                else if (password[i] >= 'A' && password[i] <= 'Z')
                {
                    ++uppercase;
                }
                else if (password[i] == '@' || password[i] == '#' || password[i] == '_')
                {
                    ++specialChar;
                }
            }

            if (digit == 0 || uppercase == 0 || lowercase == 0 || specialChar == 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
        else if (password.find(" ") != -1)
        {

            return false;
        }
    }

    cout << "Note : your password length less than 8 characters or more than 15 characters." << endl;
    return false;
}
void verificationcode() 
{
    int code ;

    cout << "We have sent a verification code to your email to confirm your account." << endl
         << "Please check your email." << endl;

  
     cout<<"Email message: Your verification code is  ";
    srand(time(0));

	for (int i = 0; i <= 3; i++)
	{
		cout << rand() % 10 ;
	}
    cout<<"\n";

    cout<<"Enter the verification code here : \n";
	cin>>code;

    cout << "Your account has been verified." << endl;
    Login();
}
void Login()
{
    string Username, Password;

    cin.ignore();
    cout << endl    << "     Log in       " << endl<< endl;
    cout << "Enter your username :" << endl;
    getline(cin, Username);

    cout << "Enter your password :" << endl;
    cin >> Password;

    cout << endl
         << "Login success!" << endl;
}