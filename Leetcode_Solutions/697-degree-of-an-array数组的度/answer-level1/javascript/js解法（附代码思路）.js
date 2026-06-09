### 解题思路
① 找出目标数组的度
② 找出数组中频数为度的各个元素（记 元素A，元素B）
③ 由题目可知，符合条件的连续子数组需要全部包含一种元素（元素A或元素B），因此只需要算出该元素的始末位置并求出最小值即可完成题目要求

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findShortestSubArray = function(nums) {
    // 利用obj来统计nums中各个整数出现的频数
    let obj = {};
    const len = nums.length;
    for(let i = 0;i < len;i++){
        if(nums[i] in obj){
            obj[nums[i]]++;
        }else{
            obj[nums[i]] = 1;
        }
    }
    // 找出数组的度
    let degree = 0;
    for(x in obj){
        degree = Math.max(degree,obj[x]);
    }
    // 找出数组的度的所属元素,并统计该元素在数组中的始末位置(始末位置+1就是符合要求的子数组的长度)然后计算出子数组长度的最小值
    let res = len;
    for(x in obj){
        if(obj[x] === degree){
            res = Math.min(res,nums.lastIndexOf(+x) - nums.indexOf(+x)+1);
        }
    }
    return res;
    
};
```