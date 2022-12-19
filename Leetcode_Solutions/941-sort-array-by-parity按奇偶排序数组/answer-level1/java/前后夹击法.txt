## 解一：暴力解法（简直不能称为算法）
### 解题思路
1. 新建一个同样大小的新数组
1. 遍历原数组，如果是偶数则放在新数组的头部，如果值奇数则放在尾部
2. 返回新数组

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] arr = new int[A.length];
        int start = 0, end = A.length - 1;

        for (int i : A) {
            if (i % 2 == 0) {
                arr[start++] = i;
            } else {
                arr[end--] = i;
            }
        }

        return arr;
    }
}
```

## 解二：交换法

### 解题思路
遍历数组，
- 如果是偶数则跳过
- 如果是奇数，则跟数组尾部做交换
-- 交换的前提是当前尾部指向的值是偶数

### 代码

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        int head = 0, tail = A.length - 1;
        int tmp;

        for (; head < tail; head++) {
            if (A[head] % 2 == 1) {
                // 奇数则交换
                for (; tail > head; tail --) {
                    if (A[tail] % 2 == 0) {
                        // 如果是偶数，则跟头部的奇数做交换
                        tmp = A[tail];
                        A[tail] = A[head];
                        A[head] = tmp;

                        // 完成交换后，下次尾部从当前位置的下一个开始
                        tail--;
                        break;
                    }
                }
            }
        }

        return A;
    }
}
```

本以为解法二要强于解法一。可事实是，二还要稍逊于一。大概是循环嵌套将算法的功劳抵消了。