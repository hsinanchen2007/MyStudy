### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/c3a7c76ff9a9ae6d3ef92d74ccf7cfd3c727f7517f5444c32c3aa1ca0f33c2b6-image.png)


### 代码

```java
class Solution {
    public int multiply(int A, int B) {
        return getSum(A, B);
    }
    private int getSum(int A, int count) {
        if (count == 0) {
            return 0;
        }
        return A + getSum(A, count-1);
    }
}
```