![图片.png](https://pic.leetcode-cn.com/419253b00a26aa5e48fb17cd33fc52377f11ac2425347bc2add0320a1026004d-%E5%9B%BE%E7%89%87.png)

```
/**
 * @param {number[]} nums
 * @return {number[][]}
 */


var subsets = function(nums) {
    let res = [], cur = []
    generateSubset(nums, 0,  cur, res)
    return res
};

generateSubset = function(nums,index,cur,res) {
   if (index === nums.length){
       res.push([].concat(cur))
       return
   }
    // 不选
    generateSubset(nums, index + 1, cur, res)
    // 选
    cur.push(nums[index])
    generateSubset(nums, index + 1, cur, res)
    cur.pop()
   
}
```
