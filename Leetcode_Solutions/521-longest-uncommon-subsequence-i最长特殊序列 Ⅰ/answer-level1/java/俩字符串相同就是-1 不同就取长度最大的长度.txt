![image.png](https://pic.leetcode-cn.com/e149ff3d427e9d36b28b3c73ccbac86d1ddef90bd2dad93efe14228fe95f37e5-image.png)
```
class Solution {
    public int findLUSlength(String a, String b) {

        if(a.equals(b)) return -1;
        return Math.max(a.length(), b.length());   
    }
}
```
