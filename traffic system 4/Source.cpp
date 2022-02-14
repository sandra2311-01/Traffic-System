#include<iostream>
#include<string>
using namespace std;
struct date
{
	int day, month, year;

};
struct driver_info {
	int license;
	string name;
	date birth_date;
	int total_fines;
	string names_of_owned_cars[3];
	int plate_numbers[3];
};
struct saved_cars {
	int plate_numbers[20] = { 3256,4658,8228,7246,9362,2635 };
	string model[20] = { "subaru","honda","kia","peugeot","mini","hyundai" };
	int value_of_violation[20] = { 50,50,100,100,100 };
	string street_name_of_incident[20] = { "tayseer","madinaty","golf","tagamo3","tayseer" };
	date saved_dates_of_fines[20] = { 2,2,2019,1,1,2019,4,2,2019,5,9,2020,9,6,2017 };
	string status[20] = { "not paid","not paid","not paid","not paid","not paid" };
	int car_speed[20] = { 85,105,170,150,110 };
	int production_year[20] = { 2019,2018,2017,2016,2020,2001 };

}main_saved_info;
struct fine {
	int plate_number;
	int value_of_violation;
	string street_name;
	date date_of_fine;
	string status;
	int car_speed;
	int speed_limit;
};
struct registered_car {
	int plate_number;
	string model;
	int production_year;
	fine recorded_fines;
};
struct saved_info {
	string street_name[20] = { "tayseer","tagamo3","golf","madinaty" };
	int speed_street_limit[20] = { 60,100,120,80 };
}info;
void display_info(int number_of_cars, string response, registered_car c1[]) {
	cout << "Do you want to see information before payment?" << endl;
	cin >> response;
	if (response == "yes") {
		for (int i = 0; i < number_of_cars; i++) {
			cout << "car number " << i + 1 << " model is " << c1[i].model << endl;
			cout << "car number " << i + 1 << " production year is " << c1[i].production_year << endl;
			cout << "date of incident of car number " << i + 1 << " is " << c1[i].recorded_fines.date_of_fine.day << " " << c1[i].recorded_fines.date_of_fine.month << " " << c1[i].recorded_fines.date_of_fine.year << endl;
			cout << "street name regarding incident of car number " << i + 1 << " is " << c1[i].recorded_fines.street_name << endl;
			cout << "speed limit of street regarding incident of car number " << i + 1 << " is " << c1[i].recorded_fines.speed_limit << endl;
			cout << "speed of car " << i + 1 << " was " << c1[i].recorded_fines.car_speed << endl;
			cout << "violation of car " << i + 1 << " is " << c1[i].recorded_fines.value_of_violation << endl;
			cout << "enter amount you want to pay: " << endl;
		}
	}
	else if (response == "no") {
		cout << "enter amount you want to pay: " << endl;
	}

}
void full_payment(int amount, int total, int number_of_cars, registered_car c1[]) {
	cin >> amount;
	/*for (int i = 0; i < number_of_cars; i++) {
		c1[i].recorded_fines.value_of_violation = 2 * (c1[i].recorded_fines.car_speed - c1[i].recorded_fines.speed_limit);
		total = total + c1[i].recorded_fines.value_of_violation;
	}*/
	total = total - amount;
	if (total == 0 || total < 0) {
		for (int i = 0; i < number_of_cars; i++) {
			for (int j = 0; j < 20; j++) {
				if (c1[i].plate_number == main_saved_info.plate_numbers[j]) {
					main_saved_info.status[j] = "paid";
					c1[i].recorded_fines.status = main_saved_info.status[j];
				}
			}
			cout << "paid" << endl;
		}
		cout << "your payment has been made successfully!" << endl;
	}
	else if (total > 0) {
		cout << "sorry not full payment made!" << endl;
	}
}


