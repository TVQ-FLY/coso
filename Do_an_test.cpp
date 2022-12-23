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

void dangnhap();
void dangky();
void quenmk();


// Dang nhap, dang ky, quen mat khau
void dangky()
{
   int t = 0;
   string usr, pas, u, p;
   system("cls");
   cout << "Nhap Username:";
   cin >> usr;
   ofstream write("username.txt", ios::app); // username file created which of append type
   ifstream read("username.txt");
   while (read >> u >> p)
   {
      if (u == usr)
      {
         t = 1;
         break;
      }
   }
   if (t == 1)
   {
      cout << "Username da duoc dang ky =((" << endl;
   }
   else
   {
      cout << "Nhap password:";
      cin >> pas;
      write << usr << " " << pas << endl;
      cout << "Dang ky thanh cong" << endl;
   }
   write.close();
}
void dangnhap()
{
   int t = 0;
   string usr, pas, u, p;
   cout << "\n\n\n===== DO AN CO SO =====\n\n";
   cout << "*** LOGIN ***\n";
   cout << "Nhap Username: ";
   cin >> usr;
   cout << "Nhap Password: ";
   cin >> pas;
   ifstream read("username.txt");
   while (read >> u >> p)
   {
      if (u == usr && p == pas)
      {
         t = 1;
         break;
      }
   }
   read.close();
   if (t == 1)
   {
      cout << "Dang nhap thanh cong !!!" << endl;
   }
   else
   {
      cout << " " << endl;
   }
}

void quenmk()
{
   int ch;
   system("cls");
   cout << "1.Tim tai khoan bang Username\n2.Tim tai khoan bang Password\n3.Quay lai Menu\n4.Nhap lua chon cua ban:";
   cin >> ch;
   switch (ch)
   {
      case 1:
      {
         int t = 0;
         string su, u, p;
         cout << "Nhap Username cua ban:";
         cin >> su;
         ifstream read("username.txt");
         while (read >> u >> p)
         {
            if (su == u)
            {
               t = 1;
               break;
            }
         }
         read.close();
         if (t == 1)
         {
            cout << "Thanh cong ! Da tim thay tai khoan \nPassword la: " << p << endl;
         }
         else
         {
            cout << "Khong tim thay tai khoan =((" << endl;
         }
         break;
      }
      case 2:
      {
         int t = 0;
         string sp, u, p;
         cout << "Nhap vao Password cua ban:";
         cin >> sp;
         ifstream read("username.txt");
         while (read >> u >> p)
         {
            if (sp == p)
            {
               t = 1;
               break;
            }
         }
         read.close();
         if (t == 1)
         {
            cout << "Thanh cong ! Da tim thay tai khoan \nUsername la: " << u << endl;
         }
         else
         {
            cout << "Khong tim thay tai khoan =((" << endl;
         }
         break;
      }
      case 3:
      {
         cout << endl;

         break;
      }
      default:
      {
         cout << "Lua chon sai, nham Enter de thu lai =((" << endl;
         quenmk();
      }
   }
}

//===================

void menu()
{

   cout << "\n\n\n===== CHUONG TRINH QUAN LY THU VIEN =====\n";
   cout << "\t**** TRAN VAN QUYEN ****";
   cout << "\n\n Nhap lua chon cua ban: \n";
   cout << " 0. Lay lai mat khau Admin\n";
   cout << " 1. Dang ky tai khoan Admin\n";
   cout << " 2. Them danh ban doc \n";
   cout << " 3. Nhap sach \n";
   cout << " 4. Sua thong tin sach \n";
   cout << " 5. Xoa sach \n";
   cout << " 6. In danh sach ban doc\n";
   cout << " 7. In danh sach sach\n";
   cout << " 8. In danh sach tai khoan Admin\n";
   cout << " 9. Thoat khoi chuong trinh !!!\n";

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

   int idsach;
   char name[30];
   char tacgia[50];

public:
   void main_menu();
   void add();
   void display();
   void showbook();
   void edit();
   int check(int);
   void modify(int);
   void delete_rec(int);
   static void listAdmin();
};

void book::add()
{

   system("cls");
   int r, flag;
   ofstream fout("Data.txt", ios::app);

   cout << "\n\n\n=====   CHUC NANG THEM SACH  =====\n";
   cout << "\nMoi ban nhap: ";
   cout << "\n ID sach : ";
   cin >> r;
   flag = check(r);
   if (flag)
      cout << "\n XIN LOI ! SACH NAY DA DUOC THEM =((";

   else
   {

      cin.sync();
      idsach = r;
      cout << " Ten sach: ";
      cin >> name;
      cout << " Ten tac gia: ";
      cin >> tacgia;

      fout.write((char *)this, sizeof(book));
      cout << "\n SACH DA DUOC THEM VAO HE THONG !!!";
   }

   cout << "\n Nhan ENTER de tiep tuc !";

   getch();
   fout.close();
}

