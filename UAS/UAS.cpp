#include <iostream>
#include <string>
using namespace std;
class Node {
public:
	//isi disini
	string namaproduk;
	string tipeproduk;
	int jumlahproduk;
	Node* next;
};
class ManajemenProduk {
private:
	Node* head;
public:
	ManajemenProduk() {
		head = NULL;
	}
	void tambahProduk() {
		string nama;
		int jumlah;
		string tipe;
		cout << "========== TAMBAH PRODUK ==========" << endl;
		cout << "Nama Produk : ";
		getline(cin, nama);
		cout << "Jumlah Produk : ";
		cin >> jumlah;cin.ignore(); // Membersihkan buffer input
		cout << "Tipe Produk : ";
		getline(cin, tipe);
		//isi disini

		Node* newnode = new Node();
		newnode->namaproduk = nama;
		newnode->jumlahproduk = jumlah;
		newnode->tipeproduk = tipe;
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
		}
		else {
			Node* current = head;
			while (current->next != NULL) {
				current = current->next;
			}
			current->next = newnode;
		}

		cout << "Produk berhasil ditambahkan!" << endl;
	}
	void tampilkanSemuaProduk() {
		cout << "========== SEMUA DATA PRODUK ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			Node* current = head;
			//isi disini
			while (current != NULL) {
				cout << "Nama Produk: " << current->namaproduk << endl;
				cout << "Jumlah Produk: " << current->jumlahproduk << endl;
				cout << "Tipe Produk: " << current->tipeproduk << endl;
				cout << endl;
				current = current->next;
			}
		}
	}
	void cariProdukByNama() {
		cout << "========== CARI PRODUK BERDASARKAN NAMA ==========" << endl;
		if (head == NULL) {
			cout << "Belum ada data produk yang tersimpan." << endl;
		}
		else {
			string targetNama;
			cout << "Nama Produk yang dicari: ";
			getline(cin, targetNama);
			Node* current = head;
			int posisi = 0;
			
			while (current != NULL) {
				posisi++;
				if (current->namaproduk == targetNama) {
					cout << "Data produk ditemukan pada posisi: " << posisi << endl;
					cout << "Nama Produk: " << current->namaproduk << endl;
					cout << "Jumlah Produk: " << current->jumlahproduk << endl;
					cout << "Tipe Produk: " << current->tipeproduk << endl;
					
					break;
				}
				current = current->next;
			}
			if (current = NULL) {
				cout << "Nama produk " << targetNama << " TIDAK DITEMUKAN" << endl;
			}
		}
	}
	void algorithmaSortByJumlahProduk() {
		if (head == NULL || head->next == NULL) {
			return; // Tidak perlu sorting jika hanya terdapat 0 atau 1 node
		}
		Node* current;
		Node* last = NULL;
		current = head;//isi disini
		while (current->next != last) {
			if (current->jumlahproduk > current->next->jumlahproduk) {
				// Tukar posisi
				string tempNama = current->namaproduk;
				int tempJumlah = current->jumlahproduk;
				string tempTipe = current->tipeproduk;

				current->namaproduk = current->next->namaproduk;
				current->jumlahproduk = current->next->jumlahproduk;
				current->tipeproduk = current->next->tipeproduk;

				current->next->namaproduk = tempNama;
				current->next->jumlahproduk = tempJumlah;
				current->next->tipeproduk = tempTipe;

			}
			current = current->next;
		}
		last = current;
	}
};
int main() {
	ManajemenProduk manajemenProduk;
	int pilihan;
	do {
		cout << "========== APLIKASI MANAJEMEN DATA PRODUK ==========" << endl;
		cout << "1. Tambah Produk" << endl;
		cout << "2. Tampilkan Semua Produk" << endl;
		cout << "3. Cari Produk berdasarkan Nama" << endl;
		cout << "4. Urutkan Produk berdasarkan Jumlah" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			manajemenProduk.tambahProduk();
			break;
		case 2:
			manajemenProduk.tampilkanSemuaProduk();
			break;
		case 3:
			manajemenProduk.cariProdukByNama();
			break;
		case 4:
			manajemenProduk.algorithmaSortByJumlahProduk();
			manajemenProduk.tampilkanSemuaProduk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}

// 2. Single Linked List, Bubble Sort, linier search
// 3. Dengan cara menggunakan queue dengan bentuk circular array. Yaitu jika rear sudah berada di posisi terakhir dari list dan di posisi awal kosong maka set REAR menjadi 0 dan masukkan lagi data dari awal
// 4. Ketika membuat sebuah program aplikasi yang mengaplikasikan data struktur LIFO (Last In First Out), seperti contohnya : program undo, dll
// 5. a. 5
//    b. Inorder Traversal