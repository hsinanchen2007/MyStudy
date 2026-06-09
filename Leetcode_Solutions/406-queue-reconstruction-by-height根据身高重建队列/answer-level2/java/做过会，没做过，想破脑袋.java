### 解题思路
先排序，然后插入

### 代码

```java
class Solution {
    public int[][] reconstructQueue(int[][] people) {
        Arrays.sort(people, (o1, o2) -> o1[0] == o2[0] ? o1[1] - o2[1] : o2[0] - o1[0]);
        List<int[]> results = new ArrayList<>();
        for (int[] value : people) {
            results.add(value[1], value);
        }
        return results.toArray(new int[people.length][2]);
    }
}
```