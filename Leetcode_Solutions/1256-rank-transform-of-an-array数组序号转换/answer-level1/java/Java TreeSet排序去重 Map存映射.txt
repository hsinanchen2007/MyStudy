### 解题思路
将原数组插入set集合中并排序（由TreeSet去做去重和排序工作）

此时，set中已经是排序好的了。那么定义一个排序序号，每次遍历序号加1即可。并将相关的数字与序号的映射存入map中。

最后遍历原数组，或许map中的value(排序序号)保存至结果集中即可。

### 代码

```java
class Solution {
    public int[] arrayRankTransform(int[] arr) {

        Set<Integer> sets = new TreeSet<>();        //利用TreeSet完成排序、去重
        for (int num : arr) sets.add(num);

        Map<Integer, Integer> map = new HashMap<>();   // 利用map存储数字映射序号关系  , <num,sort>
        int sort = 0;
        for (Integer num : sets) map.put(num, ++sort);

        int[] ans = new int[arr.length];              // 遍历原数组，将原数组中的num作为key去map中找到对应的排序序号，再放入ans中最后返回
        for (int i = 0; i < arr.length; i++) ans[i] = map.get(arr[i]);

        return ans;
    }
}
```

执行用时 :73 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :53.5 MB, 在所有 Java 提交中击败了100.00%的用户

看了眼题解，没有java,小白自告奋勇展示下了(捂脸...)