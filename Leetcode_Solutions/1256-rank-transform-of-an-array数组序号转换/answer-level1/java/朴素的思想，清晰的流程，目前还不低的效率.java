### 解题思路
算法题目，奇技淫巧方显实力，但是实际工作中，可读性似乎更重要。
下面的方法流程清晰，思路严谨简单，初学者可以看一下。
结合注释理解。


### 代码

```java
class Solution {
    public int[] arrayRankTransform(int[] arr) {
        // 1. 边界条件判断
        if (arr == null || arr.length == 0) {
            return arr;
        }
        // 2. 去重
        Set<Integer> set = new HashSet<>();
        for (int i : Arrays.copyOf(arr, arr.length)) {
            set.add(i);
        }
        int[] copy = new int[set.size()];
        int index = 0;
        for (int i : set) {
            copy[index++] = i;
        }

        // 3. 排序
        Arrays.sort(copy);
        // 4. 装入Map
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < copy.length; i++) {
            map.put(copy[i], i + 1);
        }

        //5. 得到结果
        for (int i = 0; i < arr.length; i++) {
            int value = arr[i];
            arr[i] = map.get(value);
        }
        return arr;
    }
}
```