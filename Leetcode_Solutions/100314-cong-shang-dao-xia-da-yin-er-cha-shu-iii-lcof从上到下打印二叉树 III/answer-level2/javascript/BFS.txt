### 解题思路
1. 从题目中得知，我可以用奇偶数来判断元素的添加的位置
2. 参考https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/solution/js-dui-lie-shu-zu-by-59yqcidez3/

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
var levelOrder = function(root) {
    const res = []
    if(root == null){
        return res
    }
    const queue = [];
    queue.push(root);
    //0是偶数，从题目得知从奇数开始的
    let level =1;
    while(queue.length>0){
        let len = queue.length;
        let tempArr = [];
        for(let i = 0; i<len;i++){
            let nodes = queue.shift();
            //判断是否奇数
            if(level & 1){
                //添加尾部
                tempArr.push(nodes.val)
            }else{
                //偶数向头插入
                tempArr.unshift(nodes.val)
            }
            if(nodes.left){
                queue.push(nodes.left)
            }
            if(nodes.right){
                queue.push(nodes.right)
            }
        }
        res.push(tempArr)
        level++
    }

    return res

};
```