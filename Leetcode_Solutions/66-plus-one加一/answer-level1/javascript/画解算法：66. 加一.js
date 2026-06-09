### 思路

- 标签：数组遍历
- 这道题需要整理出来有哪几种情况，在进行处理会更舒服

1. 末位无进位，则末位加一即可，因为末位无进位，前面也不可能产生进位，比如 `45 => 46`
2. 末位有进位，在中间位置进位停止，则需要找到进位的典型标志，即为当前位 $%10$ 后为 0，则前一位加 1，直到不为 0 为止，比如 `499 => 500`
3. 末位有进位，并且一直进位到最前方导致结果多出一位，对于这种情况，需要在第 2 种情况遍历结束的基础上，进行单独处理，比如 `999 => 1000`

- 在下方的 Java 和 JavaScript 代码中，对于第三种情况，对其他位进行了赋值 0 处理，Java 比较 tricky 直接 new 数组即可，JavaScript 则使用了 ES6 语法进行赋值
- 时间复杂度：$O(n)$

### 代码

```Java []
class Solution {
    public int[] plusOne(int[] digits) {
        int len = digits.length;
        for(int i = len - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if(digits[i]!=0)
                return digits;
        }
        digits = new int[len + 1];
        digits[0] = 1;
        return digits;
    }
}
```
```JavaScript []
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    const len = digits.length;
    for(let i = len - 1; i >= 0; i--) {
        digits[i]++;
        digits[i] %= 10;
        if(digits[i]!=0)
            return digits;
    }
    digits = [...Array(len + 1)].map(_=>0);;
    digits[0] = 1;
    return digits;
};
```

### 画解

<![frame_00001.png](https://pic.leetcode-cn.com/97ab9bdf9e483604c1b5e43c5793b9cc4c42cfd2abd33f815f0951bcb7e3b8d4-frame_00001.png),![frame_00002.png](https://pic.leetcode-cn.com/ec953373f01331b191c0403fca784c6ccd41e0b6a3e739affec62d12cfd12883-frame_00002.png),![frame_00003.png](https://pic.leetcode-cn.com/83a8aac8d1e44aed9dec3cf0a31c0e25d1d25cc1aaa170287087f795825da784-frame_00003.png),![frame_00004.png](https://pic.leetcode-cn.com/e4f3a237e82ec70199ccc71d55f896a3cd4c5dd78f1a7e791f3cdb9d1b96f152-frame_00004.png)>
