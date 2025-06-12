#include <iostream>
#include <string>
#include<iomanip>
#include <algorithm>
using namespace std;

// Structure for Laptop
struct Laptop {
    int laptop_id;
    string laptop_name;
    string model;
    string version;
    int price;
    string RAM;
    string SSD;
    string colours_available;
    string processor;
};

// Structure for Phones
struct Phone {
    int phone_id;
    string phone_name;
    string model;
    int price;
    string RAM;
    string Storage;
    string colours_available;
    string camera_resolution;
};

// Structure for Smartwatch
struct Smartwatch {
    int smartwatch_id;
    string product_name;
    int price;
    string capacity;
    string battery_health;
    string resolution;
};

// Function for user management
void user_management() {
    string name, email, password;
    cout << "********* Register TO Online Shopping Store *********" << endl;
    cout << "Enter your Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your Email: ";
    cin >> email;
    cout << "Enter your Password: ";
    cin >> password;
}

void orderdetails(){
	int zip,s_d,p_n;
	string f_n,l_n,street,city,country;
	    cout<<"\nFirst name :";
		cin>>f_n;
		cout<<"\nlast name :";
		cin>>l_n;
		cout<<"\nStreet Address :";
		cin.ignore();
        getline(cin, street);
        cout<<"\nTown / city :";
        cin.ignore();
        getline(cin, city);
        cout<<"\nState / Country :";
        cin.ignore();
        getline(cin, country);
        cout<<"\nPostcode/ZIP :";
        cin>>zip;
        cout<<"\nphone number :";
        cin>>p_n;
}

// Function for payment method
void paymentmethod(int totalCost){
	int pay,acc_number,s_d;
	
	cout<<endl;
	cout<<"choose a payment method"<<endl;
	cout<<"press 1.Cash On Delivery"<<endl;
	cout<<"press 2.Online Payment"<<endl<<endl;
	cin>>pay;
	if(totalCost>0){
	
	if(pay==1){
		orderdetails();
        
        cout<<"\nSHIPPING DDETAILS :";
        cout<<"\n1.Other city: Rs400 ";
        cout<<"\n2.Islamabad Delivery: Rs200 ";
        cout<<"\n3.self pick: Rs0 ";
        cin>>s_d;
        if(s_d==1){
		
        cout<<"\nAmount "<<totalCost+400<<"Rs";
		cout<<"\nYOUR ORDER HAS BEEN SUCCESSFULLY PLACED"<<endl;}
		else if(s_d==2){
		
        cout<<"\nAmount "<<totalCost+200<<"Rs";
		cout<<"\nYOUR ORDER HAS BEEN SUCCESSFULLY PLACED"<<endl;}
		else{
		
        cout<<"\nAmount "<<totalCost<<"Rs";
		cout<<"\nYOUR ORDER HAS BEEN SUCCESSFULLY PLACED"<<endl;}
	}
	if(pay==2){
		orderdetails();
        
        cout<<"\n\nSHIPPING DDETAILS :";
        cout<<"\n1.Other city: Rs400 ";
        cout<<"\n2.Islamabad Delivery: Rs200 ";
        cout<<"\n3.self pick: Rs0 ";
        cin>>s_d;
        
        if(s_d==1){
            cout<<"\nEnter your acacount number:";
		cin>>acc_number;
        cout<<"\nAmount "<<totalCost+400<<"Rs";
        cout<<"\nPAYMENT SUCCESSFUL !"<<endl;
		cout<<"ORDER CONFIRMED !"<<endl;}
		
		else if(s_d==2){
			cout<<"\nEnter your acacount number:";
		cin>>acc_number;
        cout<<"\nAmount "<<totalCost+200<<"Rs has been deducted ";
		cout<<"\nPAYMENT SUCCESSFUL !"<<endl;
		cout<<"ORDER CONFIRMED !"<<endl;}
		
		else{
			cout<<"\nEnter your acacount number:";
		cin>>acc_number;
        cout<<"\nAmount "<<totalCost<<"Rs";
		cout<<"\nPAYMENT SUCCESSFUL !"<<endl;
		cout<<"ORDER CONFIRMED !"<<endl;}
		
	}}
}

