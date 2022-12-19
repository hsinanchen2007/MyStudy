### 解题思路
1. 判断A或B是否为null
2. 判断AB根值是否相同，A的left判断、A的right判断
5. 只要有个符合就return  true
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
 * @param {TreeNode} A
 * @param {TreeNode} B
 * @return {boolean}
 */
var isSubStructure = function(A, B) {
    //如果A或B其中为空返回false
    if(!A || !B){
        return false
    }

    function back(A,B){
        //back 函数出口条件：B首先要放在首位
        if(!B){
            return true
        }
        if(!A){
            return false
        }
        //判断a的当前值是否和b相同
        if(A.val !== B.val){
            return false
        }
        return back(A.left,B.left) && back(A.right,B.right)
    }
    return back(A,B) || isSubStructure(A.left,B) || isSubStructure(A.right,B)
};
```