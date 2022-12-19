### 解题思路
这个题目实际只要找到一个有重复的元素就找到了答案。
我们观察可以轻松得出，一定存在一个3个元素的子串，其中至少有两个元素相等，比较得到相等的元素就得到答案。

![image.png](https://pic.leetcode-cn.com/8cf46c6c728c0ec0c19e2b15de9dab78b1c8087a00913218b3e277bca81f5972-image.png)

### 代码

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        for (int i = 2; i < A.length; i++) {
            if (A[i] == A[i - 1] || A[i] == A[i - 2]) return A[i];
            if (A[i - 1] == A[i - 2]) return A[i - 1];
        }
        return A[0];
    }
}
```