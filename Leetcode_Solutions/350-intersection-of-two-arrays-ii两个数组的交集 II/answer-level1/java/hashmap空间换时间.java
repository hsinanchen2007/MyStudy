执行用时 :6 ms, 在所有 Java 提交中击败了81.35%的用户
内存消耗 :38 MB, 在所有 Java 提交中击败了22.83%的用户

先遍历第一个数组，用哈希表记录所有的数字和出现的次数，
再遍历第二个数组，哈希表含有的数字且次数大于0的记录到结果数组中，然后将哈希表中这个数字的个数减一
最后根据索引index截取结果。

```
        Map<Integer, Integer> map1 = new HashMap<>();
        int[] result = new int[nums1.length];
        for (Integer item : nums1) {
            if (!map1.containsKey(item)) {
                map1.put(item, 1);
            } else {
                map1.put(item, map1.get(item) + 1);
            }
        }
        int index = 0;
        for (Integer item : nums2) {
            if (map1.containsKey(item) && map1.get(item) > 0) {
                result[index++] = item;
                map1.put(item, map1.get(item) - 1);
            }
        }
        return Arrays.copyOf(result, index);
```