int main() {
	driver_info d1;
	registered_car c1[3];
	fine f;
	char name[10];
	int number, identity, option, option2, plate_number, noc, total = 0;
	int amount = 0;
	string yes_no;
	cout << "Please choose identity:" << endl;
	cout << "1-Traffic man " << endl;
	cout << "2-driver" << endl;
	cin >> identity;
	if (identity == 1) {

	}
	else if (identity == 2) {
		cout << "what do you want to do?" << endl;
		cout << "1-check fines " << endl;
		cout << "2-Add new car info" << endl;
		cin >> option;
		if (option == 1) {
			cout << "1-fines in total" << endl;
			cout << "2-fines of certain car" << endl;
			cin >> option2;
			if (option2 == 1) {
				cout << "enter name:" << endl;
				cin >> name;
				cout << "enter number of cars owned:" << endl;
				cin >> noc;
				for (int i = 0; i < noc; i++) {
					cout << "enter plate number of " << i + 1 << " car" << endl;
					cin >> c1[i].plate_number;
					for (int j = 0; j < 20; j++)
					{
						if (c1[i].plate_number == main_saved_info.plate_numbers[j]) {
							c1[i].model = main_saved_info.model[j];
							c1[i].production_year = main_saved_info.production_year[j];
							c1[i].recorded_fines.date_of_fine.day = main_saved_info.saved_dates_of_fines[j].day;
							c1[i].recorded_fines.date_of_fine.month = main_saved_info.saved_dates_of_fines[j].month;
							c1[i].recorded_fines.date_of_fine.year = main_saved_info.saved_dates_of_fines[j].year;
							c1[i].recorded_fines.street_name = main_saved_info.street_name_of_incident[j];
							c1[i].recorded_fines.status = main_saved_info.status[j];
							for (int l = 0; l < 20; l++)
							{
								if (c1[i].recorded_fines.street_name == info.street_name[l]) {
									c1[i].recorded_fines.speed_limit = info.speed_street_limit[l];
								}
							}

							c1[i].recorded_fines.car_speed = main_saved_info.car_speed[j];

							c1[i].recorded_fines.value_of_violation = 2 * (c1[i].recorded_fines.car_speed - c1[i].recorded_fines.speed_limit);
							total = total + c1[i].recorded_fines.value_of_violation;
						}
					}
				}
				cout << "total fines is " << total << endl;
				display_info(noc, yes_no, c1);

				full_payment(amount, total, noc, c1);
				/*cin >> amount;
				total = total - amount;
				if (total == 0) {
					for (int i = 0;i < noc;i++) {
						for (int j = 0;j < 20;j++) {
							if (c1[i].plate_number == main_saved_info.plate_numbers[j]) {
								main_saved_info.status[j] = "paid";
								c1[i].recorded_fines.status = main_saved_info.status[j];
							}
						}
					}
					cout << "your payment has been made successfully!" << endl;



				}
				else if (total > 0) {
					cout << "sorry not full payment made!" << endl;
				}*/
			}

		}
		else if (option2 == 2) {
			cout << "please enter required information:" << endl;
			cout << "please enter plate number:" << endl;
			cin >> plate_number;
			for (int i = 0; i < 20; i++) {
				if (plate_number == main_saved_info.plate_numbers[i]) {
					cout << "your car model is " << main_saved_info.model[i] << endl;
					cout << "the date of incident is " << main_saved_info.saved_dates_of_fines[i].day << " " << main_saved_info.saved_dates_of_fines[i].month << " " << main_saved_info.saved_dates_of_fines[i].year << endl;
					cout << "your car speed was " << main_saved_info.car_speed[i] << endl;
					if (main_saved_info.street_name_of_incident[i] == info.street_name[i]) {
						cout << "the street name of incident is " << main_saved_info.street_name_of_incident[i] << endl;
						cout << " street speed limit is " << info.speed_street_limit[i] << endl;
					}
					cout << "status: " << main_saved_info.status[i] << endl;
				}
			}
		}
	}
	else if (option == 2) {

	}



	cout << "saba3ba33" << endl;
	system("pause");
}

