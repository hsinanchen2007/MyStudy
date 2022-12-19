### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()==1){
            return 1;
        }
       int len=s.length();
        int max=0;
        String resultS="";
        int result=0;
        for(int i=0;i<len;i++){
            int j=i+1;
            char first=s.charAt(i);
            resultS=resultS+first;
            for(;j<len;j++){
                char last=s.charAt(j);
                if(resultS.contains(String.valueOf(last))){
                    int le=resultS.length();
                    if(le>=result){
                        result=le;
                    }
                    resultS="";
                    break;
                }
                resultS=resultS+last;
                int le=resultS.length();
                if(le>result){
                    result=le;
                }
                if(j==len-1){
                    resultS="";
                }


            }
        }
        return result;
        }
    }
```