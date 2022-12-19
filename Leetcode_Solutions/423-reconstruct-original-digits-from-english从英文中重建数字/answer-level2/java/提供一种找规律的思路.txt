首先，列出0-9所有数字的英文，分别为：zero,one,two,three,four,five,six,seven,eight,nine

（1）寻找只出现一次的字母：**z,w,u,x,g**。确定 **0，2，4，6，8** 的数量；
（2）除去 0，2，4，6，8 所涵盖的字母后，接下来可以确定数量的唯一字母有：**r,f,s**。确定 **3，5，7** 的数量；
（3）除去 3，5，7 所涵盖的字母后，**o**的数量唯一确定数字 **1** 的个数；
（4）除去 1 所涵盖的字母后，**e 或者 i** 的数量唯一确定数字 **9** 的个数。

之后进行字符串的连接操作即可。


```
class Solution {
    public String originalDigits(String s) {
        char[] str = new char[26];
        char[] check = s.toCharArray();
        for(int i = 0;i < check.length;i++){
            str[check[i] - 'a']++;
        }
        int zero = 0,one = 0,two = 0,three = 0,four = 0,five = 0,six = 0,seven = 0,eight = 0,nine = 0;
        zero = str[25];
        str[4] -= str[25];
        str[17] -= str[25];
        str[14] -= str[25]; 
        two = str[22];
        str[19] -= str[22];
        str[14] -= str[22];
        four = str[20];
        str[5] -= str[20];
        str[14] -= str[20];
        str[17] -= str[20];
        six = str[23];
        str[18] -= str[23];
        str[8] -= str[23];
        eight = str[6];
        str[4] -= str[6];
        str[8] -= str[6];
        str[7] -= str[6];
        str[19] -= str[6];
        three = str[17];
        str[19] -= str[17];
        str[7] -= str[17];
        str[4] -= str[17];
        str[4] -= str[17];
        five = str[5];
        str[8] -= str[5];
        str[21] -= str[5];
        str[4] -= str[5];
        seven = str[21];
        str[17] -= str[21];
        str[4] -= str[21];
        str[4] -= str[21];
        str[13] -= str[21];
        one = str[14];
        str[13] -= str[14];
        str[4] -= str[14];
        nine = str[4];
        // 上述为数字判断的处理过程
        // 下述为字符串连接过程
        int[] num = new int[]{zero,one,two,three,four,five,six,seven,eight,nine};
        String ans = "";
        for(int i = 0;i < num.length;i++){
            for(int j = 0;j < num[i];j++){
                ans += String.valueOf(i);
            }
        }
        return ans;
    }
}
```
