```javascript []
题意很难理解 看了几个老哥的题解 这是一个二叉搜索树的题 而且用中序排列法 意思是求出 x>=L && x<=R 的值的和 
然后本人立马看了看相关二叉树的知识 然后写了一个二叉树 结果发现本题参数不是一个数组 而是一个二叉树对象 真坑呀 
总而言之 我用的是递归 贴出代码 仅供参考 有更好的方法请发表意见 共同学习 二叉树详情请在网上查阅 
JS天下第一   慢
提交时间	提交结果	执行用时	内存消耗	语言
7 分钟前	通过	324 ms	69.4 MB	Javascript
7 分钟前	通过	292 ms	68.8 MB	Javascript
7 分钟前	通过	392 ms	68.8 MB	Javascript
9 分钟前	通过	364 ms	68.5 MB	Javascript
11 分钟前	通过	368 ms	68.9 MB	Javascript
12 分钟前	通过	332 ms	69.1 MB	Javascript
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} L
 * @param {number} R
 * @return {number}
 */
var rangeSumBST = function(root, L, R) {

        let num = 0;
        
        const inOrderNode = (node)=>{
            if(node !== null){
                inOrderNode(node.left)
                if(node.val>=L && node.val<=R){
                    num+=node.val
                }
                inOrderNode(node.right)
            }
        }
        
        inOrderNode(root)
    
        return num
    
};
```
