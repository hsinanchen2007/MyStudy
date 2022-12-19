#### 思路一
用一个指针`j`指向非0的数字位置，遍历`nums`，将非0数字从`j`为0开始依次填写，最后将剩余位置填`0`即可。
#### 代码
```
var moveZeroes = function(nums) {
    let j = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            nums[j] = nums[i];
            j++;
        }
    }
    for (let i = j; i < nums.length; i++) {
        nums[i] = 0;
    }
};
```
优化，将`nums[j]`和不为零的数交换位置：
```
var moveZeroes = function(nums) {
    let j = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== 0) {
            let temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            j++;
        }
    }
};
```
#### 思路二
遍历`nums`，遇到为0的数，将其删除，然后在最后添加一个0，重置下标，继续从当前位置开始判断。
```
var moveZeroes = function(nums) {
    let j = 0;
    for (let i = 0; i < nums.length; i++) {
        if (j++ < nums.length) {
            if (nums[i] === 0) {
                nums.splice(i, 1);
                nums.push(0);
                i--;
            }
        }
    }
};
```
*引入变量j的原因：因为会重置下标i，当出现[1,0,0]类似的情况，会出现死循环，j控制次数，避免死循环*

