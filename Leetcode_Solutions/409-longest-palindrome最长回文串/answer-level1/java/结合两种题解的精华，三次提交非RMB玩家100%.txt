首先，注意审题！！！
题目中是“通过这些字母构造最长回文串”，而不是在已有的字符串中寻找最长字符串。（第一次看题栽噗噗）

汲取了@Sweetiee 🍬的int[58]、TimesOfeachletter[letter-'A']++;---58精致实用

还汲取了第二个for来自官方题解评论区首位@总有一天丶 
判断思路如下：
*       1.统计出现次数为奇数的字母有多少个，
*       2. return count == 0 ? s.length() : (s.length() - count + 1);
*         如果给出的字符串中的字母要出现的次数全为偶数，那么字符串的长度就是最长回文串的长度
*         又因为“构成回文串，只能出现一个个数为奇数的字符”且有count个字母要出现的次数为奇数
*         那么我们会“保留一次奇数”，其余的奇数次字母，都要“砍”掉一个，砍掉后的其余的再平均分配到对称中心的左右两端

 
```
class Solution {
    public int longestPalindrome(String s) {
        /*
        * 方法一*/
        int[] TimesOfeachletter = new int[58];
        int NumsOfoddTimes = 0;

        for (char letter:s.toCharArray()){
            TimesOfeachletter[letter-'A']++;
        }

        for (int lettertimes:TimesOfeachletter){
            NumsOfoddTimes+=(lettertimes%2);
        }

        return NumsOfoddTimes==0? s.length():(s.length()-NumsOfoddTimes+1);
    }
    /*
     * 两次提交，耗时1 ms左右（100%），使用内存37.8M（5.25%）*/
}
```

萌新首答，感谢题解区各位的帮助
