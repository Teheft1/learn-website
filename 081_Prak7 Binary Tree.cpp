#include <iostream>

using namespace std;

typedef struct binary
{
    int data;
    struct binary *kiri;
    struct binary *kanan;
};

struct binary *root = NULL;

int main();

int datamasuk(binary **root,int datain){
    if((*root) == NULL){
        binary *baru;
        baru = new struct binary;
        baru->data =datain;
        baru->kanan =NULL;
        baru->kiri=NULL;
        (*root)=baru;
        (*root)->kanan=NULL;
        (*root)->kiri=NULL;
    }else if(datain < (*root)->data){
        datamasuk(&(*root)->kiri,datain);
    }else if(datain > (*root)->data){
        datamasuk(&(*root)->kanan,datain);
    }else if(datain==(*root)->data){
        cout<<"data sudah ada"<<endl;
    }
    main();
}

int caridata(binary *root,int cari){
    if(root == NULL){
        cout<<"binary tree kosong";
    }
    if(root != NULL  && root->data == cari){
        cout<<"data ditemukan "<<endl;
    }else if(root->data < cari){
        caridata(root->kanan,cari);
    }else {
        caridata(root->kiri,cari);
    }
    main();
}

struct binary* deletedata(binary *root, int del){
    if(root == NULL){
        return root;
    }else if(del < root->data)
    root->kiri = deletedata(root->kiri,del);
    else if(del>root->data)
    root->kanan = deletedata(root->kanan,del);
    else{
        if(root->kiri == NULL&&root->kanan == NULL){
            delete root;
            root = NULL;
            return root;
        }else if(root->kiri==NULL){
            struct binary* temp = root;
            root = root -> kanan;
            delete temp;
        }else if(root->kanan==NULL){
            struct binary* temp = root;
            root = root -> kiri;
            delete temp;
        }else {
            struct binary* min_right_subtree;
            struct binary* temp =  root->kanan;
            while(temp->kiri != NULL){
                temp = temp->kiri;
            }
            min_right_subtree = temp;
            
            root->data = min_right_subtree -> data;

            root->kanan= deletedata(root->kanan, min_right_subtree->data);
        }
    }
    return root;
}

int preorder(binary *root){
    if(root==NULL){
        return 0;
    }
    cout<<root->data<<" ";

    preorder(root->kiri);
    
    preorder(root->kanan);
}
int inorder(binary *root){
    if(root==NULL){
        return 0;
    }
    inorder(root->kiri);
    cout<<root->data<<" ";
    inorder(root->kanan);
}

int postorder(binary *root){
    if(root==NULL){
        return 0;
    }
    postorder(root->kiri);
    postorder(root->kanan);
    cout<<root->data<<" ";
}

int main(){
    int chose,angkain;

    cout<<endl<<"1. masukkan data"<<endl;
    cout<<"2. cari data"<<endl;
    cout<<"3. hapus data"<<endl;
    cout<<"4. Preorder, inorder, postorder "<<endl;
    cout<<"Pilihan : ";
    cin>>chose;
    switch (chose)
    {
    case 1:
        cout<<"masukkan angka : ";
        cin>>angkain;
        datamasuk(&root,angkain);
        break;
    case 2:
        cout<<"masukkan angka : ";
        cin>>angkain;
        caridata(root,angkain);
        break;
    case 3:
        cout<<"hapus data : ";
        cin>>angkain;
        deletedata(root,angkain);
        main();
        break;
    case 4:
        cout<<"preorder : "<<endl;
        preorder(root);
        cout<<endl<<"postorder : "<<endl;
        postorder(root);
        cout<<endl<<"postorder : "<<endl;
        inorder(root);
        main();
        break;
    default:
        break;
    }
}
