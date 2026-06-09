
### 思路 1：使用递归
* 中序遍历也叫中根遍历，遍历时，根节点顺序在中间，即左跟右。先根遍历：根左右；后根遍历：左右根。
* 中根遍历最重要的一点是：**如果当前节点没有左子树，记录其值。**
* 成功使用递归的关键：保证每一个节点的值都会被记录，递归有两个条件：递归条件和基线条件。
* 递归条件：用于函数自己调用自己。这里设置为如果左/右子树不为空，递归调用。
* 基线条件：用于保证递归会结束。这里不用设置，因为只要树不是无穷的，递归就能结束。
* 在计算机内部，使用调用栈（Call Stack）来存放函数。调用另一个函数时，当前函数暂停并处于为完成状态，该函数的所有变量的值都还在内存中。
* 时间复杂度：O(n)。

### 代码
```Java []
class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        traversal(root, list);
        return list;
    }

    private void traversal(TreeNode root, List<Integer> list) {
        if (root != null) {
            if (root.left != null) {
                traversal(root.left, list);
            }
            list.add(root.val);//如果当前节点没有左子树，记录其值
            if (root.right != null) {
                traversal(root.right, list);
            }
        }
    }
}
```
```JavaScript []
var inorderTraversal = function (root) {
    let list = [];
    traversal(root, list);
    return list;
};

var traversal = function (root, list) {
    if (root !== null) {
        if (root.left !== null) {
            traversal(root.left, list);
        }
        list.push(root.val);
        if (root.right !== null) {
            traversal(root.right, list);
        }
    }
};
```
### 画解

<![0.png](https://pic.leetcode-cn.com/902b6c0764f1c61dbadeeedd8967bf594c3f8b76333502769af95fed4d418b0b-file_1564548419239),![1.png](https://pic.leetcode-cn.com/14bfeca60e29bad7aca1a8d03b1fe073d62396b8f9b29b9061297cfd57475f1c-file_1564548419250),![2.png](https://pic.leetcode-cn.com/a5de46814732e4b00f5a591be3046231318eceef76b9dec992df462afc5f4773-file_1564548419255),![3.png](https://pic.leetcode-cn.com/0c9406e38fa13fc56491c60b2f575301b1ce9f0c25fb0394349af17b7f9006c2-file_1564548419261),![3-2.png](https://pic.leetcode-cn.com/df17356c3313a7dd135c251b2efe649cadaccb2ecb30ddf0b48fc62b24a82cc1-file_1564548419271),![4.png](https://pic.leetcode-cn.com/c124950cadbaa3c28ecf7815409feb8272e30c588ecd9e5117356166142265ca-file_1564548419273),![5.png](https://pic.leetcode-cn.com/e04f8f54af5a52939e08784150fbbaf05a1418f062c2faa64a66eba24eab190b-file_1564548419276),![5-2.png](https://pic.leetcode-cn.com/c14a5fed955184e04f286a3c2c495e560d8f0933859b18278b6ec91f13a2ecfa-file_1564548419278),![6.png](https://pic.leetcode-cn.com/b1feebf5e07befcfa4a7a0f08998efed1b173c72a1a8124a46d220437bc86d07-file_1564548419283),![6-2.png](https://pic.leetcode-cn.com/88d11942bf9d217a30fc743a46e51365958d0269da0e912487beb1c79380a94c-file_1564548419284),![7.png](https://pic.leetcode-cn.com/3912d7e730227b85394aa09d1cbe5653b8bfd6a6da9615faf01c3f1784735161-file_1564548419287),![8.png](https://pic.leetcode-cn.com/b327b287209f4282dcfdda3b55f09ad311134810ab010cbb6eb88904cfb8ee8a-file_1564548419288),![9.png](https://pic.leetcode-cn.com/25067498f2682673289e4d65377f36e23325c9bea905f7e6a4ce0d23dc8710ac-file_1564548419292),![9-2.png](https://pic.leetcode-cn.com/28d683dfcaf48aa564e4022cd58ca60628f55408cef4f9d82a8748d193f2a705-file_1564548419290),![10.png](https://pic.leetcode-cn.com/2f37ca50b6409df48614092a700694e7ec7d3a4013905469270a8cd9089dea81-file_1564548419297),![10-2.png](https://pic.leetcode-cn.com/82f18f132f97f97edb748e3e6464c70911cce9b88339e9fdc39e5716a9c18063-file_1564548419298),![11.png](https://pic.leetcode-cn.com/be94ae08ffa3855f422f381427b1c73d18b822726903fdc3b2f2422071a7085a-file_1564548419300),![11-2.png](https://pic.leetcode-cn.com/405814cb4e6b710c38a511c7014e5ec191ee1c9c7a953671d7df609058a28d59-file_1564548419302)>

### 思路 2：使用栈
* 使用递归时，如果没有结合到函数调用栈理解的话，不太好理解
* 在计算机内部，使用调用栈来存放函数，所以可以直接使用栈来实现，更形象
* 具体参考 [LeetCode官方题解](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/solution/er-cha-shu-de-zhong-xu-bian-li-by-leetcode/) 方法二
* 时间复杂度：O(n)