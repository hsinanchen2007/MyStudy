### 说在前面
本题和题目136.只出现一次的数字的本质思想是相同的。通过对比两题的题意，可以发现两题都是需要找一个元素（数字or字符），这个元素的特点是：**它只出现过一次，而其他元素均出现两次**。本题中t是重新排列后添加了一个字母，因此这个字母就是只出现一次的元素，而其他字母都出现过两次（字符串s中一次，t一次）。由此，得到的一下三种解法实质上和136的三种解法是一模一样的。

### 解法一：哈希表
执行用时：3ms
内存消耗:35.9MB

哈希表是比较容易想到的方法，用一个哈希表记录每个元素出现的次数，由于只有26个字母，因此哈希表大小26足以（a对应下标0，b对应下标1，以此类推）。对s中每个字符，出现一次则在哈希表中次数加一；对t中的每个字符，若在s中也有，则哈希表中记录的次数为1，而多出来的那个字母，哈希表记录为0，这就是答案。

时间复杂度:O(n)。需要遍历两个字符串。
空间复杂度:O(1)。只有26个字母，哈希表大小为26。

代码

```java
class Solution {
    public char findTheDifference(String s, String t) {
        int[] hash = new int[26];
        for(int i = 0; i < s.length(); i++)
            hash[s.charAt(i) - 'a']++;
        int i;
        for(i = 0; i < t.length(); i++)
        {
            int index = t.charAt(i) - 'a';
            if(hash[index] == 0)    break;
            else                    hash[index]--; 
        }
        return t.charAt(i);
    }
}
```

### 解法二：ASCII码运算
执行用时：1ms
内存消耗：35.8MB

由于t中除了一个多余的字符外，其余字符和s中一样。则可以联想，两个字符串中所有字符的ASCII值之和相差的数就是多余字符的ASCII值。

时间复杂度：O(n)。
空间复杂度：O(1)。

代码：
```java
class Solution {
    public char findTheDifference(String s, String t) {
        int sum1 = 0, sum2 = 0;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            sum1 += s.charAt(i);
            sum2 += t.charAt(i);
        }
        sum2 += t.charAt(len);
        return (char)(sum2 - sum1);
    }
}
```

### 解法三：位运算--按位异或
执行用时：1ms
内存消耗：35.9MB

除了一个元素只出现一次以外，其余所有元素均出现两次，联想按位异或(XOR)。通俗地说，按位异或就是对二进制的每一位进行不进位的加法、不借位的减法，对位进行异或操作。
0 ^ 0 = 0
0 ^ 1 = 1
1 ^ 0 = 1
1 ^ 1 = 0
**任何非零数和零异或还是原数。两个相同的数异或为零。**
由此，如果对s和t中的每一个字符（的ASCII码）异或，则s和t中都有的字符得到的异或结果为零，零和多余的那个字符异或，结果就是那个多余的字符（的ASCII码）。转换为char输出即可。

时间复杂度：O(n)。
空间复杂度：O(1)。

代码：
```java
class Solution {
    public char findTheDifference(String s, String t) {
        int ans = 0;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            ans = ans ^ s.charAt(i);
            ans = ans ^ t.charAt(i);
        }
        ans = ans ^ t.charAt(len);
        return (char)(ans);
    }
}
```