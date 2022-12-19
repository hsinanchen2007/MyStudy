### 方法1
记录遇到的1，遇到0则选取前面比较大的数
![image.png](https://pic.leetcode-cn.com/f596981cbcd88552aabc839de3316c31989fc202b6dacffd6afa36bd8b636133-image.png)

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let max = 0;
    let tmpMax = 0; // 遇到0之前的连续的1的个数
    for(let i=0; i<nums.length; i++){
        if(nums[i]==1) tmpMax++;
        else{
            max = Math.max(max,tmpMax);
            tmpMax=0;
        }
    }
    return Math.max(max,tmpMax);
};
```
### 方法二
将数组从0处分割，对比哪个元素的长度比较长
![image.png](https://pic.leetcode-cn.com/a59b63b22fcf6c381ea7fa800d5869aa012cde8fee6366d6eb6ac98fd4f8c9ba-image.png)

```javascript
var findMaxConsecutiveOnes = function(nums) {
    let arr = nums.join('').split('0');
    let max = 0;
    for(let i=0;i<arr.length;i++){
        if(arr[i].length > max) max = arr[i].length;
    }
    return max;
};
```

