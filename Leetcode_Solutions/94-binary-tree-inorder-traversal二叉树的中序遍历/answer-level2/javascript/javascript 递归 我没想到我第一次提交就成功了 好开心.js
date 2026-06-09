### 解题思路
好激动 我第一次 写 递归 写 关于二叉树的问题 这么快解决 且第一次提交就过的！！！！！激动的想要叫起来

刚开始写了一版 自测的测试用例都没过 
后来想起来 某位面试官说过的话 你还是不理解递归的意义 我知道 我还不熟练 于是 在纸上写了一下 只有 两层时是什么情况 后来 再写一遍 就成了！！！

首先 中序遍历  即左中右 所以 根节点 需等待左边子数遍历完成才能去根 再去右
我想有一个 可以存放的 全局数组 也就是 result 

自己定义了递归需要调用的函数

先判断 如果 root 就是 null  直接return; 注意这里只是 简单的return; 外层是 return的 result 空数组 因为没有任何 的push 操作

如果不是null 则可能 没有左子节点 或者 右子节点 

先判断有没有左子节点 如果有 root.val需等待 左边push[递归调用 这里 会进行左边的全部的工作 ] 【再进行根节点的push】 进数组 再 将 root.val push进去  最后  右边 递归调用函数 不管是否为null 丢进去函数 里面 函数自然会去 做处理 这是递归的神秘之处
 
### 代码

```javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function(root) {
    // 先用递归看一哈
    let result = [];
    function fn(root){
        if( root === null ){
            return; // 什么都不做
        }
        if( root.left === null ){
            result.push(root.val); // 左边没有子节点 直接push
        }else{ 
            fn(root.left); // 左边有 那么递归调用  
            result.push(root.val); // 上面事情做完  push 相对的根节点
        }
        fn(root.right); // 递归右子节点
    }
    fn(root); // 初次调用
    return result; // 返回结果
};
```