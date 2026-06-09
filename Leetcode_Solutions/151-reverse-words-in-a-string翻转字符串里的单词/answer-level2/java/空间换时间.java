### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
        /**
         * "the sky is blue"
         * */
        public String reverseWords(String str) {
            int end = str.length() - 1, begin = str.length() - 1, index = 0, k;
            char[] chars = str.toCharArray(), ans = new char[str.length()];
            while (begin >= 0){
                while(begin >= 0 && chars[begin] != ' '){
                    begin--;
                }
                k = (begin == 0 && chars[begin] != ' ') ? begin : begin + 1;
                if(index != 0 && end >= k){
                    ans[index++] = ' ';
                }
                for(; k <= end; k++){
                    ans[index++] = chars[k];
                }

                while(begin >= 0 && chars[begin] == ' '){
                    begin--;
                }
                end = begin;
            }
            return new String(ans,0,index);
        }
    }
```