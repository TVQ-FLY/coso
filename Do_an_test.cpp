#include <iostream>
#include <conio.h>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string>
#include <iomanip>

using namespace std;

void menu()
{

   cout << "\n\n\n===== CHUONG TRINH QUAN LY THU VIEN =====\n";
   cout << "**** TRAN VAN QUYEN ****";
   cout << "\n\n Nhap lua chon cua ban: \n";
   cout << " 1. Dang ki ban doc \n";
   cout << " 2. Nhap sach \n";
   cout << " 3. Sua thong tin sach \n";
   cout << " 4. Xoa sach \n";
   cout << " 5. In danh sach ban doc\n";
   cout << " 6. In danh sach sach\n";
   cout << " 7. Thoat khoi chuong trinh !!!\n";
   cout << "Moi nhap: ";
}

class sach;
class dausach;
class phieumuon;

class bandoc
{
   friend class phieumuon;

private:
   char *ten;
   char *ma;
   phieumuon *sachmuon[5];
   int somuon;
   static int sobandoc;
   static bandoc *cacbandoc[100];

public:
   bandoc(char *m, char *t)
   {
      ma = new char[strlen(m) + 1];
      ten = new char[strlen(t) + 1];
      strcpy(ma, m);
      strcpy(ten, t);
      somuon = 0;
   }
   ~bandoc()
   {
      delete[] ma;
      delete[] ten;
   }
   static void dangki();
   static bandoc *timbd(char *);
   phieumuon *muon(char *);
   void tra(dausach *);
   static void xoadl();
   void muon(dausach *dausach);
   static void inds();
};



int bandoc::sobandoc = 0;

bandoc *bandoc::cacbandoc[100];

void bandoc::dangki()
{
   char ma[80];

   ofstream outfile;
   outfile.open("bandoc.txt", ios::app);
   cout << "\nMa ban doc : ";
   cin.getline(ma, 80);
   outfile << ma;
   char ten[80];
   cout << "\nTen ban doc : ";
   cin.getline(ten, 80);
   outfile << ", ";
   outfile << ten;
   outfile << "\n";
   cacbandoc[sobandoc++] = new bandoc(ma, ten);
   cout << " Ban doc "
        << "' " << ten << " '"
        << " da duoc dang ki \n ";
   outfile.close();
}


void bandoc::inds()
{

   for (int i = 0; i <= sobandoc; i++)
   {
      ifstream infile;
      infile.open("bandoc.txt");
      cout << "\n";
      string a;
      getline(infile, a, ',');
      string b;
      infile >> b;
      cout << "\nDanh sach ban doc la: ";
      cout << "\n"
           << a << "\t" << b;

      for (int i = 0; i <= 100; i++)
      {
         string a;
         getline(infile, a, ',');
         string b;
         infile >> b;
         cout << a << "\t" << b;
      }
      infile.close();
   }
}

class book
{

   int book_no;
   char name[30];
   char nxb[50];

public:
   void main_menu();
   void add();
   void display();
   void showbook();
   void edit();
   int check(int);
   void modify(int);
   void delete_rec(int);
   void bill(int);
};


void book::add()
{

   system("cls");
   int r, flag;
   ofstream fout("Record.txt", ios::app);

   cout << "\n\t\t\t\t  Nhap Thong Tin Sach";
   cout << "\n\t\t\t\t      * Menu Them Sach *";
   cout << "\n ----------------------";

   cout << "\n Nhap ID sach :- " << endl;
   cin >> r;

   flag = check(r);

   if (flag)
      cout << "\n Trung roi";

   else
   {

      book_no = r;
      cout << " Ten sach: ";
      cin >> name;
      cout << " NhaXB: ";
      cin >> nxb;

      fout.write((char *)this, sizeof(book));
      cout << "\n Da them sach...!!!";
   }

   cout << "\n Press any key to continue.....!!";

   getch();
   fout.close();
}

void book::display()
{

   system("cls");

   ifstream fin("Record.txt", ios::in);
   int r, flag;

   cout << "\n Nhap ID sach :- " << endl;
   cin >> r;

   while (true)
   {

      fin.read((char *)this, sizeof(book));
      if (fin.eof() || fin.fail())
      {
         break;
      }
      if (book_no == r)
      {

         system("cls");
         cout << "\n Thong tin sach:";
         cout << "\n ----------------";
         cout << "\n\n ID sach: " << book_no;
         cout << "\n Ten sach: " << name;
         cout << "\n NXB: " << nxb;
         flag = 1;
         break;
      }
   }

   if (flag == 0)
      cout << "\n ID sach khong ton tai....!!";
   cout << "\n\n Press any key to continue....!!";

   getch();
   fin.close();
}