// Sorting functions
void sortPhones(Phone p[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size;j++) {
            if (p[i].phone_name > p[j].phone_name) {
                // Swap the two phone elements
                Phone temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void sortLaptops(Laptop l[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (l[i].laptop_name > l[j].laptop_name) {
                // Swap the two laptop elements
                Laptop temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
        }
    }
}
void sortSmartwatches(Smartwatch s[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (s[i].product_name > s[j].product_name) {
                // Swap the two smartwatch elements
                Smartwatch temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

// Binary search functions
void binarySearchPhones(Phone p[], int size, const string& searchName) {
    int low = 0, high = size - 1;
    bool found = false;

    while (low <= high
	 ) {
        int mid = (low + high) / 2;
        if (p[mid].phone_name == searchName) {
            cout << "Phone Found: " << p[mid].phone_name <<" | Price: Rs. " << p[mid].price << endl;
            found = true;
            break;
        } else if (p[mid].phone_name < searchName) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Phone not found with name: " << searchName << endl;
    }
}

void binarySearchLaptops(Laptop l[], int size, const string& searchName) {
    int low = 0, high = size - 1;
    bool found = false;

    while (low <= high ) {
        int mid = (low + high) / 2;
        if (l[mid].laptop_name == searchName) {
            cout << "Laptop Found: " << l[mid].laptop_name<< " | Price: Rs. " << l[mid].price << endl;
            found = true;
            break;
        } else if (l[mid].laptop_name < searchName) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Laptop not found with name: " << searchName << endl;
    }
}

void binarySearchSmartwatches(Smartwatch s[], int size, const string& searchName) {
    int low = 0, high = size - 1;
    bool found = false;

    while (low <= high ) {
        int mid = (low + high) / 2;
        if (s[mid].product_name == searchName) {
            cout << "Smartwatch Found: " << s[mid].product_name<< " | Price: Rs. " << s[mid].price << endl;
            found = true;
            break;
        } else if (s[mid].product_name < searchName) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "Smartwatch not found with name: " << searchName << endl;
    }
}

// Wrapper function to search for items by name
void searchItemsBinary(Phone p[], Laptop l[], Smartwatch s[], int size) {
    string searchName;

    cout << "Enter the name of the item to search: ";
    cin.ignore();
    getline(cin, searchName);

    // Perform binary search for each category
    cout << "\nSearching in Phones...\n";
    binarySearchPhones(p, size, searchName);

    cout << "\nSearching in Laptops...\n";
    binarySearchLaptops(l, size, searchName);

    cout << "\nSearching in Smartwatches...\n";
    binarySearchSmartwatches(s, size, searchName);
}

// Function to display information of all phones
void displayPhones(Phone p[], int size) {
        // Table Header
    cout << "+----------+---------------+----------------------+------------+----------+---------------+----------------------------------------+--------------------+" << endl;
    cout << "| Phone ID | Phone Name    | Model                | Price (Rs) | RAM      | Storage       | Colours Available                      | Camera Resolution  |" << endl;
    cout << "+----------+---------------+----------------------+------------+----------+---------------+----------------------------------------+--------------------+" << endl;

    // Table Rows
    for (int i = 0; i < size; i++) {
        cout << "| " << setw(8) << left << p[i].phone_id << " | "
             << setw(13) << left << p[i].phone_name << " | "
             << setw(20) << left << p[i].model << " | "
             << setw(10) << left << p[i].price << " | "
             << setw(8)  << left << p[i].RAM << " | "
             << setw(13) << left << p[i].Storage << " | "
             << setw(38) << left << p[i].colours_available << " | "
             << setw(18) << left << p[i].camera_resolution << " |" << endl;
    }

    // Table Footer
    cout << "+----------+---------------+----------------------+------------+----------+---------------+----------------------------------------+--------------------+" << endl;
}
 


// Function to display information of all laptops
void displayLaptops(Laptop l[], int size) {
    // Table Header
    cout << "+-----------+------------------+----------------+------------------+------------+----------+---------------+-------------------------+----------------+" << endl;
    cout << "| Laptop ID | Laptop Name      | Model          | Version          | Price (Rs) | RAM      | SSD           | Colours Available       | Processor      |" << endl;
    cout << "+-----------+------------------+----------------+------------------+------------+----------+---------------+-------------------------+----------------+" << endl;

    // Table Rows
    for (int i = 0; i < size; i++) {
        cout << "| " << setw(9) << left << l[i].laptop_id << " | "
             << setw(16) << left << l[i].laptop_name << " | "
             << setw(14) << left << l[i].model << " | "
             << setw(16) << left << l[i].version << " | "
             << setw(10) << left << l[i].price << " | "
             << setw(8) << left << l[i].RAM << " | "
             << setw(13) << left << l[i].SSD << " | "
             << setw(23) << left << l[i].colours_available << " | "
             << setw(14) << left << l[i].processor << " |" << endl;
    }

    // Table Footer
    cout << "+-----------+------------------+----------------+------------------+------------+----------+---------------+-------------------------+----------------+" << endl;
}



// Function to display information of all smartwatches
void displaySmartwatches(Smartwatch s[], int size) {
   // Table Header
    cout << "+----------------+----------------+------------+----------------+-----------------+----------------+" << endl;
    cout << "| Smartwatch ID  | Product Name   | Price (Rs) | Capacity       | Battery Health  | Resolution     |" << endl;
    cout << "+----------------+----------------+------------+----------------+-----------------+----------------+" << endl;

    // Table Rows
    for (int i = 0; i < size; i++) {
        cout << "| " << setw(14) << left << s[i].smartwatch_id << " | "
             << setw(14) << left << s[i].product_name << " | "
             << setw(10) << left << s[i].price << " | "
             << setw(14) << left << s[i].capacity << " | "
             << setw(15) << left << s[i].battery_health << " | "
             << setw(14) << left << s[i].resolution << " |" << endl;
    }

    // Table Footer
    cout << "+----------------+----------------+------------+----------------+-----------------+----------------+" << endl;
}

void cartitems(Phone p[], Laptop l[], Smartwatch s[], int size) {
    int id1[6], toadd1, sum1 = 0, Q1[10], price1 = 0;
    string ph,lp,sw;
    cout << "\nDO YOU WANT TO ADD PHONES TO THE CART ?(YES/NO) " << endl;
    cin >>ph;
    if(ph == "yes" || ph == "YES" || ph == "Yes"){
    cout << "HOW MANY PHONES DO YOU WANT TO ADD TO THE CART? " << endl;
    cin >> toadd1;
    for (int i = 0; i < toadd1; i++) {
        cout << "Enter the IDs of products to add to the cart: " << endl;
        cin >> id1[i];
        cout << "Enter the Quantity of products you want " << endl;
        cin >> Q1[i];
    }}

    
    int id2[6], toadd2, sum2 = 0, Q2[10], price2 = 0;
    cout << "DO YOU WANT TO ADD LAPTOPS TO THE CART ?(YES/NO) " << endl;
    cin>>lp;
    if(lp == "yes" || lp == "YES" || lp == "Yes"){
    cout << "HOW MANY LAPTOPS DO YOU WANT TO ADD TO THE CART? " << endl;
    cin >> toadd2;
    for (int i = 0; i < toadd2; i++) {
        cout << "Enter the IDs of products to add to the cart: " << endl;
        cin >> id2[i];
        cout << "Enter the Quantity of products you want " << endl;
        cin >> Q2[i];
    }}

    
    int id3[6], toadd3, sum3 = 0, Q3[10], price3 = 0;
    cout << "DO YOU WANT TO ADD SMARTWATCHES TO THE CART ?(YES/NO) " << endl;
    cin>>sw;
    if(sw == "yes" || sw == "YES" || sw == "Yes"){
    cout << "HOW MANY SMARTWATCHES DO YOU WANT TO ADD TO THE CART? " << endl;
    cin >> toadd3;
    for (int i = 0; i < toadd3; i++) {
        cout << "Enter the IDs of products to add to the cart: " << endl;
        cin >> id3[i];
        cout << "Enter the Quantity of products you want: " << endl;
        cin >> Q3[i];
    }}

    if(ph == "yes" || ph == "YES" || ph == "Yes"){
    // Category: PHONES
    cout << "\nCategory: PHONES\n";
    cout << "-----------------------------------------------------" << endl;
    cout << "Items\t\tQuantity\tCost\n";
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < toadd1; i++) {
        for (int j = 0; j < size; j++) {
            if (id1[i] == p[j].phone_id) {
                if (Q1[i] > 1) {
                    price1 = Q1[i] * p[j].price;
                    sum1 += price1;
                    cout << p[j].phone_name << "\t\t" << Q1[i] << "\t\t" << price1 << " Rs" << endl;
                } else {
                    cout << p[j].phone_name << "\t\t" << Q1[i] << "\t\t" << p[j].price << " Rs" << endl;
                    sum1 += p[j].price;
                }
            }
        }
    }

    cout << "-----------------------------------------------------" << endl;
    cout << "Subtotal:\t\t\t" << sum1 << " Rs\n\n";}

    if(lp == "yes" || lp == "YES" || lp == "Yes"){
    // Category: LAPTOPS
    cout << "\nCategory: LAPTOPS\n";
    cout << "-----------------------------------------------------" << endl;
    cout << "Items\t\tQuantity\tCost\n";
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < toadd2; i++) {
        for (int j = 0; j < size; j++) {
            if (id2[i] == l[j].laptop_id) {
                if (Q2[i] > 1) {
                    price2 = Q2[i] * l[j].price;
                     sum2 += price2;
                    cout << l[j].laptop_name << "\t\t" << Q2[i] << "\t\t" << price2 << " Rs" << endl;
                } else {
                    cout << l[j].laptop_name << "\t\t" << Q2[i] << "\t\t" << l[j].price << " Rs" << endl;
                    sum2 += l[j].price;
                }
            }
        }
    }

    cout << "-----------------------------------------------------" << endl;
    cout << "Subtotal:\t\t\t" << sum2 << " Rs\n\n";}

    if(sw == "yes" || sw == "YES" || sw == "Yes"){
    // Category: SMARTWATCHES
   ;
    cout << "\nCategory: SMARTWATCHES\n";
    cout << "-----------------------------------------------------" << endl;
    cout << "Items\t\t\tQuantity\tCost\n";
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < toadd3; i++) {
        for (int j = 0; j < size; j++) {
            if (id3[i] == s[j].smartwatch_id) {
                if (Q3[i] > 1) {
                    price3 = Q3[i] * s[j].price;
                    sum3 += price3;
                    cout << s[j].product_name << "\t\t" << Q3[i] << "\t\t" << price3 << " Rs" << endl;
                } else {
                    cout << s[j].product_name << "\t\t" << Q3[i] << "\t\t" << s[j].price << " Rs" << endl;
                    sum3 += s[j].price;
                }
            }
        }
    }

    cout << "-----------------------------------------------------" << endl;
    cout << "Subtotal:\t\t\t" << sum3 << " Rs\n\n";}

    // Calculate and display the total cost
    int totalCost = sum1 + sum2 + sum3;
   
    cout << "Total Cost:\t\t\t" << totalCost << " Rs" << endl;
    cout << "-----------------------------------------------------" << endl;
    
    paymentmethod(totalCost);
    
}

int main() {
    int press,cat;
    string decide;
    int menu_decide;
    
    Phone p[5] = {
        {1, "iPhone", "iPhone 16 Pro Max", 540500, "8 GB", "1 TB", "Black Titanium", "48 MP"},
        {2, "Samsung", "Samsung A32", 71000, "4 GB", "128 GB", "Awesome Black", "64 MP"},
        {3, "OnePlus", "OnePlus 12", 219960, "2 GB", "256 GB", "Silky Black", "50 MP"},
        {4, "Infinix", "Infinix Note 12", 45499, "6 GB", "128 GB", "Ice Blue", "48 MP"},
        {5, "Huawei", "Huawei Mate 40", 228999, "8 GB", "512 GB", "Mystic Silver", "50 MP"}};

    Laptop l[5] = {
        {1, "Apple", "MacBook Air", "10.13.6", 224999, "16 GB", "512 GB", "Midnight Black", "i7"},
        {2, "HP", "Envy x360", "Windows 11", 204500, "16 GB", "512 GB", "Gold", "Ryzen 7"},
        {3, "Dell", "XPS 13", "Windows 11", 175000, "8 GB", "256 GB", "Frost", "i5"},
        {4, "Lenovo", "ThinkPad X1", "12th Gen", 75000, "16 GB", "256 GB", "Black", "i7"},
        {5, "Asus", "ZenBook 14", "Windows 10", 90000, "8 GB", "256 GB", "Ponder Blue", "i5"}
    };

    Smartwatch s[5] = {
        {1, "Sveston watch", 11000, "260 mAh", "5-7 days", "240x240"},
        {2, "Apple Ultra 2", 10000, "64 GB", "36 hours", "410x410"},
        {3, "Samsung Galaxy", 11100, "16 GB", "24 hours", "396x396"},
        {4, "Huawei Fit 3", 49000, "1.5 GB", "10 days", "1.82-inch"},
        {5, "LG W7 watch", 52000, "4 GB", "100 hours", "360x360"}
    };


    cout << "****************** WELCOME TO ONLINE SHOPPING STORE ******************" << endl;
    user_management();
    cout << "Press 1.view categories"<< endl;
    cout << "Press 2.search items " << endl;
    cout << "Press 3.Buy/Addtocart " << endl;
    cin  >> menu_decide;
    
    switch (menu_decide) {
        case 1:
        	cout << "Press 1.TO VIEW PHONES" << endl;  	
            cin>>cat;
            if(cat==1){
            	displayPhones (p, 5);
            	
			}
			else
			cout<<"invalid input "<<endl;
			
			
			cout << "Press 2.TO VIEW LAPTOPS" << endl;
			cin>>cat;
			if(cat==2){
            	displayLaptops(l, 5);
            	
			}
			else
			cout<<"invalid input "<<endl;
			
			
			cout << "Press 3.TO VIEW SMARTWATCHES" << endl;
			cin>>cat;
			if(cat==3){
            	displaySmartwatches(s, 5);
            	
            	
			}
			    cout<<endl;
            	cout<<"DO YOU WANT TO BUY PRODUCTS ? (YES/NO):";
            	cin>>decide;
            	if(decide == "yes" || decide == "YES" || decide == "Yes"){
            		cartitems(p,l,s,5);
            	}
            	
			
			else
			cout<<"invalid input "<<endl;
            break;
        case 2:
                // Sort arrays before performing binary search
                sortPhones(p, 5);
                sortLaptops(l, 5);
                sortSmartwatches(s, 5);

                // Call the binary search function
                searchItemsBinary(p, l, s, 5);
            break;
        case 3:
             cartitems(p,l,s,5);
             break;
        
        default:
            cout << "Invalid option! Please choose a valid category." << endl;
            break;
    }

    
    cout << "Thank you for shopping with us!" << endl;
    return 0;}
    



