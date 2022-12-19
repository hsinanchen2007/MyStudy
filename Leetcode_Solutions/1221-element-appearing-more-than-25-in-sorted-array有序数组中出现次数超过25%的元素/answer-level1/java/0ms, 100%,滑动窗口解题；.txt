### 解题思路
![屏幕快照 2020-02-28 19.51.54.png](https://pic.leetcode-cn.com/8c26899cf2d90ff9d546da3a9d24b76ebff744046fc5a459b8ab70727037a654-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-28%2019.51.54.png)


### 代码

```java
class Solution {
    public int findSpecialInteger(int[] arr) {
        // 滑动窗口解题
        int r = 0, l = arr.length / 4;
        while (l < arr.length) {
            if (arr[r] == arr[l]) {
                return arr[r];
            }
            r++;
            l++;
        }
        return -1;
    }
}
```