### 方法一：使用isGoingUp标记目前状态（上山/下山）
在解题的过程中首先考虑了使用一个布尔值标记“行程”状态的方法。
```java
class Solution {
    public boolean validMountainArray(int[] A) {
        int length = A.length;
        if (length < 3) {
            return false;
        }

        // 检查山峰是否出现在 i == 0 或 i == length
        if ((A[0] >= A[1]) || (A[length - 2] <= A[length - 1])) {
            return false;
        }

        // isGoingUp 布尔值，标记目前上山/下山状态
        boolean isGoingUp = true;
        for (int i = 1; i <= length - 2; i++) {
            if (isGoingUp) {
                if (A[i - 1] >= A[i]) {
                    // 发现山峰，随即进入下山过程
                    isGoingUp = false;
                }
            } else {
                if (A[i - 1] <= A[i]) {
                    return false;
                }
            }
        }

        return true;
    }
}
```

### 方法二：while循环判断上下山过程
测试结果指出方法一相对比较慢，于是考虑不再显性地使用isGoingUp布尔值。这种方法可以达到100%的时间排位。
```java
class Solution {
    public boolean validMountainArray(int[] A) {
        int length = A.length;
        if (length < 3) {
            return false;
        }

        // 检查山峰是否出现在 i == 0 或 i == length
        if ((A[0] >= A[1]) || (A[length - 2] <= A[length - 1])) {
            return false;
        }

        int i = 2;

        // 上山，在 A[i - 1] < A[i] 时发现山峰
        // 这一过程比方法一少了一步比较，可以在时间上有所节省
        while (A[i - 1] < A[i]) {
            i++;
        }

        // 下山，一旦发现 i >= length - 1 就意味着已经到达山脚
        // 之所以是 >= 是因为不同数组长度（比如3或4）会使得这一过程的终点不同
        while (A[i - 1] > A[i]) {
            i++;
            if (i >= length - 1) {
                return true;
            }
        }

        // 如果之前没有被return掉，就说明无法下山，是false
        return false;
    }
}
```
尽管两种方法的时间复杂度均为 O(n)，但其中的细微差异亦会导致不同。