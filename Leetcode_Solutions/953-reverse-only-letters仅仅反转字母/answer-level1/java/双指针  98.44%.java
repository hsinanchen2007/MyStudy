![image.png](https://pic.leetcode-cn.com/3878f2e3d43ac7309e9fb98d70e725b630fe41b1efeb48ed4e6e408b15b2bf92-image.png)

```
class Solution {
        public String reverseOnlyLetters(String S) {
            char[] chars = S.toCharArray();
            int i=0,j=chars.length-1;
            while (i<j){
                while (i<j && !(chars[i]<='Z' && chars[i]>='A' || chars[i]<='z' && chars[i]>='a'))
                    i++;
                while (i<j && !(chars[j]<='Z' && chars[j]>='A' || chars[j]<='z' && chars[j]>='a'))
                    j--;
                if(i<j){
                    char temp=chars[i];
                    chars[i]=chars[j];
                    chars[j] = temp;
                }
                i++;
                j--;
            }
            return new String(chars);
        }
    }
```
