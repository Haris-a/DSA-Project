#include<iostream>
#include<sstream>
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include "STRUCT.h"
#include "CONTACTS.h"
using namespace std;
using namespace sf;

int main()
{
	//Window
	RenderWindow window(VideoMode(512, 512), "Contacts app", Style::Titlebar | Style::Close);

	//FPS
	//window.setFramerateLimit(30);

	//Texture and image loading
	Texture bg;
	Texture pl;
	Texture dl;
	Texture Ed;
	Texture Se;
	Texture De;
	Texture Li;
	Texture Sn;
	bg.loadFromFile("Textures/Contacts-icon.png");
	pl.loadFromFile("Textures/Plus.png");
	dl.loadFromFile("Textures/delete.png");
	Ed.loadFromFile("Textures/Edit.png");
	Se.loadFromFile("Textures/search.png");
	De.loadFromFile("Textures/Delete_all.png");
	Li.loadFromFile("Textures/Black.png");
	Sn.loadFromFile("Textures/Screen.jpg");

	//Texture for Instructions
	Texture I1;
	Texture I2;
	Texture I3;
	Texture I4;
	Texture I5;
	I1.loadFromFile("Textures/i1.png");
	I2.loadFromFile("Textures/i2.png");
	I3.loadFromFile("Textures/i3.png");
	I4.loadFromFile("Textures/i4.png");
	I5.loadFromFile("Textures/i5.png");

	//Sprite
	Sprite background;
	Sprite plus;
	Sprite Del;
	Sprite Edit;
	Sprite Search;
	Sprite Dell_All;
	Sprite Line;
	Sprite Screen;
	background.setTexture(bg);
	plus.setTexture(pl);
	plus.setScale(Vector2f(2.4f, 2.4f));
	plus.setPosition(325.0f, 265.0f);
	Del.setTexture(dl);
	Del.setScale(Vector2f(1.4f, 1.4f));
	Del.setPosition(355.0f, 185.0f);
	Edit.setTexture(Ed);
	Edit.setScale(Vector2f(1.4f, 1.4f));
	Edit.setPosition(355.0f, 95.0f);
	Search.setTexture(Se);
	Search.setScale(Vector2f(1.4f, 1.4f));
	Search.setPosition(355.0f, 5.0f);
	Dell_All.setTexture(De);
	Dell_All.setScale(Vector2f(1.4f, 1.4f));
	Dell_All.setPosition(355.0f, 400.0f);
	Line.setTexture(Li);
	Screen.setTexture(Sn);

	//Sprites for Instructions
	Sprite is1;
	Sprite is2;
	Sprite is3;
	Sprite is4;
	Sprite is5;
	is5.setTexture(I5);
	is5.setPosition(10.0f, 90.0f);
	is4.setTexture(I4);
	is4.setPosition(10.0f, 140.0f);
	is2.setTexture(I2);
	is2.setPosition(10.0f, 190.0f);
	is1.setTexture(I1);
	is1.setPosition(10.0f, 240.0f);
	is3.setTexture(I3);
	is3.setPosition(3.0f, 290.0f);

	//Text and Font
	Font ALBA;
	ALBA.loadFromFile("Textures/Rocko.ttf");
	Text Prompt;
	Text Phone;
	Text Name;
	Text PhoneN;
	Prompt.setFont(ALBA);
	Prompt.setCharacterSize(22);
	Prompt.setPosition(200.0f, 40.0f);
	Prompt.setFillColor(Color::Black);
	Phone.setFont(ALBA);
	Phone.setCharacterSize(22);
	Phone.setPosition(160.0f, 250.0f);
	Phone.setFillColor(Color::Black);
	Name.setFont(ALBA);
	Name.setCharacterSize(25);
	Name.setPosition(220.0f, 125.0f);
	Name.setFillColor(Color::Black);
	PhoneN.setFont(ALBA);
	PhoneN.setCharacterSize(22);
	PhoneN.setPosition(220.0f, 370.0f);
	PhoneN.setFillColor(Color::Black);

    //Pointer textures, sprites and text
	Texture* Enter_N;
	Enter_N = new Texture;
	Sprite* Enter_Nfield;
	Enter_Nfield = new Sprite;
	Enter_Nfield->setOrigin(140.f, 35.f);
	Enter_Nfield->setPosition(256.0f, 127.0f);
	Enter_Nfield->setScale(1.2f, 1.2f);
	Texture* Enter_PN;
	Enter_PN = new Texture;
	Sprite* Enter_PNfield;
	Enter_PNfield = new Sprite;
	Enter_PNfield->setOrigin(140.f, 35.f);
	Enter_PNfield->setPosition(256.0f, 372.0f);
	Enter_PNfield->setScale(1.2f, 1.2f);

	//Co-ordinates of window
	int window_x = window.getSize().x;
	int window_y = window.getSize().y;

    //bool
	bool m1 = true;
	bool m2 = false;
	bool m3 = false;
	bool m4 = true;
	bool m5 = true;
	bool m6 = false;
	bool m7 = true;
	bool m8 = false;
	bool m9 = true;
	bool m10 = false;
	bool m11 = true;
	bool m12 = false;
	bool x;
	bool y;
	bool z = true;
	bool w;
	unsigned int p;
	unsigned int a;
	string b;
	string n;
	char c;
	unsigned int get_num;
	string get_name;

	//Fresh window #lemon chiffon (RGB)
	window.clear(Color::Color(255, 250, 205, 255));
	window.draw(Screen);

	//Draw background
	window.draw(background);
	window.display();

	//Class
	Contacts C;

	//main loop
	while (window.isOpen())
	{
		int mp_x = Mouse::getPosition(window).x;
		int mp_y = Mouse::getPosition(window).y;

		Event ev;

		//Event polling
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
			{
				window.close();
			}
		}

		//Instructions
		if (Mouse::isButtonPressed(Mouse::Left) && m1==true)
		{
			window.clear(Color::Color(255, 250, 205, 255));
			window.draw(Screen);
			Name.setString("Instructions");
			Name.setCharacterSize(30);
			Name.setPosition(180.0f, 10.0f);
			window.draw(Name);
			window.draw(is5);
			Name.setString("Click this icon, and then press ' S ' to search a Contact ");
			Name.setCharacterSize(18);
			Name.setPosition(40.0f, 95.0f);
			window.draw(Name);
			window.draw(is4);
			Name.setString("Click this icon, and then press ' E ' to update a Contact ");
			Name.setCharacterSize(18);
			Name.setPosition(40.0f, 145.0f);
			window.draw(Name);
			window.draw(is2);
			Name.setString("Click this icon, and then press ' D ' to delete a Contact ");
			Name.setCharacterSize(18);
			Name.setPosition(40.0f, 195.0f);
			window.draw(Name);
			window.draw(is1);
			Name.setString("Click this icon, and then press ' A ' to add new Contact ");
			Name.setCharacterSize(18);
			Name.setPosition(40.0f, 245.0f);
			window.draw(Name);
			window.draw(is3);
			Name.setString("Click this icon, and then press ' X ' to delete all Contacts ");
			Name.setCharacterSize(18);
			Name.setPosition(28.0f, 295.0f);
			window.draw(Name);
			Name.setString("To Quit Contacts app, press quit button on top right corner ");
			Name.setCharacterSize(18);
			Name.setPosition(3.0f, 345.0f);
			window.draw(Name);
			Name.setString("Press Escape");
			Name.setCharacterSize(30);
			Name.setPosition(170.0f, 425.0f);
			window.draw(Name);
			window.display();
			m1 = false;
			m2 = true;
		}

		// Mouse detects add icon
		if(Mouse::isButtonPressed(Mouse::Left)&& mp_x>=354 && mp_x<=448 && mp_y>=295 && mp_y<=381 && m2==true)
		{
			window.clear(Color::Color(255, 250, 205, 255));
			window.draw(Screen);
			window.display();
			m3 = true;
		}

		// Mouse detects delete icon
		if (Mouse::isButtonPressed(Mouse::Left)&& mp_x>=366 && mp_x<=433 && mp_y>=187 && mp_y<=271 && m5==true)
		{
			window.clear(Color::Color(255, 250, 205, 255));
			window.draw(Screen);
			window.display();
			m6 = true;
		}

		// Mouse detects edit icon
		if (Mouse::isButtonPressed(Mouse::Left)&& mp_x>=365 && mp_x<=431 && mp_y>=107 && mp_y<=170 && m7==true)
		{
			window.clear(Color::Color(255, 250, 205, 255));
			window.draw(Screen);
			window.display();
			m8 = true;
		}

		// Mouse detects search icon
		if (Mouse::isButtonPressed(Mouse::Left)&& mp_x>=354 && mp_x<=443 && mp_y>=4 && mp_y<=88 && m9==true)
		{
			window.clear(Color::Color(255, 250, 205, 255));
			window.draw(Screen);
			window.display();
			m10 = true;
		}

		// Mouse detects delete all icon
		if (Mouse::isButtonPressed(Mouse::Left)&& mp_x>=355 && mp_x<=445 && mp_y>=402 && mp_y<=487 && m11==true)
		{
			window.clear(Color::Color(255, 250, 205, 255));
			window.draw(Screen);
			window.display();
			m12 = true;
		}

		//This part of program deals with adding new contacts.
		if (m3 == true)
		{
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				Enter_N->loadFromFile("Textures/AddContact.png");
				Enter_Nfield->setTexture(*Enter_N);
				Prompt.setString("Enter Name");
				Enter_PN->loadFromFile("Textures/AddContact.png");
				Enter_PNfield->setTexture(*Enter_PN);
				Phone.setString("Enter Phone number");
				cout << "Name" << endl;
				cin >> b;
				cout << "Phone number" << endl;
				cin >> a;
				x=C.check_existing_contact(b, a);
				if (x==true)
				{
					window.clear(Color::Color(255, 250, 205, 255));
					window.draw(Screen);
					Name.setString("Contact already exist's!, Try again...");
					Name.setPosition(20.0f, 200.0f);
					window.draw(Name);
					window.display();
					x = false;
				}
				else
				{
					C.add_contact(b, a);
					Name.setString(b);
					Name.setPosition(110.0f, 115.0f);
					stringstream ss;
					ss << a;
					string s;
					ss >> s;
					PhoneN.setString(s);
					window.clear(Color::Color(255, 250, 205, 255));
					window.draw(Screen);
					window.draw(Prompt);
					window.draw(*Enter_Nfield);
					window.draw(Name);
					Phone.setPosition(160.0f, 250.0f);
					PhoneN.setPosition(110.0f, 360.0f);
					window.draw(Phone);
					window.draw(*Enter_PNfield);
					window.draw(PhoneN);
					window.display();
				}
				m3 = false;
			}
		}

		//This part of program deals with displaying all contacts.
		if (Keyboard::isKeyPressed(Keyboard::Escape) && m4==true)
		{
			float c = 0.0;
			float d = 0.0;
			window.clear(Color::Color(255, 250, 205, 255));
			window.draw(Screen);
			node* nodeptr = C.head;
			while (nodeptr)
			{
				Name.setString(nodeptr->name);
				Name.setPosition(10.0f, 10.0f + c);
				window.draw(Name);
				Line.setPosition(0.0f, 45.0f + d);
				window.draw(Line);
				c = c + 45.0f;
				d = d + 45.0f;
				nodeptr = nodeptr->next;
			}
			window.draw(Search);
			window.draw(Edit);
			window.draw(Del);
			window.draw(plus);
			window.draw(Dell_All);
			window.display();
		}

		//This part of program deals with deleting selective contacts.
		if (m6 == true)
		{
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				Enter_PN->loadFromFile("Textures/AddContact.png");
				Enter_PNfield->setTexture(*Enter_PN);
				Phone.setString("Enter Phone number");
				cout << "Phone number" << endl;
				cin >> a;
				C.delete_contact(a);
				stringstream ss;
				ss << a;
				string s;
				ss >> s;
				PhoneN.setString(s);
				window.clear(Color::Color(255, 250, 205, 255));
				window.draw(Screen);
				Phone.setPosition(155.0f, 40.0f);
				PhoneN.setPosition(110.0f, 115.0f);
				Name.setString("Contact deleted successfully!");
				Name.setPosition(50.0f, 300.0f);
				window.draw(Name);
				window.draw(Phone);
				window.draw(*Enter_Nfield);
				window.draw(PhoneN);
				window.display();
				m6 = false;
			}
		}

		//This part of program deals with updating existing contact
		if (m8 == true)
		{
			if (Keyboard::isKeyPressed(Keyboard::E))
			{
				Enter_N->loadFromFile("Textures/AddContact.png");
				Enter_Nfield->setTexture(*Enter_N);
				Prompt.setString("Enter Name");
				Enter_PN->loadFromFile("Textures/AddContact.png");
				Enter_PNfield->setTexture(*Enter_PN);
				Phone.setString("Enter Phone number");
				cout << "Update" << endl;
				cin >> b;
				node* nodeptr = C.head;
				while (nodeptr)
				{
					if (nodeptr->name == b && z == true)
					{
						cout << "New Name" << endl;
						cin >> n;
						cout << "New Phone number" << endl;
						cin >> p;
						w = C.check_existing_contact(n, p);
						if (w == true)
						{
							window.clear(Color::Color(255, 250, 205, 255));
							window.draw(Screen);
							Name.setString("Contact already exist's!, Try again...");
							Name.setPosition(20.0f, 200.0f);
							window.draw(Name);
							window.display();
							w = false;
						}
						else
						{
							nodeptr->name = n;
							nodeptr->phone_no = p;
							Name.setString(nodeptr->name);
							Name.setPosition(110.0f, 115.0f);
							stringstream ss;
							ss << nodeptr->phone_no;
							string s;
							ss >> s;
							PhoneN.setString(s);
							window.clear(Color::Color(255, 250, 205, 255));
							window.draw(Screen);
							window.draw(Prompt);
							window.draw(*Enter_Nfield);
							window.draw(Name);
							Phone.setPosition(160.0f, 250.0f);
							PhoneN.setPosition(110.0f, 360.0f);
							window.draw(Phone);
							window.draw(*Enter_PNfield);
							window.draw(PhoneN);
							window.display();
							z = false;
						}
					}
					else
					{
						nodeptr = nodeptr->next;
					}
				}
				if (z == true)
				{
					window.clear(Color::Color(255, 250, 205, 255));
					window.draw(Screen);
					Name.setString("No Contact Found! , Try again...");
					Name.setCharacterSize(30);
					Name.setPosition(55.0f, 200.0f);
					window.draw(Name);
					window.display();
				}
				m8 = false;
			}
		}

		//This part of program deals with searching contacts.
		if (m10 == true)
		{
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				Enter_N->loadFromFile("Textures/AddContact.png");
				Enter_Nfield->setTexture(*Enter_N);
				Prompt.setString("Search");
				cout << "Search by (a) Name or (b) Phone number:" << endl;
				cin >> c;
				if (c == 'a')
				{
					cout << "Name" << endl;
					cin >> b;
					y = C.search_contact_by_name(b);
					if (y==true)
					{
						Name.setString(b);
						Prompt.setPosition(200.0f, 40.0f);
						Prompt.setCharacterSize(30);
						Name.setPosition(110.0f, 115.0f);
						window.clear(Color::Color(255, 250, 205, 255));
						window.draw(Screen);
						window.draw(Prompt);
						window.draw(*Enter_Nfield);
						window.draw(Name);
						Name.setString("Contact Found!");
						Name.setCharacterSize(30);
						Name.setPosition(150.0f, 200.0f);
						window.draw(Name);
						Name.setString("Name");
						Name.setCharacterSize(30);
						Name.setPosition(50.0f, 300.0f);
						window.draw(Name);
						Name.setString(b);
						Name.setCharacterSize(30);
						Name.setPosition(325.0f, 300.0f);
						window.draw(Name);
						Name.setString("Phone number");
						Name.setCharacterSize(30);
						Name.setPosition(50.0f, 375.0f);
						window.draw(Name);
						get_num = C.send_phone_no();
						stringstream ss;
						ss << get_num;
						string s;
						ss >> s;
						PhoneN.setString(s);
						PhoneN.setCharacterSize(30);
						PhoneN.setPosition(325.0f, 375.0f);
						window.draw(PhoneN);
						window.display();
					}
					else
					{
						window.clear(Color::Color(255, 250, 205, 255));
						window.draw(Screen);
						Name.setString("No Contact Found! , Try again...");
						Name.setCharacterSize(30);
						Name.setPosition(55.0f, 200.0f);
						window.draw(Name);
						window.display();
					}
				}
				else if (c == 'b')
				{
					cout << "Phone number" << endl;
					cin >> a;
					y = C.search_contact_by_phone_number(a);
					if (y == true)
					{
						stringstream ss;
						ss << a;
						string s;
						ss >> s;
						PhoneN.setString(s);
						Prompt.setPosition(200.0f, 40.0f);
						Prompt.setCharacterSize(30);
						PhoneN.setPosition(110.0f, 115.0f);
						window.clear(Color::Color(255, 250, 205, 255));
						window.draw(Screen);
						window.draw(Prompt);
						window.draw(*Enter_Nfield);
						window.draw(PhoneN);
						Name.setString("Contact Found!");
						Name.setCharacterSize(30);
						Name.setPosition(150.0f, 200.0f);
						window.draw(Name);
						Name.setString("Name");
						Name.setCharacterSize(30);
						Name.setPosition(50.0f, 300.0f);
						window.draw(Name);
						get_name = C.send_name();
						Name.setString(get_name);
						Name.setCharacterSize(30);
						Name.setPosition(325.0f, 300.0f);
						window.draw(Name);
						Name.setString("Phone number");
						Name.setCharacterSize(30);
						Name.setPosition(50.0f, 375.0f);
						window.draw(Name);
						PhoneN.setString(s);
						PhoneN.setCharacterSize(30);
						PhoneN.setPosition(325.0f, 375.0f);
						window.draw(PhoneN);
						window.display();
					}
					else
					{
						window.clear(Color::Color(255, 250, 205, 255));
						window.draw(Screen);
						Name.setString("No Contact Found! , Try again...");
						Name.setCharacterSize(30);
						Name.setPosition(55.0f, 200.0f);
						window.draw(Name);
						window.display();
					}
				}
				m10 = false;
			}
		}

		//This part of program deals with deleting all contacts.
		if (m12 == true)
		{
			if (Keyboard::isKeyPressed(Keyboard::X))
			{
				C.delete_all_contacts();
				window.clear(Color::Color(255, 250, 205, 255));
				window.draw(Screen);
				Name.setString("All contacts deleted successfully!");
				Name.setCharacterSize(30);
				Name.setPosition(15.0f, 200.0f);
				window.draw(Name);
				window.display();
				m12 = false;
			}
		}
	}
	
	//End of program
	return 0;
}