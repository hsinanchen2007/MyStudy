![image.png](https://pic.leetcode-cn.com/ff082375a77f40acac5fa6057c14e8db7beb65fd543db0b19f0c2695b7f76170-image.png)

```
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
    var arr=[];
    var arrlast=[];
    function add(deep, node){
        var temp = new ListNode(node.val);
        if(arr[deep]){
            arrlast[deep].next = temp;
            arrlast[deep] = temp;
        }
        else{ 
            arr[deep] = temp;
            arrlast[deep] = temp;
        }
        if(node.left){
            add(deep+1, node.left);
        }
        if(node.right){
             add(deep+1, node.right);
        }
    }
    add(0, tree);
    return arr;
};
```
