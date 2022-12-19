### 解题思路

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int n1 = arr1.length;
        int n2 = arr2.length;
        int[] result = new int[n1];
        boolean[] visited = new boolean[n1];
        int k = 0;
        for (int i = 0; i < n2; i++) {
            int currentValue = arr2[i];
            for (int j = 0; j < n1; j++) {
                if (visited[j]) {
                    continue;
                }
                if (arr1[j] == currentValue) {
                    result[k++] = arr1[j];
                    visited[j] = true;
                }
            }
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n1; i++) {
            if (!visited[i]) {
                list.add(arr1[i]);
            }
        }
        int[] rest = list.stream().sorted().mapToInt(i -> i.intValue()).toArray();
        for (int i = 0; i < rest.length; i++) {
            result[k + i] = rest[i];
        }
        return result;
    }
}
```