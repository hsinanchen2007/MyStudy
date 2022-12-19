由于这道题只需要知道当前字符有没有在字符串中有没有出现过，若出现过能返回下标。因此这里可以用一个对象`map`来维护之前已经出现过的字符下标，可以通过双指针来模拟窗口滑动边界。这里分为两种情况：
+ 若出现过，`left`的指针需要移到之前已经出现的下标+1，即`left = map[ char ] + 1`。并更新当前字符的下标。
+ 若未出现，计算最大值`max`，并记录当前字符的下标。
最后返回max即可。

```javascript
var lengthOfLongestSubstring = function(s) {
    let map = {};
    let max = 0;
    let left = 0;
    let right = 0;
    while (right < s.length) {
        const item = s[right];
        if (map[ item ] >= 0 && map[ item ] >= left) {
            left = map[ item ] + 1;
            map[ item ] = right;
        } else {
            map[ item ] = right;
            max = Math.max(right - left + 1, max);
        }
        right++;
    }
    return max;
};
```
