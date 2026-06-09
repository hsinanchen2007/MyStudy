// 🙋🙋我来了~~ 最近这几天非常忙，leetcode和公众号的消息不能及时回复见谅！我会抽空一条条回复的！现在先来打卡啦~

// 这道题目其实出得有点恶心，需要比较仔细才可以通过。当然比这题更恶心的是要需要识别科学计数法，识别二进制(0b01)，八进制（012)，十六进制（0xab），不知道leetcode会不会丧心病狂出这样的题目（或者已经有了？）。。

// 这题的做法大概是这样：
// 1. 去掉前导空格
// 2. 再是处理正负号
// 3. 识别数字，注意越界情况。

// 这道题目如果只是简单地字符串转整数的话，就是简单地 `ans = ans * 10 + digit`。
// 但是注意这道题目可能会超过integer的最大表示！
// 也就是说会在某一步 `ans * 10 + digit > Integer.MAX_VALUE`。
// `*10` 和 `+digit` 都有可能越界，那么只要把这些都移到右边去就可以了。
// `ans > (Integer.MAX_VALUE - digit) / 10` 就是越界。

// 不过我的忠告是，等真正工作以后，尽可能地调用jdk的方法，比如`Character.isDigit`。如果没有你想要的api，也要尽量使用guava，apache common等常见的utils包，尽量不要自己造轮子，一是这样减少出错的可能，二是比较无脑，保护脑细胞~

// 下面是代码：

// ```java
public class Solution {
    public int myAtoi(String str) {
        char[] chars = str.toCharArray();
        int n = chars.length;
        int idx = 0;
        while (idx < n && chars[idx] == ' ') {
            // 去掉前导空格
            idx++;
        }
        if (idx == n) {
            //去掉前导空格以后到了末尾了
            return 0;
        }
        boolean negative = false;
        if (chars[idx] == '-') {
            //遇到负号
            negative = true;
            idx++;
        } else if (chars[idx] == '+') {
            // 遇到正号
            idx++;
        } else if (!Character.isDigit(chars[idx])) {
            // 其他符号
            return 0;
        }
        int ans = 0;
        while (idx < n && Character.isDigit(chars[idx])) {
            int digit = chars[idx] - '0';
            if (ans > (Integer.MAX_VALUE - digit) / 10) {
                // 本来应该是 ans * 10 + digit > Integer.MAX_VALUE
                // 但是 *10 和 + digit 都有可能越界，所有都移动到右边去就可以了。
                return negative? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            ans = ans * 10 + digit;
            idx++;
        }
        return negative? -ans : ans;
    }
}
// ```

// 以上谢谢大家，求赞求赞求赞！

// ❤️大佬们随手关注下我的wx公众号【[甜姨的奇妙冒险](https://pic.leetcode-cn.com/304599b006dd41bcf2042715f31a2dc4fbdc4cf9748a11a81d8978ea1e839956-wxgzh.jpeg)】和 知乎专栏【[甜姨的力扣题解](https://zhuanlan.zhihu.com/c_1224355183452614656)】 
// 更多题解干货等你来～～