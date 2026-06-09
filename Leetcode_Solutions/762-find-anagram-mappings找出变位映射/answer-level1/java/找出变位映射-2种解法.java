>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(n ^ 2)，其中n为数组A的长度。空间复杂度是O(n)。

执行用时：1ms，击败96.30%。消耗内存：38.2MB，击败8.57%。

```java
public class Solution {
    public int[] anagramMappings(int[] A, int[] B) {
        int n = A.length;
        boolean[] visited = new boolean[n];
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[j] && B[j] == A[i]) {
                    result[i] = j;
                    visited[j] = true;
                    break;
                }
            }
        }
        return result;
    }
}
```

# 解法二：哈希表

时间复杂度和空间复杂度均是O(n)，其中n为数组A的长度。

执行用时：1ms，击败96.30%。消耗内存：38.2MB，击败8.57%。

```java
public class Solution {
    public int[] anagramMappings(int[] A, int[] B) {
        int n = A.length;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            map.put(B[i], i);
        }
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            result[i] = map.get(A[i]);
        }
        return result;
    }
}
```