void book::showbook()
{

   system("cls");

   ifstream fin("Record.txt", ios::in);
   cout << "\n\t\t\t    LIST BOOK!!!!";
   cout << "\n\t\t\t    ----------------------";
   cout << "\n\n ID Sach\tTen sach\tNXB\n";

   while (true)
   {

      fin.read((char *)this, sizeof(book));
      if (fin.eof() || fin.fail())
      {
         break;
      }
      cout << "\n\n " << book_no << "\t\t" << name;
      cout << "\t\t" << nxb;
   }

   cout << "\n\n\n\t\t\tPress any key to continue.....!!";
   getch();
   fin.close();
}

// void book::edit()
// {

//    system("cls");

//    int choice, r;
//    cout << "\n Menu Doi, Tra Phong";
//    cout << "\n ---------";
//    cout << "\n\n 1.Edit";
//    cout << "\n 2.Delete";
//    cout << "\n Nhap Hanh Dong Cua Ban: ";

//    cin >> choice;
//    system("cls");

//    cout << "\n Nhap ID sach: ";
//    cin >> r;

//    switch (choice)
//    {

//    case 1:
//       modify(r);
//       break;

//    case 2:
//       delete_rec(r);
//       break;

//       break;

//    default:
//       cout << "\n Wrong Choice.....!!";
//    }
//    cout << "\n Press any key to continue....!!!";

//    getch();
// }

int book::check(int r)
{

   int flag = 0;

   ifstream fin("Record.txt", ios::in);

   while (true)
   {

      fin.read((char *)this, sizeof(book));
      if (fin.eof() || fin.fail())
      {
         break;
      }
      if (book_no == r)
      {

         flag = 1;
         break;
      }
   }

   fin.close();
   return (flag);
}

void book::modify(int r)
{

   long pos, flag = 0;

   fstream file("Record.txt", ios::in | ios::out | ios::binary);

   while (true)
   {
      pos = file.tellg();

      file.read((char *)this, sizeof(book));
      if (file.eof() || file.fail())
      {
         break;
      }

      if (book_no == r)
      {

         cout << "\n Nhap Thong Tin Moi";
         cout << "\n -----------------";
         cout << "\n Ten sach: ";
         cin >> name;

         cout << " NXB: ";
         cin >> nxb;
         file.seekg(pos);
         file.write((char *)this, sizeof(book));
         cout << "\n Thong Tin Da Duoc Sua Doi....!!";
         flag = 1;
         break;
      }
   }

   if (flag == 0)
      cout << "\n Khong ton tai ID !!";
   file.close();
}

void book::delete_rec(int r)
{

   int flag = 0;
   char ch;
   ifstream fin("data.txt", ios::in);
   ofstream fout("temp.txt", ios::out);

   while (true)
   {

      fin.read((char *)this, sizeof(book));
      if (fin.eof() || fin.fail())
      {
         break;
      }

      if (book_no == r)

      {

         cout << "\n Ten sach: " << name;
         cout << "\n NXB: " << nxb;
         cout << "\n\n Ban Co Muon Xoa Thong Tin Khong?(y/n): ";
         cin >> ch;

         if (ch == 'n')
            fout.write((char *)this, sizeof(book));
         flag = 1;
      }

      else
         fout.write((char *)this, sizeof(book));
   }

   fin.close();
   fout.close();

   if (flag == 0)
      cout << "\n Khong ton tai ID !!";

   else
   {

      remove("data.txt");
      rename("temp.txt", "data.txt");
   }
}


int main()
{

   book h;
   while (1)
   {
      menu();
      int i = _getch();
      switch (i)
      {
      case '1':
      {
         bandoc::dangki();
         break;
      }
      case '2':
      {
         h.add();
         break;
      }
      case '3':
      {
         system("cls");
         int r;
         cout << "\n Nhap ID sach: ";
         cin >> r;
         h.modify(r);
         break;
      }
      case '4':
      {
         system("cls");
         int r;
         cout << "\n Nhap ID sach: ";
         cin >> r;
         h.delete_rec(r);
         break;
      }
      case '5':
      {
         bandoc::inds();

         break;
      }
      case '6':
         h.showbook();
      }

      if (i == '7')
         break;
         _getch(); 
   }
   return 0;
}
