//�ɮצW�١Gd:\C++17\C1708.cpp
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
	void deleteNode(int num, TreeNode *&nodePtr);	//�R���`�I��ƭ쫬
public:
	BinaryTree() { root = NULL; }
	void insertNode(int);	//���J�`�I��ƭ쫬
	void coutInOrder() { showInOrder(root); }	//�I�sInOrder��ƨ��
	void coutPreOrder() { showPreOrder(root); }	//�I�sPreOrder��ƨ��
	void coutPostOrder() { showPostOrder(root); }	//�I�sPostOrder���
	bool searchNode(int num);	//�j�M��ƨ�ƭ쫬
	void removeNode(int num) { deleteNode(num, root); } //�I�s�R���`�I�쫬
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
				if(tempNode->left) {	//�YtempNode->left!=NULL
				    tempNode = tempNode->left;	//tempNode->left���{�ɫ���
				} else {	//�YtempNode->left==NULL
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

bool BinaryTree::searchNode(int num)	//�j�M�G�����ƨ��
{
	TreeNode *nodePtr = root;	//�OnodePtr����root
	while(nodePtr)	//��nodePtr������NULL
	{
		if(num == nodePtr->data)	//�Y�j�M���==�`�I���
			return true;
		else if(num < nodePtr->data)	//�Y�j�M���<�`�I���
			nodePtr = nodePtr->left;
		else if(num > nodePtr->data)	//�Y�j�M���>�`�I���
			nodePtr = nodePtr->right;
	}
	return false;
}

void BinaryTree::deleteNode(int num, TreeNode *&nodePtr) 
{					//�R���G����`�I���
	if(num < nodePtr->data)	//�Y�j�M���<�`�I���
		deleteNode(num, nodePtr->left);	//���^�I�sdeleteNode
	else if(num > nodePtr->data)	//�Y�j�M���>�`�I���
		deleteNode(num, nodePtr->right);	//���^�I�sdeleteNode
	else {		//�Y�j�M���==�`�I���
		TreeNode *tempNode;	//�إ��{�ɸ`�I
		if(nodePtr == NULL)	//�YnodePtr����NULL
			cout << "����R���Ÿ`�I�I";
		else if(nodePtr->right == NULL)	//�YnodePtr->right����NULL
		{
			tempNode = nodePtr;	//�OtempNode�n�R�����`�I
			nodePtr = nodePtr->left;	//�OnodePtr = nodePtr->left
			delete tempNode;	//�R��tempNode�`�I
		}
		else if(nodePtr->left == NULL)	//�YnodePtr->left����NULL
		{
			tempNode = nodePtr;	//�OtempNode�n�R�����`�I
			nodePtr = nodePtr->right;	//�OnodePtr=nodePtr->right
			delete tempNode;	//�R��tempNode�`�I
		}
		else		//�H�W�ҫD
		{
			tempNode = nodePtr->right;	//�OtempNode=nodePtr->right
			while(tempNode->left)	//tempNode->left������NULL
				tempNode = tempNode->left;	//�OtempNode=����l�`�I
			tempNode->left = nodePtr->left;
			tempNode = nodePtr;	//tempNode���n�R���`�I
			nodePtr = nodePtr->right;	//�OnodePtr=nodePtr->right
			delete tempNode;	//�R��tempNode�`�I
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
	cout << "����";
	cout << "\n���PreOrder��ơG";
	intTree.coutPreOrder();	//�I�scoutPreNode���
	cout << "\n���PostOrder��ơG";
	intTree.coutPostOrder();	//�I�scoutPostNode���
	cout << "\n���InOrder��ơG";
	intTree.coutInOrder();	//�I�scoutInNode���

	if(intTree.searchNode(3))	//�I�ssearchNode���
		cout << "\n�b�G�����Ƶ��c����� 3\n";
	else
		cout << "\n�b�G�����Ƶ��c���䤣�� 3\n";

	cout << "\n�R���`�I 9";
	intTree.removeNode(9);	//�I�sremoveNode���
	cout << "\n�R���`�I 1";
	intTree.removeNode(1);	//�I�sremoveNode���
	cout << "\n���InOrder��ơG";
	intTree.coutInOrder();	//�I�scoutInNode���
	cout << endl;
	return 0;
}
