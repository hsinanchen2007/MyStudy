## 解题方案

### 思路

- 标签：字符串遍历，进制转换
- 初始化结果`ans = 0`，遍历时将每个字母与A做减法，因为A表示1，所以减法后需要每个数加1，计算其代表的数值`num = 字母 - ‘A’ + 1`
- 因为有26个字母，所以相当于26进制，每26个数则向前进一位
- 所以每遍历一位则`ans = ans * 26 + num`
- 以ZY为例，Z的值为26，Y的值为25，则结果为`26 * 26 + 25=701`
- 时间复杂度：O(n)


### 代码

```java
class Solution {
    public int titleToNumber(String s) {
        int ans = 0;
        for(int i=0;i<s.length();i++) {
            int num = s.charAt(i) - 'A' + 1;
            ans = ans * 26 + num;
        }
        return ans;
    }
}
```

### 画解

<![frame_00001.png](https://pic.leetcode-cn.com/97416a122f3315e3a0eb9951a1d742e7c1734d915f4b96099610a92629899d04-frame_00001.png),![frame_00002.png](https://pic.leetcode-cn.com/a5e8e39fa19491e3e1d82c6aba3dec24e080c368d0400bf57012548b0fdb2af4-frame_00002.png),![frame_00003.png](https://pic.leetcode-cn.com/da62003ebc140532fe1e42ff2c46d5c920101d6de50fd3c6910eee1e9d9c7df5-frame_00003.png),![frame_00004.png](https://pic.leetcode-cn.com/4267220aeef6e659dcae4fa7b59d63c68efdb7b0f748d431d8acca4af278de65-frame_00004.png)>

点击我的头像加关注，和我一起打卡天天算法