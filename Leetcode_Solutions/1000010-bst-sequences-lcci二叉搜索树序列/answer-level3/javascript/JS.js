### 解题思路
&emsp;&emsp;写一个js版本，主要难点就是左右节点数组保持相对顺序的合并。

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
 * @return {number[][]}
 */
var BSTSequences = function(root) {
    //相对顺序合并
    function permutationAll(arr1, arr2){
        function permutation(arr1, arr2, temp, ret){
            if(arr1.length == 0){
                ret.push([...temp.concat(arr2)]);
                return;
            }
            if(arr2.length == 0){
                ret.push([...temp.concat(arr1)]);
                return;
            }
            temp.push(arr1.shift());
            permutation(arr1, arr2, temp, ret);
            arr1.unshift(temp.pop());
            temp.push(arr2.shift());
            permutation(arr2, arr1, temp, ret);
            arr2.unshift(temp.pop());
            return ret;
        }
        if(arr1.length == 0) return arr2;
        if(arr2.length == 0) return arr1;
        let ret = [];
        for(let i = 0; i < arr1.length; i++){
            for(let j = 0; j < arr2.length; j++){
                ret.push(...permutation(arr1[i], arr2[j], [], []));
            }
        }
        return ret;
    }
    function dfs(root){
        if(root == null) return [];
        let leftArray = dfs(root.left),
            rightArray = dfs(root.right),
            mergeSet = permutationAll(leftArray, rightArray);
        if(mergeSet.length == 0){
            mergeSet.push([]);
        }
        for(let i = 0; i < mergeSet.length; i++){
            mergeSet[i].unshift(root.val);
        }
        return mergeSet;
    }
    let ret = dfs(root);
    return ret.length == 0 ? [[]] : ret;
};
```