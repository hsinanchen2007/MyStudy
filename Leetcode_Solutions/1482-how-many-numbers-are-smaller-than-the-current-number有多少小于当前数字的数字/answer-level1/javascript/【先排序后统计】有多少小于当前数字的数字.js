### 解题思路
先排序，然后计算每一个元素之前有几个元素，整体时间复杂度是排序最慢O(nlogn)
但是需要新的数组来存储排序后的数据（为了不改变原数组），O(n)
并且需要一个hash来存储结果映射O(n)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    //排序
    numsNew=nums.slice(0)
    numsNew.sort((x,y)=>x-y)
    //将结果记录在hash中
    let r={}  // key:[num,sNum]
    let temp=0;//记录前一个节点
    numsNew.forEach(obj=>{
        if(!(obj in r)) r[obj]=temp
        temp++;
    })
    //不改变原数组的情况下，需要映射
    return nums.map(x=>r[x])
};
```