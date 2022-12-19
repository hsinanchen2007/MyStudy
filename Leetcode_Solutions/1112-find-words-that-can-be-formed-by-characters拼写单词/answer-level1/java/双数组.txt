### 解题思路
用一个数组count2保存每个字符出现的字数，每次循环之后都从这个数组恢复。
另一个数组count则是计数，每次遇到一个字母，次数减一。若单词某个字母次数为0，则该单词未被掌握，跳过该单词剩余部分。（每次检查完一个单词之后记得从count2恢复字母次数。）
### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[]count=new int[26];       
        int[]count2=new int[26];
        for(int i=0;i<chars.length();i++)
        {
            count[chars.charAt(i)-'a']++;
            count2[chars.charAt(i)-'a']++;
        }
        int ans=0;
        for(int i=0;i<words.length;i++)
        {
            String t=words[i];
            int j=0;
            for(;j<t.length();j++)
            {
                if(count[t.charAt(j)-'a']==0)
                {break;}
                else
                {
                    count[t.charAt(j)-'a']--;
                }
            }
            if(j==t.length())
            {ans+=t.length();}
            for(j=0;j<26;j++)
            {
                count[j]=count2[j];
            }
        }
        return ans;
    }
}
```