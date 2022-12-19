### 解题思路
用map来解决这道题目，通过一遍map，将所有出现元素和他们出现的次数进行存储，因为map的唯一性，然后对其进行一次遍历，找出最大值，第一次map操作时间复杂度为o(1),第二次而o(n),所以总体加起来为O(n);
但是由于开辟了一个map空间，空间复杂度同样是o(n)
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let myMap = new Map();
    nums.map(item =>  {
        if(myMap.has(item)){
            myMap.set(item, myMap.get(item)+1)
        }else{
            myMap.set(item, 1);
        }
    })
    let majority = 0;
    let maxItem = 0;
    console.log(myMap);
    for ( let [key, value] of myMap){
        if(value > majority){
            majority = value;
            maxItem = key;
        }
    }
    return maxItem;
};
```
