### 解题思路
这道题目和 451题：根据字符出现频率排序 基本相同
[https://leetcode-cn.com/problems/sort-characters-by-frequency/](https://leetcode-cn.com/problems/sort-characters-by-frequency/)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var topKFrequent = function(nums, k) {
    var map=new Map();
    for(var i=0;i<nums.length;i++){
        if(map.has(nums[i])){
            map.set(nums[i],map.get(nums[i])+1)
        }else{
            map.set(nums[i],1)
        }
    }
    var arr=[];
    map.forEach((value,key)=>arr.push({name:key,value:value}));
    arr.sort((a,b)=>b.value-a.value);
    var arr2=[]
    for(var i=0;i<k;i++){
        arr2.push(arr[i].name)
    }
    return arr2;
};
```