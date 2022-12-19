>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(n ^ 2)，其中n为light数组的长度。空间复杂度是O(n)。

执行用时：755ms，击败100.00%。消耗内存：50.9MB，击败100.00%。

```java
public class Solution {
    public int numTimesAllBlue(int[] light) {
        int n = light.length, result = 0;
        boolean[] isOpen = new boolean[n];
        for (int i = 0; i < n; i++) {
            isOpen[light[i] - 1] = true;
            boolean flag = true;
            for (int j = 0; j <= i; j++) {
                if (!isOpen[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result++;
            }
        }
        return result;
    }
}
```

# 解法二：记录当前点亮灯的最大编号值

假设灯的编号从0开始至n - 1，对于第i个操作，点亮编号为light[i] - 1的灯，去看前i个操作点亮的灯的编号的最大值，如果该值等于i，说明前i展灯全被点亮了。

时间复杂度是O(n)，其中n为light数组的长度。空间复杂度是O(1)。

执行用时：3ms，击败100.00%。消耗内存：51.4MB，击败100.00%。

```java
public class Solution {
    public int numTimesAllBlue(int[] light) {
        int result = 0, right = 0;
        for (int i = 0; i < light.length; i++) {
            right = Math.max(right, light[i] - 1);
            if (right == i) {
                result++;
            }
        }
        return result;
    }
}
```