### 解题思路
此处撰写解题思路

### 代码

* 第一次，这里第二次循环没有注意越界了
```javascript
7052 ms	36.3 MB
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    // 距离为k之间有没有相同的元素
    let i,j
    for(i = 0; i < nums.length;i++){
        let num = nums[i]
        for(j=i+1;j<=i+k;j++){
            if(num == nums[j]){
                return true
            }
        }
    }
    return false
};
```
* 第二次，修改了越界，速度快了很多
```javascript
1548 ms	36.3 MB
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
     // 距离为k之间有没有相同的元素
    let i,j,t
    for(i = 0; i < nums.length;i++){
        let num = nums[i]
        t = (i+k+1)>nums.length?nums.length:(i+k+1)
        for(j=i+1;j<t;j++){
            if(num == nums[j]){
                return true
            }
        }
    }
    return false
};
```