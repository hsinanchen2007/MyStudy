### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int len=words.length;
        int l1=-1, l2=-1;
        int min=Integer.MAX_VALUE;
        for(int i=0;i<len;i++){
            if(words[i].equals(word1))
            {
                l1=i;
                if(l2!=-1)
                    min=Math.min(min,l1-l2);
            }
            else if(words[i].equals(word2)){
                l2=i;
                if(l1!=-1)
                    min=Math.min(min,l2-l1);
            }
        }
        return min;
    }
}
```