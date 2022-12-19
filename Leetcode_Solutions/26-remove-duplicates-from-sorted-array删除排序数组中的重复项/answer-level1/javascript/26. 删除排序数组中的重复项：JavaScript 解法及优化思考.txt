## 双指针解法

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let i = 0;
    for (let j = 1; j < nums.length; j++)
        if (nums[j] != nums[j-1]) {
            nums[++i] = nums[j];
        }
    return i + 1;
};
```

**复杂度分析：**

- 时间复杂度：O(n)
- 空间复杂度：O(1)


## 优化思考

使用上面的解法，如果相邻的两个数组元素不相等，那么指针 `i` 所指向的数组元素也会被原地进行一次复制。这个操作其实没必要。那么我们可以通过增加一个判断条件，如果 `j - i > 1` 再进行元素的复制，如果 `i` 和 `j` 所指向的是两个相邻且不相等的元素，则没必要进行复制。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let i = 0;
    for (let j = 1; j < nums.length; j++)
        if (nums[j] != nums[j-1]) {
            if(j - i > 1) {
                nums[i + 1] = nums[j];
            }
            i++;
        }
    return i + 1;
};
```

我们再看看上面这段代码，虽然避免了复制的操作，但是增加了一次减法计算和数值大小判断。所以并算不上优化，可能计算上还更加耗时。

**复杂度分析：**

- 时间复杂度：O(n)
- 空间复杂度：O(1)

---

**更多题解请关注**：[https://github.com/leviding/leetcode-js-leviding](https://github.com/leviding/leetcode-js-leviding)
