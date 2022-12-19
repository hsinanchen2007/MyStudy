本题写于2019年七夕，祝大家七夕快乐，送一道521给你们。

## 解题方案

### 思路

- 标签：题意理解，本题题意难于理解
- **独有**指的是只有自己有，另一个字符串没有
- 举例说明，设两个字符串变量名分别为 `a` 和 `b`
  - `a = 'c', b = 'cd'`，`'cd'` 是 `a` 独有的，所以最长子序列为 `'cd'`，长度为 2
  - `a = 'cd', b = 'cd'`, `'cd', 'c', 'd'` 在两个字符串中都有，所以不存在独有的最长子序列，返回 -1
- 通过举例分析，得出以下结论：
  - 如果两个字符串长度不一样，则较长的字符串**本身**不可能是短字符串的子序列，直接返回其长度即可
  - 如果两个字符串内容相等，那么他们独有的最长子序列不存在，返回 -1


### 代码



```Java []
class Solution {
    public int findLUSlength(String a, String b) {
        if(a.equals(b))
            return -1;
        return a.length() > b.length() ? a.length() : b.length();
    }
}
```



```JavaScript []
/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */
var findLUSlength = function(a, b) {
    if(a === b)
        return -1;
    return a.length > b.length ? a.length : b.length;
};
```


### 画解

<![1.png](https://pic.leetcode-cn.com/e3aa1de6587d7998444b29e472e744a848ceaed30affb479b04f2335f7e335c2-1.png),![2.png](https://pic.leetcode-cn.com/c27d33ea84eeec9ab34dd74bb3f7abd02938290d9b7406457bfc15edccbc3280-2.png),![3.png](https://pic.leetcode-cn.com/587194fb25041de88f08ac58bdb36e2e9ee6f8fa929bd8554c3136d8fdf4d377-3.png)>

