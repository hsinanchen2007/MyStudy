### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numMatchingSubseq(String S, String[] words) {
        int number=0;
        if(S.length()==0||words.length==0)
        return 0;
        for(int i=0;i<words.length;i++){
             int j=0;
                for(int k=0;k<S.length();k++){
                    if(words[i].charAt(j)==S.charAt(k)){
                        j++;
                    }
                    if(j==words[i].length()){
                     number++;
                     break;
                    }
                }   
        }
        return number;
    }
}
```