### 解题思路
递归的方式，深度优先。每遇到一个节点，把它放到相应level的链接里。如果没有链接，创建链表。
result保存链表的表头，也就是答案
curList保存链表的最后一个结点，方便append数据

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
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {TreeNode} tree
 * @return {ListNode[]}
 */
var listOfDepth = function(tree) {
 let result=[]
 let curList=[]
 function helper(root,level){
     if(!root) return
     if(level in result){
         let node=new ListNode(root.val)
         curList[level].next=node
         curList[level]=node
     }
     else{
         result[level]=curList[level]=new ListNode(root.val)
         
     }
     helper(root.left,level+1)
     helper(root.right,level+1)
 }
  helper(tree,0)
  return result
};
```