//檔案名稱：d:\C++17\C1706.cpp
#include <iostream>
using namespace std;

struct TreeNode {	//定義TreeNode結構資料
	int data;
	TreeNode *left;
	TreeNode *right;
};

class BinaryTree {	//定義二元樹資料類別
	TreeNode *root;
	void showInOrder(TreeNode *);	//顯示InOrder資料原型
	void showPreOrder(TreeNode *);	//顯示PreOrder資料原型
	void showPostOrder(TreeNode *);	//顯示PostOrder原型
public:
	BinaryTree() { root = NULL; }
	void insertNode(int);	//插入節點函數原型
	void coutInOrder() { showInOrder(root); }	//呼叫InOrder資料函數
	void coutPreOrder() { showPreOrder(root); }	//呼叫PreOrder資料函數
	void coutPostOrder() { showPostOrder(root); }	//呼叫PostOrder函數
};

void BinaryTree::insertNode(int num)	//插入節點函數
{
	TreeNode *newNode = new TreeNode;	//newNode為新節點指標
	TreeNode *tempNode;	//tempNode為暫存節點
	newNode->left = newNode->right = NULL;	//令新節點左右指標=NULL
	newNode->data = num;	//資料存入新節點的緩衝區
	if(root == NULL) {	//若二元樹還沒有資料
		root = newNode;	//令根節點=新節點
	} else {		//若二元樹中已有資料
		tempNode = root;	//令tempNode指向root
		while(tempNode) {	//當tempNode不等於NULL
			if(num < tempNode->data) {	//新資料 < tempNode->data
				if(tempNode->left) {	//若tempNode->left != NULL
				    tempNode = tempNode->left;	//tempNode->left為臨時指標
				} else {	//若tempNode->left == NULL
				    tempNode->left = newNode;	//新節點插入tempNode->left
				    break;
				}
			} else if(num > tempNode->data) {	//新資料 > tempNode->data
				if(tempNode->right) {	//若tempNode->right!=NULL
				    tempNode = tempNode->right;	//tempNode->right為臨時指標
				} else {	//若tempNode->right==NULL
				    tempNode->right = newNode;	//新節點插入tempNode->right
				    break;
				}
			} else {	//新資料 == tempNode->data
				cout << "資料重複！";
				break;
			}
		}
	}
}

void BinaryTree::showInOrder(TreeNode *nodePtr)	//顯示InOrder資料函數
{
	if(nodePtr)	//若nodePtr不等於NULL
	{
		showInOrder(nodePtr->left);	//遞回呼叫，越過左邊分支
		cout << nodePtr->data << ' ';	//處理節點資料
		showInOrder(nodePtr->right);	//遞回呼叫，越過右邊分支
	}
}

void BinaryTree::showPreOrder(TreeNode *nodePtr)	//顯示PreOrder資料函數
{
	if(nodePtr)	//若nodePtr不等於NULL
	{
		cout << nodePtr->data << ' ';	//處理節點資料
		showPreOrder(nodePtr->left);	//遞回呼叫，越過左邊分支
		showPreOrder(nodePtr->right);	//遞回呼叫，越過右邊分支
	}
}

void BinaryTree::showPostOrder(TreeNode *nodePtr)	//顯示PostOrder函數
{
	if(nodePtr)	//若nodePtr不等於NULL
	{
		showPostOrder(nodePtr->left);	//遞回呼叫，越過左邊分支
		showPostOrder(nodePtr->right);	//遞回呼叫，越過右邊分支
		cout << nodePtr->data << ' ';	//處理節點資料
	}
}

int main(int argc, char** argv)
{
	BinaryTree intTree;
	cout << "插入節點...";
	intTree.insertNode(5);	//呼叫insertNode函數
	intTree.insertNode(9);	//呼叫insertNode函數
	intTree.insertNode(1);	//呼叫insertNode函數
	intTree.insertNode(6);	//呼叫insertNode函數
	intTree.insertNode(4);	//呼叫insertNode函數
	cout << "完成";
	cout << "\n顯示PreOrder資料：";
	intTree.coutPreOrder();	//呼叫coutPreNode函數
	cout << "\n顯示PostOrder資料：";
	intTree.coutPostOrder();	//呼叫coutPostNode函數
	cout << "\n顯示InOrder資料：";
	intTree.coutInOrder();	//呼叫coutInNode函數
	cout << endl;
	return 0;
}
