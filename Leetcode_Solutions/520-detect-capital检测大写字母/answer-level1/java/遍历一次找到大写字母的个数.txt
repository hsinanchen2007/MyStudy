![image.png](https://pic.leetcode-cn.com/c0fc258ce89a3600bac1bf13ec4778d1343dcc65bc9cfaf8a2e6b49c28dbd553-image.png)
```
class Solution {
        public boolean detectCapitalUse(String word) {
            if (word==null)
                return false;
            if (word.length()<2)
                return true;
            int cnt=0;
            for (int i = 0; i <word.length() ; i++) {
                if (word.charAt(i)<='Z' && word.charAt(i)>='A')
                    cnt++;
            }
            if (cnt==0||cnt==word.length())
                return true;
            else if (cnt==1 && word.charAt(0)<='Z' && word.charAt(0)>='A')
                return true;
            else return false;
        }
    }
```
