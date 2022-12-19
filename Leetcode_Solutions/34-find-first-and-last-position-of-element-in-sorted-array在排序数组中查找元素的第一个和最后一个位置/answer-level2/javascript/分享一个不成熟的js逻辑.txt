### 解题思路
此处撰写解题思路
1.for  in 方法获取目标值的所有索引，存储到一个数组里面
2.取出数组中，第一个索引和最后一个索引，这样就可以获取到起始位置和终点位置

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    var ponitList=[];
    var tempList=[];
    for (var i in nums){
        if(nums[i]==target){
            ponitList.push(i);
        }
    }
    if(ponitList.length==0){
        tempList=[-1,-1];
    }else{
        tempList=[ponitList[0],ponitList[ponitList.length-1]]
    }
    return tempList
};
```