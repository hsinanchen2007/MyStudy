![image.png](https://pic.leetcode-cn.com/c562214d29243fb27d94e16ccf4f2a155a5d002bc2f7c29606895a9d2d3fee15-image.png)
```
class Solution {
        public void reverseString(char[] s) {
            if (s.length<2)
                return;
            int i=0,j=s.length-1;
            while (i<j){
                char temp = s[i];
                s[i] = s[j];
                s[j]= temp;
                i++;
                j--;
            }
            return;
        }
    }
```
