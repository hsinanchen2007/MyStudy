### 解题思路
使用map存排序后的第几大，从1开始存。

### 代码

```java
class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int[] a = new int[arr.length];
        a = arr.clone();
        Arrays.sort(a);
        Map<Integer, Integer> map = new HashMap<>();
        int index=1;
        for (int i=0; i<a.length; i++) {
            if (!map.containsKey(a[i])) {
                map.put(a[i], index);
                index++;
            }
        }   
        int[] re = new int[arr.length];
        for (int i=0; i<arr.length; i++) {
            re[i] = map.get(arr[i]);
        }
        return re;
    }
}
```