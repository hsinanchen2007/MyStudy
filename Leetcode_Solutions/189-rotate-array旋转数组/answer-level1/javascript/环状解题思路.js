### 解题思路
概述：环状解题思路每次取出一个数，将它放置最终的位置上，循环执行。每一个元素只遍历一次，时间复杂度是O(n)。首先将数组看成环状数组,元素长度为l，每一个元素最终的位置即在自身位置(i+k)%l上。发现每一次循环元素会回到原来出发的位置，因此需要接着从下一个元素开始。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    let i = 0,j=0;
    k%=nums.length;
    while(i<nums.length){
        let a = j;
        let innum = nums[a]; // 取出待插入的值
        do{
            let b = (a+k)%nums.length;
            let temp = nums[b];
            nums[b] = innum; // 将待插入的值放置最终位置
            innum = temp;
            i++; 
            a=b;    
        }while(a!==j && i<nums.length)
        j++;
    }
};
```