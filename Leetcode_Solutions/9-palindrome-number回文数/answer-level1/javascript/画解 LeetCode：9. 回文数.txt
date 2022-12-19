## 数学方式

![frame_00001.png](https://pic.leetcode-cn.com/f205f3862c28c799aba80678d2c54c7b6be587fc57fef4de38d597ffc8c44f7f.jpg)

### 思路

* 标签：` 数学 `
* 如果 x 为负数，x 肯定不是回文数
* **从两头向中间依次比较左数和右数是否相等**：比较最高位和最低位，比较之后，去除最高位和最低位，循环
* 最高位，当前数除以除数，需要先利用循环得到除数：`left = 1234321 / 1000000 = 1`，
* 最低位，取余：`right = x % 10`
* 去除最高位和最低位：`x = 1234321 % 1000000 / 10 = 234321 / 10 = 23432`
* 除数对应变化：`div = 1000000 / 100 = 10000`
* 时间复杂度：O(n)，当为回文数时，循环次数最多：2/n-1（不算循环得到除数的时间），n 为数组的长度。
* 空间复杂度：O(1)，没有利用多余空间

### 代码

```Java []
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0)
            return false;
        int div = 1; // 除数
        while (x / div >= 10)
            div *= 10;
        while (x > 0) {
            int left = x / div;
            int right = x % 10;
            if (left != right)
                return false;
            x = x % div / 10;
            div /= 100;
        }
        return true;
    }
}
```
```JavaScript []
var isPalindrome = function (x) {
    if (x < 0)
        return false;
    let div = 1;
    while (parseInt(x / div) >= 10) {
        div *= 10;
    }
    while (x > 0) {
        let left = parseInt(x / div);
        let right = x % 10;
        if (left !== right) {
            return false;
        }
        x = parseInt(x % div / 10);
        div = parseInt(div / 100);
    }
    return true;
};
```
### 画解

<![frame_00001.png](https://pic.leetcode-cn.com/7a28e247744fe18e0ad1545303bb5e4f11e18ac3c7b7941c14614eae5dfd8c07-file_1566201121459),![frame_00002.png](https://pic.leetcode-cn.com/ce9bcd7168080576fa5faa0561d4734477110ac6f646f5ac6e3b055235e7ece9-file_1566201121469),![frame_00003.png](https://pic.leetcode-cn.com/c62dc2db11706218de52d723bf4e40b0b46fa3a201c4b8ef8abf95ddb056a364-file_1566201121483),![frame_00004.png](https://pic.leetcode-cn.com/3cc83ec168e3cb1b76122598b4f90e7933a63e13803d4a0a1541711f323f29bd-file_1566201121489),![frame_00005.png](https://pic.leetcode-cn.com/0b112e3dd057c061d8b4fd5159249d67aba7abb22a9aa6700c4f98fa0ecd32fa-file_1566201121491)>


### 测试用例
描述 | 1 | 2 | 3 | 4 | 5 
---|---|---|---|---|---
输入 | 0 | 10 | 1001 | 1000021 | 123454321
输出 | true | false |  false | false | true