### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        if (arr1 == null || arr2 == null) return null;
        int[] bucket = new int[1001];
        for (int num : arr1) bucket[num]++;
        int[] result = new int[arr1.length];
        int i = 0;
        for (int num : arr2)
            while (bucket[num]-- > 0) result[i++] = num;
        for (int j = 0; j <= 1000; j++)
            while (bucket[j]-- > 0) result[i++] = j;
        return result;
    }
}
```