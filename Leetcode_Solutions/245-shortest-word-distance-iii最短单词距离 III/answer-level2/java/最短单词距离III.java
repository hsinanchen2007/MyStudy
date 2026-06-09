### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int shortestWordDistance(String[] words, String word1, String word2) {
        int len=words.length;
        int s1=-1,s2=-1;
        int min=Integer.MAX_VALUE;
        for(int i=0;i<len;i++)
        {
            if(words[i].equals(word1))
            {
                s1=i;
                if(s2!=-1)
                    min=Math.min(min,s1-s2);
            }
            if(words[i].equals(word2))
            {
                s2=i;
                if(s1!=-1&&s1!=s2)
                    min=Math.min(min,s2-s1);
            }
        }
        return min;
    }
}
```