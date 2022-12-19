### 解题思路
每次遍历都复刻下之前的列表，然后对其操作后合并两个列表

### 代码

```java
class Solution {
    public static List<List<Integer>> subsets(int... nums) {
        List<List<Integer>> res = new ArrayList<>();


        for (int num : nums) {
            List<List<Integer>> resItem = new ArrayList<>();
            for (List<Integer> r : res) {
                List<Integer> item = new ArrayList<>(r);
                item.add(num);
                resItem.add(item);
            }
            List<Integer> e = new ArrayList<>();
            e.add(num);
            resItem.add(e);
            res.addAll(resItem);
        }
        res.add(Collections.emptyList());
        return res;
    }
}
```