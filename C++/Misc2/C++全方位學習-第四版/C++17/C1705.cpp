//�ɮצW�١Gd:\C++17\C1705.cpp
#include <iostream>
using namespace std;

struct TreeNode {	//�w�qTreeNode���c���
	int data;
	TreeNode *left;
	TreeNode *right;
};

class BinaryTree {	//�w�q�G���������O
	TreeNode *root;
public:
	BinaryTree() { root = NULL; }
	void insertNode(int);	//���J�`�I��ƭ쫬
};

void BinaryTree::insertNode(int num)	//���J�`�I���
{
	TreeNode *newNode = new TreeNode;	//newNode���s�`�I����
	TreeNode *tempNode;	//tempNode���Ȧs�`�I
	newNode->left = newNode->right = NULL;	//�O�s�`�I���k����=NULL
	newNode->data = num;	//��Ʀs�J�s�`�I���w�İ�
	if(root == NULL) {	//�Y�G�����٨S�����
		root = newNode;	//�O�ڸ`�I=�s�`�I
	} else {		//�Y�G���𤤤w�����
		tempNode = root;	//�OtempNode���Vroot
		while(tempNode) {	//��tempNode������NULL
			if(num < tempNode->data) {	//�s��� < tempNode->data
				if(tempNode->left) {	//�YtempNode->left != NULL
				    tempNode = tempNode->left;	//tempNode->left���{�ɫ���
				} else {	//�YtempNode->left == NULL
				    tempNode->left = newNode;	//�s�`�I���JtempNode->left
				    break;
				}
			} else if(num > tempNode->data) {	//�s��� > tempNode->data
				if(tempNode->right) {	//�YtempNode->right!=NULL
				    tempNode = tempNode->right;	//tempNode->right���{�ɫ���
				} else {	//�YtempNode->right==NULL
				    tempNode->right = newNode;	//�s�`�I���JtempNode->right
				    break;
				}
			} else {	//�s��� == tempNode->data
				cout << "��ƭ��ơI";
				break;
			}
		}
	}
}

int main(int argc, char** argv)
{
   	BinaryTree intTree;
	cout << "���J�`�I...";
	intTree.insertNode(5);	//�I�sinsertNode���
	intTree.insertNode(9);	//�I�sinsertNode���
	intTree.insertNode(1);	//�I�sinsertNode���
	intTree.insertNode(6);	//�I�sinsertNode���
	intTree.insertNode(4);	//�I�sinsertNode���
	cout << "����\n";
	return 0;
}
