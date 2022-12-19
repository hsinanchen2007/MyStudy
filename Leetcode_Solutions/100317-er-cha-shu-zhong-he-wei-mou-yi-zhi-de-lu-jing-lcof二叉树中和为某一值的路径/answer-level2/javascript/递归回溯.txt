### 解题思路
- 大家都知道JS，
- 基本类型：字符串（String）、数字(Number)、布尔(Boolean)、对空（Null）、未定义（Undefined）、Symbol
- 对象类型：Object
- 递归回溯：如果条件不符合，回到上一步另一个选择进行递归。

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
 * @param {number} sum
 * @return {number[][]}
 */
var pathSum = function(root, sum) {

    const res = [];
    if(root == null){
        return res
    }

    function helper(node,target,paths){
        paths.push(node.val);
        //递归结束条件
        if(!node.left && !node.right && node.val === target){
            res.push(paths)
        }
        //使用slice进行浅拷贝
        //根据题目的例子
        //执行到 7 的时候 都不符合
        //它会回到11哪步，执行node.right
        //接着执行下面代码
        if(node.left){
            helper(node.left,target-node.val,paths.slice())
        }
        // 使用slice进行浅拷贝
        if(node.right){
            helper(node.right,target-node.val,paths.slice())
        }

    }

    helper(root,sum,[]);
    return res

};
```