void book::showbook()
{

   system("cls");

   ifstream fin("Data.txt", ios::in);
   cout << "\n\n\n===== TAT CA SACH TRONG HE THONG =====\n";
   cout << "\n\n ID \t\tTen sach\tTen tac gia\n";

   while (true)
   {

      fin.read((char *)this, sizeof(book));
      if (fin.eof() || fin.fail())
      {
         break;
      }
      cout << "\n\n " << idsach << "\t\t" << name;
      cout << "\t\t" << tacgia;
   }

   cout << "\n\n\n\t\t\tNhan ENTER de tiep tuc !";
   getch();
   fin.close();
}

int book::check(int r)
{

   int flag = 0;

   ifstream fin("Data.txt", ios::in);

   while (true)
   {

      fin.read((char *)this, sizeof(book));
      if (fin.eof() || fin.fail())
      {
         break;
      }
      if (idsach == r)
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

   fstream file("Data.txt", ios::in | ios::out | ios::binary);

   while (true)
   {
      pos = file.tellg();

      file.read((char *)this, sizeof(book));
      if (file.eof() || file.fail())
      {
         break;
      }

      if (idsach == r)
      {

         cout << "\n Nhap thong tin ban muon update: ";
         cout << "\n Ten sach: ";
         cin >> name;
         cout << "Tac gia: ";
         cin >> tacgia;
         file.seekg(pos);
         file.write((char *)this, sizeof(book));
         cout << "\n UPDATE THANH CONG !!!";
         flag = 1;
         break;
      }
   }

   if (flag == 0)
      cout << "\nXIN LOI, ID NAY KHONG TON TAI !!!";
   file.close();
}

void book::delete_rec(int r)
{

   int flag = 0;
   char ch;
   ifstream fin("Data.txt", ios::in);
   ofstream fout("temp.txt", ios::out);

   while (true)
   {

      fin.read((char *)this, sizeof(book));
      if (fin.eof() || fin.fail())
      {
         break;
      }

      if (idsach == r)
      {

         cout << "\n Ten sach: " << name;
         cout << "\n NXB: " << tacgia;
         cout << "\n\n Ban Co Muon Xoa Thong Tin Khong?(y/n): ";
         cin >> ch;

         if (ch == 'n')
            fout.write((char *)this, sizeof(book));
         flag = 1;
      }
      else
      {
         fout.write((char *)this, sizeof(book));
      }
   }

   fin.close();
   fout.close();

   if (flag == 0)
      cout << "\n Khong ton tai ID !!";

   else
   {

      remove("Data.txt");
      rename("temp.txt", "Data.txt");
      cout << "Xoa thanh cong !!!";
   }
}

void listAdmin(){
   system("cls");

   
      ifstream infile;
      infile.open("username.txt");
      cout << "\n";
      string a;
      getline(infile, a, ',');
      string b;
      getline(infile, b, ',');
      cout << "\nDanh sach tai khoan Admin: \n";
      cout << a << "\t"<< b;

      for (int i = 0; i <= 5; i++)
      {
         string a;
         getline(infile, a, ',');
         string b;
         getline(infile, b, ',');

         cout << a << "\t" << b;
      }

      infile.close();
}



int main()
{
   dangnhap();
   book quyen;
   while (1)
   {
      menu();
      int i = _getch();
      switch (i)
      {
         case '0':
         {
            quenmk();
            break;
         }
         case '1':
         {
            dangky();
            break;
         }
         case '2':
         {
            bandoc::dangki();
            break;
         }
         case '3':
         {
            quyen.add();
            break;
         }
         case '4':
         {
            system("cls");
            int r;
            cout << "\n Nhap ID sach: ";
            cin >> r;
            quyen.modify(r);
            break;
         }
         case '5':
         {
            system("cls");
            int r;
            cout << "\n Nhap ID sach: ";
            cin >> r;
            quyen.delete_rec(r);
            break;
         }
         case '6':
         {
            bandoc::inds();
            break;
         }
         case '7':
         {
            quyen.showbook();
            break;
         }
         case '8':
         {
            listAdmin();
            break;
         }
      }
      if (i == '9')
         break;
      _getch();
   }
   return 0;
}
