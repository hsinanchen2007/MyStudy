### 解题思路
暴力解法
![1111.png](https://pic.leetcode-cn.com/441d665eeb4c4861691c5983d8ce9cdcd29f620f17b6e4357035a00f1d11425f-1111.png)
1.分别统计每个单词每个字母的出现顺序
2.出现次数差值和的值即为所求(其实不必记录两个值，一个值就行了，因为字符串一样长)
### 代码

```java
class Solution {
    public int minSteps(String s, String t) {
        int [] S=new int[26];
        int [] T=new int[26];
        for (int i=0;i<s.length();i++){
            S[s.charAt(i)-'a']++;
        }
        for (int i=0;i<t.length();i++){
            T[t.charAt(i)-'a']++;
        }
        int ss=0,tt=0;
        for (int i=0;i<26;i++){
            if (S[i]>T[i])
                ss+=S[i]-T[i];
            else
                tt+=T[i]-S[i];
        }
        return Math.min(ss,tt);
    }
}
```