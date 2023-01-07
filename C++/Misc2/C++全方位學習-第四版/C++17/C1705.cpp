//檔案名稱：d:\C++17\C1705.cpp
#include <iostream>
using namespace std;

struct TreeNode {	//定義TreeNode結構資料
	int data;
	TreeNode *left;
	TreeNode *right;
};

class BinaryTree {	//定義二元樹資料類別
	TreeNode *root;
public:
	BinaryTree() { root = NULL; }
	void insertNode(int);	//插入節點函數原型
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

int main(int argc, char** argv)
{
   	BinaryTree intTree;
	cout << "插入節點...";
	intTree.insertNode(5);	//呼叫insertNode函數
	intTree.insertNode(9);	//呼叫insertNode函數
	intTree.insertNode(1);	//呼叫insertNode函數
	intTree.insertNode(6);	//呼叫insertNode函數
	intTree.insertNode(4);	//呼叫insertNode函數
	cout << "完成\n";
	return 0;
}
