### 解题思路
先使用双指针法找出全部符合条件的三个数，再人工去重。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var duplicate =function(arr){
        // 法一：es6
        // let res=new Map();
        // arr.forEach(item=>{
        //     item.sort((a,b)=>a-b);
        //     res.set(item.join(),item);
        // });        
        // return Array.from(res.values);

        // 法二：
        let res={}
        arr.forEach(item=>{
            item.sort((a,b)=>a-b);
            res[item]=item;
        });
        return Object.values(res)
}
var threeSum = function(nums) {
    const result = [];
    nums.sort(function(a,b){
        return a - b;
    });
    if((nums.length < 3) || ((nums[0] === nums[nums.length - 1]) && nums[0] !== 0)) return result;
    if(nums[0] === 0 && nums[nums.length - 1] === 0) {
       const temp = [0,0,0];
       result.push(temp);
       return result;
    }
    
    for(let i = 0;i < nums.length;i ++) {
        let j = i + 1;
        let k = nums.length - 1;
        while(j < k) {
            if(nums[i] + nums[j] + nums[k] === 0) {
                let item = [].concat(nums[i]).concat(nums[j]).concat(nums[k]);
                result.push(item);
                j ++;
                k --;
            } else if(nums[i] + nums[j] + nums[k] < 0) {
                j ++;
            } else {
                k --;
            }
        }
    }
    return duplicate(result);
};
```