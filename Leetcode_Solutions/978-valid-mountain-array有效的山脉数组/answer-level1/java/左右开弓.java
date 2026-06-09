### 解题思路
1. 从左边遍历找出第一个最大值返回索引
2. 从右边遍历找出第一个最大值返回索引
3. 比较连个索引是否相等
![image.png](https://pic.leetcode-cn.com/61999d4ef33e19f1f0cf72d5bfeae1b9852240744e0aafcbe064b3c33cc1ceeb-image.png)

### 代码

```java
class Solution {
    public boolean validMountainArray(int[] A) {
        int left = 0;
        int right = A.length - 1;
        while (left < A.length - 1) {
            if (A[left] >= A[left + 1]) {
                break;
            }
            left++;
        }
        while (right > 0) {
            if (A[right] >= A[right - 1]) {
                break;
            }
            right--;
        }
        return left == right && left != 0 && left != A.length - 1;
    }
}
```