#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    //Declaration Of Variables

    //OverTime And Regular Time Variables
    const float regularRate = 25000.00;
    const float overtimeRate = 37500.00;

    //Required Details Variables
    string firstName,lastName,indexNumber;
    int plan;
    int dependants;

    //Extra Tax
    const float gussTax = 0.06;
    const float constituencyTax = 0.03;
    const float welfareTax = 0.02;

    //NHIS Deduction Variable
    const float nhisDeduct = 5000.00;

    //Finance Variables
    float extradiff;
    float nationalTax;
    float natTaxDeductAmount;
    float totalExtraTaxAmount;
    float grossPay;
    float finalGrossPay;
    float extraTaxPay;
    float netPay;
    float dependantsFee;

    //Variables For The Calculating The Hours
    float mh,wh,hours;

    //Errors
    string errorText = "\nSorry, Your Input Cant Be Negative..Enter A Valid Input.";
    string abuseError = "\nYour Have Been Abused, Please Contact Any Human Resource Agency And Make A Report.";

    //Code Begins Here
    cout << "@@@...JB and SONS Consultants Limited...@@@" << endl;
    cout << "\n...Workers Gross Pay..." << endl;

    //Details Input
    cout << "\nWelcome, Please Fill The Following Details To Get Started" << endl;
    cout << "\nEnter Your First Name: ";
    cin >>firstName;
    cout << "\nEnter Your last Name: ";
    cin >>lastName;
    cout << "\nEnter Your Index Number: ";
    cin >>indexNumber;
    while (true) {
    cout << "\nFor Your NHIS Please Enter Your Number Of Dependants." <<endl;
    cout << "(Number Of Individuals Who Depend On You For A Living. E.g: wife,children,relatives,guardian,etc."<< endl;
    cout << "Dependants: ";
    cin >>dependants;
    if (dependants>3){
        int difference = dependants-3;
        dependantsFee = difference*nhisDeduct;
        break;
    }else if (dependants>=0 && dependants<=3){
        dependantsFee = 0;
        break;
    }else {
        cout <<errorText<<endl;
        continue;
    }
    }
    cout << "\nPlease wait while we submit your details..." << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << "\nDetails Submitted..."<< endl;
    cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << endl;
    cout << "\nFollow The Steps Below"<< endl;

    //Code For Getting The Number Of Hours Worked And Calculating The Gross Pay
    //Ensures The Correct Data Input
    while (true) {
    cout <<"\n...Select Your Hour Format..." << endl;   //Various Payment Plans
    cout <<"1. Hours Per Week."<< endl;
    cout <<"2. Hours Per Month."<< endl;
    cout <<"\n: ";
    cin>>plan;
        if (plan==1) {
            while (true) {
                cout <<"\nTotal Working Hours In A Week: ";
                cin>>wh;
                hours = wh * 4.43;
                if (wh>=0){
                    if (wh>=0 && wh<=40) {
                        grossPay = hours * regularRate;
                    }else if (wh>40 && wh<=84) {
                        extradiff = hours - 40;
                        grossPay = (40 * regularRate) + (extradiff * overtimeRate);
                    }else{
                        cout <<abuseError<< endl;
                        return 0;
                    }
                    break;
                }else{
                    cout <<errorText<< endl;
                    continue;
                }
            }
            break;
        }else if (plan==2) {
            while (true){
                cout <<"\nTotal Working Hours In A Month: ";
                cin>>mh;
                hours = mh;
                if (mh>=0){
                    if (mh>0 && mh<=177.2) {
                        grossPay = hours * regularRate;
                    }else if (mh>177.2 && mh<=372.12) {
                        extradiff = hours - 177.2;
                        grossPay = (177.2 * regularRate) + (extradiff * overtimeRate);
                    }else {
                        cout <<abuseError<< endl;
                        return 0;
                    }
                    break;
                }else{
                    cout <<errorText<< endl;
                    continue;
                }
            }
            break;
        }else {
            cout <<"Invalid Entry Try Again\n";
            continue;
        }
    }

    //National Tax Scale
    if (grossPay <= 125000.00){
        nationalTax = 0;
        natTaxDeductAmount = 0;
        finalGrossPay = grossPay;
    }else if (grossPay > 125000.00 && grossPay <= 250000.00) {
        nationalTax = 0.05;
        finalGrossPay = grossPay-(nationalTax*grossPay);
    }else if (grossPay > 250000.00 && grossPay <= 1750000.00) {
        nationalTax = 0.1;
        finalGrossPay = grossPay-(nationalTax*grossPay);
    }else if (grossPay > 1750000.00 && grossPay <= 2750000.00) {
        nationalTax = 0.15;
        finalGrossPay = grossPay-(nationalTax*grossPay);
    }else if (grossPay > 2750000.00 && grossPay <= 5000000.00) {
        nationalTax = 0.2;
        finalGrossPay = grossPay-(nationalTax*grossPay);
    }else if (grossPay > 5000000.00) {
        nationalTax = 0.3;
        finalGrossPay = grossPay-(nationalTax*grossPay);
    }else {
        return 0;
    }

    //Finance Calculations
    float gussTaxAmount = finalGrossPay*gussTax;
    float constituencyTaxAmount = finalGrossPay*constituencyTax;
    float welfareTaxAmount = finalGrossPay*welfareTax;
    totalExtraTaxAmount = gussTaxAmount+constituencyTaxAmount+welfareTaxAmount;
    extraTaxPay = finalGrossPay-totalExtraTaxAmount;
    natTaxDeductAmount = grossPay*nationalTax;
    netPay = extraTaxPay-dependantsFee;

    cout << "\nPlease wait while we finish the calculations..." << endl;
    this_thread::sleep_for(chrono::seconds(5));
    cout << "\nResults;" << endl;
    cout << "\n\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n" << endl;

    //Output Data
    cout <<"Staff Name: "<<firstName<<" "<<lastName<< endl;
    cout <<"Staff ID: "<<indexNumber<< endl;
    cout <<"Total Working Hours This Month: "<<hours<< endl;

    cout <<"\n$$$...TAX DETAILS AND DEDUCTIONS...$$$\n"<< endl;
    //National Tax
    cout <<"National Tax(According To Gross Pay): "<<nationalTax*100<<"%"<< endl;
    cout <<fixed<<setprecision(2)<<"Amount: "<<"Gh Cedis "<<natTaxDeductAmount<< endl;
    //GUSS Tax
    cout <<"\nGUSS Tax: "<<gussTax*100<<"%"<< endl;
    cout <<fixed<<setprecision(2)<<"Amount: "<<"Gh Cedis "<<gussTaxAmount<< endl;
    //Constituency Tax
    cout <<"\nConstituency Tax: "<<constituencyTax*100<<"%"<< endl;
    cout <<fixed<<setprecision(2)<<"Amount: "<<"Gh Cedis "<<constituencyTaxAmount<< endl;
    //Welfare Tax
    cout <<"\nWelfare Tax: "<<welfareTax*100<<"%"<< endl;
    cout <<fixed<<setprecision(2)<<"Amount: "<<"Gh Cedis "<<welfareTaxAmount<< endl;
    //Total Amount Deducted
    cout <<fixed<<setprecision(2)<<"\nTotal Amount Deducted: "<<"Gh Cedis "<<totalExtraTaxAmount<< endl;
    //Dependants And Fee
    cout <<"\nDependants: "<<dependants<< endl;
    cout <<fixed<<setprecision(2)<<"NHIS Fee: "<<"Gh Cedis "<<dependantsFee<< endl;
    //Gross Pay
    cout <<fixed<<setprecision(2)<<"\nGross Pay: "<<"Gh Cedis "<<grossPay<< endl;
    cout <<fixed<<setprecision(2)<<"Pay(After National Tax): "<<"Gh Cedis "<<finalGrossPay<< endl;
    cout <<fixed<<setprecision(2)<<"Pay(After Extra Tax): "<<"Gh Cedis "<<extraTaxPay<< endl;
    //Net Pay
    cout <<fixed<<setprecision(2)<<"\nNet Pay: "<<"Gh Cedis "<<netPay<< endl;

    cout << "\nThanks For Using Our Services..." << endl;

    return 0;
}
