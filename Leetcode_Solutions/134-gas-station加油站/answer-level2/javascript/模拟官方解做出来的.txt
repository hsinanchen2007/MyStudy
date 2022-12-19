### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} gas
 * @param {number[]} cost
 * @return {number}
 */
var canCompleteCircuit = function(gas, cost) {
    var sum = 0, cur = 0, res = 0, i =0
   while(i<gas.length) {
       sum += gas[i] - cost[i] //（1）记录整体耗油量
       cur += gas[i] - cost[i] // 记录当前路线耗油量
       if (cur<0) { //根据官解当前路线不满足时，则向下查找，若当前路线下cur>0，则根据反证法证明该值正确
           cur = 0
           res = i+1
       } 
       i++
   }
   return sum>=0? res:-1 // 根据（1）若总耗油量为负则没有找到解返回-1
};
```