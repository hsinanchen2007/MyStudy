### 解题思路
![屏幕快照 2020-02-12 13.50.44.png](https://pic.leetcode-cn.com/be708161a71c7e659dc26e8d9a233750f60b795244090552efa158245a7805e2-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-12%2013.50.44.png)


### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        char[] Jrr = J.toCharArray();
        char[] Srr = S.toCharArray();
        Arrays.sort(Jrr);
        Arrays.sort(Srr);
        int jindex = 0,sindex = 0,res = 0;
        while (jindex < Jrr.length && sindex < Srr.length) {
            int j = (int)Jrr[jindex];
            int s = (int)Srr[sindex];
            if (j < s) {
                jindex++;
            } else if (j > s) {
                sindex++;
            } else {
                res++;
                sindex++;
            }
        }
        return res;
    }
}
```