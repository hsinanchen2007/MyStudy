//�ɮצW�١Gd:\C++17\C1706.cpp
#include <iostream>
using namespace std;

struct TreeNode {	//�w�qTreeNode���c���
	int data;
	TreeNode *left;
	TreeNode *right;
};

class BinaryTree {	//�w�q�G���������O
	TreeNode *root;
	void showInOrder(TreeNode *);	//���InOrder��ƭ쫬
	void showPreOrder(TreeNode *);	//���PreOrder��ƭ쫬
	void showPostOrder(TreeNode *);	//���PostOrder�쫬
public:
	BinaryTree() { root = NULL; }
	void insertNode(int);	//���J�`�I��ƭ쫬
	void coutInOrder() { showInOrder(root); }	//�I�sInOrder��ƨ��
	void coutPreOrder() { showPreOrder(root); }	//�I�sPreOrder��ƨ��
	void coutPostOrder() { showPostOrder(root); }	//�I�sPostOrder���
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

void BinaryTree::showInOrder(TreeNode *nodePtr)	//���InOrder��ƨ��
{
	if(nodePtr)	//�YnodePtr������NULL
	{
		showInOrder(nodePtr->left);	//���^�I�s�A�V�L�������
		cout << nodePtr->data << ' ';	//�B�z�`�I���
		showInOrder(nodePtr->right);	//���^�I�s�A�V�L�k�����
	}
}

void BinaryTree::showPreOrder(TreeNode *nodePtr)	//���PreOrder��ƨ��
{
	if(nodePtr)	//�YnodePtr������NULL
	{
		cout << nodePtr->data << ' ';	//�B�z�`�I���
		showPreOrder(nodePtr->left);	//���^�I�s�A�V�L�������
		showPreOrder(nodePtr->right);	//���^�I�s�A�V�L�k�����
	}
}

void BinaryTree::showPostOrder(TreeNode *nodePtr)	//���PostOrder���
{
	if(nodePtr)	//�YnodePtr������NULL
	{
		showPostOrder(nodePtr->left);	//���^�I�s�A�V�L�������
		showPostOrder(nodePtr->right);	//���^�I�s�A�V�L�k�����
		cout << nodePtr->data << ' ';	//�B�z�`�I���
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
	cout << "����";
	cout << "\n���PreOrder��ơG";
	intTree.coutPreOrder();	//�I�scoutPreNode���
	cout << "\n���PostOrder��ơG";
	intTree.coutPostOrder();	//�I�scoutPostNode���
	cout << "\n���InOrder��ơG";
	intTree.coutInOrder();	//�I�scoutInNode���
	cout << endl;
	return 0;
}
