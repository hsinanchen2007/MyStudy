# 思路
1. 奇偶性思考
    对于出现偶次数的字符，肯定可以构建回文字符串，所以关键在于出现奇次数的字符。再进一步思考，出现3（5、7、、、）次的字符等同于出现1次。
2. 异或位运算
    奇偶性与位运算是等同的效果。
    出现0次 + 出现1次 = 出现1次    ->    0 ^ 1 = 1
    出现1次 + 出现1次 = 出现0次    ->    1 ^ 1 = 0
    可以发现，利用位运算可以巧妙解决奇偶性。由此想到可以利用int字节的低26位来存储26个小写字母出现的奇偶次数。
3. 统计二进制1的个数
    用一个数num的字节位存储了奇偶次数后，接下来就是统计奇数的字符个数。也就等同于统计num的二进制表达中1的个数。可以使用如下巧妙统计小算法。
    
```
int count = 0;
while (num != 0) {
    num &= (num - 1);
    count++;
}
```
4. 判断回文串的可行性
    已经知道出现奇数次字符的个数为count后，只需要与k比较大小，如果小于k，自然是可以构建出对应的回文字符串。

# 实现
```
public boolean canConstruct(String s, int k) {
        int length = s.length();
        if (k > length) {
            return false;
        }
        char[] array = s.toCharArray();
        int index = 0;
        int num = 0;
        for (int i = 0; i < length; i++) {
            index = array[i] - 'a';
            num ^= (1 << index);
        }
        int count = 0;
        while (num != 0) {
            num &= (num - 1);
            count++;
        }
        return count <= k;
    }
```
![1400.PNG](https://pic.leetcode-cn.com/462fe418fe8fc5ffa6e017927c89d3e4ffc14ed82ab9b65fd24761ba6e6344d2-1400.PNG)

