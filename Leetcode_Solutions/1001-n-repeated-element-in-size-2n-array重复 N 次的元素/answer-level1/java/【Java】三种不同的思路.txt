### 思路一：

最笨的办法，依次遍历，计算各数字的出现次数，并用 map 存储。判断各个数字的次数是否大于1即可

### 代码：

时间复杂度O(n)，空间复杂度O(n)

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        if (A == null) {
            return -1;
        }
        int n = A.length;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(A[i], map.getOrDefault(A[i], 0) + 1);
            if (map.get(A[i]) == n / 2) {
                return A[i];
            }
        }
        return -1;
    }
}
```

### Result：

Runtime：43ms

Your runtime beats 4.79% of java submissions.

### 思路二：（投机取巧的方法）

其实，仔细读题可以发现，待求结果是数组中唯一重复出现的数字。可以借助 map 或者 set 数据结构。可以减少很多次不必要的执行逻辑

### 代码：

时间复杂度O(n) ，空间复杂度O(n)

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        if (A == null) {
            return -1;
        }
        int n = A.length;
        Map<Integer, Boolean> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (map.containsKey(A[i])) {
                return A[i];
            }
            map.put(A[i], true);
        }
        return -1;
    }
}
```

### Result：

Runtime：1ms

Your runtime beats 86.08% of java submissions.

### 思路三：

根据题目描述，4 <= A.length <= 10000，有一个数重复 N 次，而且所有数的个数为2N，因此，也就是说，要求的这个数占了一半。那么必然可得，**一定会出现连续的三个数，其中有两个数相等**，也就是所要求的数。举个例子，比如有数组[1, 2, 4, 5, 3, 3, 3, 3]，那么将3打的最散的排列是[1, 3, 2, 3, 4, 3, 5, 3]。可以发现无论怎么排，一定会出现三个连续的数，其中存在两个相同的数。

### 代码：

时间复杂度O(n) ，空间复杂度O(1)

```java
class Solution {
    public int repeatedNTimes(int[] A) {
        if (A == null) {
            return -1;
        }
        int n = A.length;
        for (int i = 0; i < n - 2; i++) {
           if (A[i] == A[i + 1] || A[i] == A[i + 2]) {
               return A[i];
           }
        }
        return A[n - 1];
    }
}
```
### Result：

Runtime：0ms

Your runtime beats 100% of java submissions.