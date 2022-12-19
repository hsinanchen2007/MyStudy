```javascript []
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
// 1.首先看到这道题 我想到用递归 自己调自己
// 2.翻转一颗空树 结果还是一颗空树 因此需要判断这棵树是否为null
// 3.树有两个节点 left 和 right 所以需要递归一直调用这两个节点
// 4.示例的递归执行顺序 所以说并不会出现 翻转完left 又翻转 right 跟没翻转一样的情况  
// 5.如果有大佬思想更好 总结的更易懂 请不吝赐教 
/** 执行顺序 跟着这个顺序自己执行一遍 更加清晰 哦 
4
2
1
null
null
3
null
null
7
6
null
null
9
null
null
*/
var invertTree = function(root) {
    // 递归 将给定节点的 left right 互换
    function invertNode(node){
        
        if(node === null){
            return null
        }

        let left = invertNode(node.left)
        let right = invertNode(node.right)
        node.left = right
        node.right = left
        return node
    }
    invertNode(root)
    return root
    // 如下 是最直白的方法 这个应该都能懂
//     function changeNode(node){
//        if(node !== null){
//         if(node.left !== null && node.right !== null){
//             // val 翻转
//         let right = Object.assign({},node.right)
//         let left = Object.assign({},node.left)
//         // node.left.val = right.val
//         // node.left.left = right.left
//         // node.left.right = right.right
//         // node.right.val = left.val
//         // node.right.left = left.left
//         // node.right.right = left.right
//         node.left = right
//         node.right = left
//             changeNode(node.left)
//             changeNode(node.right)
//        }else if(node.left !== null){
//            let left = Object.assign({},node.left)
//            node.left = null
//            node.right = left
//            changeNode(node.right)
//        }else if(node.right !== null){
//            let right = Object.assign({},node.right)
//            node.right = null
//            node.left = right
//            changeNode(node.left)
//        }
//        }
        
        
//     }
//     changeNode(root)
//     // console.log(root)
//     return root
};
```

