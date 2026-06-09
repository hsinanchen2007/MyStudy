### 解题思路
* 通过Map（）数据结构，通过循环得到值的最大频率；
* 两次次数相等之时，既可以计算最小数组长度, 

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findShortestSubArray = function(nums) {
//     通过Map数据结构找次数最大的值
    let map = new Map(), size = 1, len = nums.length

    for (let n of nums){
        map.set(n, map.has(n) ? map.get(n) + 1 : 1)
        size = Math.max(size, map.get(n))
    }
    
    let polo = new Map()
    // 这里循环的末尾要用nums.length
    for (let i = 0; i < nums.length; i++){
        let cur = nums[i]
        polo.set(cur, polo.has(cur) ? polo.get(cur) + 1 : 1)
        if(polo.get(cur) == size){
            let start = nums.indexOf(cur)
            // i-start +1 得到长度
            len = Math.min(len, i - start + 1);
        }
    }
   return len
};


```