### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) {
                       char[] haystackArr=haystack.toCharArray();
            char[] needleArr=needle.toCharArray();

            if(needle.equals("")) return 0;

            int count=0;
            int extent = needleArr.length;

            for (int i = 0 ; i<haystackArr.length; i++ ){
                if(haystackArr[i]==needleArr[count]){
                    count++;
                    if(count==needleArr.length){
                        return i-count+1;
                    }
                }else {
                   if(count>=1){
                        i-=count-1;
                    }
                    count=0;
                    if(haystackArr[i]==needleArr[0]){
                        count=1; 
                    }
                }
            }
            return -1;
    }
    }

```