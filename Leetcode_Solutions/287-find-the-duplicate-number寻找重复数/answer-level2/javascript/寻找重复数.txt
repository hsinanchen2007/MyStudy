### 解题思路
- 思路参考寻找有环链表环起始点
- 数组的值结合index，把链表等效成有环的链表

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    let L = 0, R = 0, LL
    while(true){
        L = nums[L]
        R = nums[nums[R]]
        if(L === R){
            LL = 0
            while(nums[L] !== nums[LL]){
                L = nums[L]
                LL = nums[LL]
            }
            return nums[LL]
        }
    }
};
```