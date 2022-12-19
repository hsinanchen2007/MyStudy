### 解题思路

![6DF7FD3E466E1C106743A7467CA4B4DD.png](https://pic.leetcode-cn.com/91e8dca68fea03dce450b6a2457f81814e8037aa5e52834b44aaa93c3b0f1407-6DF7FD3E466E1C106743A7467CA4B4DD.png)


### 代码

```java
class Solution {
    public int countSegments(String s) {
        int segmentCount = 0;
        for (int i = 0; i < s.length(); i++) {
            if ((i == 0 || s.charAt(i-1) == ' ') && s.charAt(i) != ' ') {
                segmentCount++;
            }
        }
        return segmentCount;
    }
}
```