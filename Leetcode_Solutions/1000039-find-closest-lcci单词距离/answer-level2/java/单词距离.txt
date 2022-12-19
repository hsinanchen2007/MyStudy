### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int findClosest(String[] words, String word1, String word2) {
        //一次遍历
        int res=Integer.MAX_VALUE;
        int index1=-1,index2=-1;
        for(int i=0;i<words.length;i++){
            if(words[i].equals(word1)){
                index1=i;
                if(index2!=-1)
                    res=Math.min(res,Math.abs(index2-index1));
            }
            if(words[i].equals(word2)){
                index2=i;
                if(index1!=-1)
                    res=Math.min(res,Math.abs(index2-index1));
            }
        }
        return res;
    }
}
```