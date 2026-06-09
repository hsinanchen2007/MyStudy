![image.png](https://pic.leetcode-cn.com/8d8c60fc6914fee9618780754a06cb0aea74265737b5e367508cd3be84ed89d7-image.png)
```
class Solution {
        public int findLUSlength(String a, String b) {
            if (a.equals(b))
                return -1;
            else return Math.max(a.length(),b.length());
        }
    }
```
