1. 如果数组长度为1，那么直接返回数组唯一项。 
2. 如果数组长度为2，那么返回“第1项”和“第2项”的较大者。 
3. 如果数组长度为3，那么返回“数组长度为1的结果+第3项”与“数组长度为2的结果”的较大者。 
4. 如果数组长度为4，那么返回“数组长度为2的结果+第4项”与“数组长度为3的结果”的较大者。 
5. …… 
6. 如果数组长度为n，那么返回“数组长度为n-2的结果+第n项”与“数组长度为n-1的结果”的较大者。

```js
var rob = function(nums) {
    const len = nums.length;
    if (len == 0) {
        return 0
    }
    let arr = new Array(len + 1);
    arr[0] = 0;
    arr[1] = nums[0];
    for(let i = 2; i <= len; i++) {
        arr[i] = Math.max(arr[i-1], arr[i-2] + nums[i-1])
    }
    return arr[len]
};
```