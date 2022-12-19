### 解题思路
![image.png](https://pic.leetcode-cn.com/af32e2480ad431e8ab468a31a24e7c60966f87be393804a482d6d4c37d000487-image.png)

速度空间和set大法差不多啊。


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let i = 1;
    let j = 1;
    let tmp = nums[0];

    while (i < nums.length) {
        if (nums[i] != tmp) {
            nums[j] = nums[i];
            tmp = nums[i];
            j++
        }
        i++;
    }
    return j;
};
```