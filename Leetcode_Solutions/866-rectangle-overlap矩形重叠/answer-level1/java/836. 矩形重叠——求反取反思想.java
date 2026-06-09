
![image.png](https://pic.leetcode-cn.com/86737bea1366ecca7674bd9ad5b1f671a635682032afbb0cda7b15a80c3a5453-image.png)
# 解题思路
正着求比较难，即求重叠的情况有很多种。如果求非重叠的情况，最后取反就一样会得出结果。


![image.png](https://pic.leetcode-cn.com/7fbf555274949bda7163d1ab8bdcd7f79d210baf350f76e1bb90f0a1b1a1c8d2-image.png)


```java
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        
        return !(rec1[0]>=rec2[2]||
        rec1[1]>=rec2[3]||
        rec1[2]<=rec2[0]||
        rec1[3]<=rec2[1]);
    }
}
```



