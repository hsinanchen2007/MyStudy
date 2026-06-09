### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    let res = []
    if(!nums.length) return res
    let pb ={};
    let len = nums.length
    let p = [...new Set(nums)]
    for(let i of nums){
        if(pb[i]){
            pb[i] += 1
        }else{
            pb[i] = 1
        }
    }
    let dfs = (nums,pb,temp,res,length) =>{
        //截止条件
        if(temp.length === length){
            res.push([...temp])
            return
        }
        //候选节点
        for(let i=0;i<nums.length;i++){
            //候选条件
            if(pb[nums[i]]){
                temp.push(nums[i])
                pb[nums[i]] = pb[nums[i]]-1
                dfs(nums, pb, temp, res, length)
                pb[nums[i]]= pb[nums[i]]+1
                temp.pop()
            }
        }
    }
    dfs(p, pb, [], res,len)
    return res
};
```