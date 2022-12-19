
***1. 有序序列递归的进行二分生成高度平衡的BST，不再赘述（突然想不起来如何证明生成的一定是平衡的，有人可以告诉一下吗？）
2. 另外就是一个经典的递归生成树的问题了，之前在一个重要的机试上因为这个简单的问题摔过跤 : )***
首先是一个节点是需要new TreeNode的，不然根本无法访问其val和左右指针，因为这些attribute根本还没生成（指针只定义不初始化，系统是不会分配内存的。想象一下动态数组就行了，不new怎么访问元素）。除非只想把这个东西做一个临时指针指向别人，那么`TreeNode* a=NULL`才好，否则`r = new TreeNode(……)`才是合理的。另外`TreeNode* a=NULL`是一个安全的做法，比如这道题有为空的情况。
另外，如果只做到上述的，会发现好不容易递归生成的树，返回来后全是空的，很简单的会联想到局部变量的问题，函数参数TreeNode*不是已经是个指针了吗？为什么还会这样？数组指针传入函数所作的变换为何返回来后不会失效？为什么createBST得加上&才成功。
原因在于这里函数的参数传递还是值传递/值拷贝，函数内只是新建了一个指针变量，复制了其指向的地址，也就是该指针的内容，但是一般在数组这种操作，只是改变其某个元素值。所以返回后，基于原来的指针，还是可以访问的。
但是如果是new的话，注意到动态分配的一块区间的起始地址，可不一定是刚才那地址。所以很明显的，只是值拷贝，又没返回新地址。当然在函数外访问旧地址是无效的。可以参考一下例子：

```
#include<iostream>
using namespace std;

void test(int* a){ //拷贝的只是指向的东西，而非该变量的真正地址 
	printf("函数内该指针所在地址：%p\n",&a);
	printf("函数内该指针所指地址：%p\n",a);
	a = new int[2];
	printf("new之后函数内该指针所在地址：%p\n",&a);
	printf("new之后函数内该指针所指地址：%p\n",a);
}

int main(){
	int i;
	int* a;
	printf("函数外该指针所在地址：%p\n",&a);
	printf("函数外该指针所指地址：%p\n",a);
	test(a);
	printf("函数返回后该指针所在地址：%p\n",&a);
	printf("函数返回后该指针所指地址：%p\n",a);
	return 0;
}
```
```
函数外该指针所在地址：00000000006ffe48
函数外该指针所指地址：0000000000000001
函数内该指针所在地址：00000000006ffe20
函数内该指针所指地址：0000000000000001
new之后函数内该指针所在地址：00000000006ffe20
new之后函数内该指针所指地址：0000000000a614f0
函数返回后该指针所在地址：00000000006ffe48
函数返回后该指针所指地址：0000000000000001
```
可以看到指针所在地址在函数内外不同，说明本质上不是同一个“指针变量”，只是其内容（所指地址）相同。而new之后问题就来了，新分配的区间起始地址变了，因而函数内指针的内容也变量。但其实函数外的指针内容还没变，所以访问不到分配的区间。
以下为加上&后的输出，这是函数内外本质都是同个指针变量了。
```
函数外该指针所在地址：00000000006ffe48
函数外该指针所指地址：0000000000000001
函数内该指针所在地址：00000000006ffe48
函数内该指针所指地址：0000000000000001
new之后函数内该指针所在地址：00000000006ffe48
new之后函数内该指针所指地址：00000000008314f0
函数返回后该指针所在地址：00000000006ffe48
函数返回后该指针所指地址：00000000008314f0
```
**总结一下，定义指针要么先赋值为NULL，要么给new。另外函数内的new是不能直接给函数外用的，除非用引用。**

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void createBST(TreeNode* &r,vector<int>& nums,int front,int tail){//注意tail是不可触碰的,注意这里的&
        if (front>=tail) // 注意=，因为tail表示的是开区间
            return;
        int mid = (tail+front)/2;
        r = new TreeNode(nums[mid]);  // NOTICE NEW!
        // r->val = nums[mid]; XXXX
        createBST(r->left,nums,front,mid);
        createBST(r->right,nums,mid+1,tail);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL; //注意加上这个null，这和new有何区别？
        sort(nums.begin(),nums.end());
        
        createBST(root,nums,0,(int)nums.size());
        return root;
    }
};
```
