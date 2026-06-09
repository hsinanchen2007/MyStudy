
```Java []
class Solution {
    public int numJewelsInStones(String J, String S) {
       char[] s = S.toCharArray();
        int count = 0;
        for (char c : s) {
            if (J.indexOf(c)>=0)count++;
        }
        return count;
    }
}
```


![image.png](https://pic.leetcode-cn.com/8b997aada65664ce34fc1f47867d64dbcc7ae1fe4d5a118d89f5028e72322b07-image.png)
