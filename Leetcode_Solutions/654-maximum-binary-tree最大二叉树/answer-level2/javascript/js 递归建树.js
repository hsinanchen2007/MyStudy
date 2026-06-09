```js
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {number[]} nums
 * @return {TreeNode}
 */
var constructMaximumBinaryTree = function(nums) {
    
    const digui = function(arr){
        if(arr.length === 0) return null
        
        // 找到最大元素所在index
        let max = - Infinity, maxIndex = 0
        arr.forEach((num, index) => {
            if(num > max){
                max = num
                maxIndex = index
            }
        })

        const newNode = new TreeNode(max)
        newNode.left = digui(arr.slice(0, maxIndex))
        newNode.right = digui(arr.slice(maxIndex + 1))

        return newNode
    }

    return digui(nums)
};
```