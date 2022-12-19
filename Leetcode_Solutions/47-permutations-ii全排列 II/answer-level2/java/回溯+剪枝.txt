### 解题思路
这道题真的做哭了，就加个排序加个条件判断的事，卡了我一晚上，结果是因为回溯时had复原时出现的问题，我调用了List.remove(Object o)这个函数，直接根据之前加入的元素的值删除，但我没考虑如果元素重复到这个函数会优先删除前面那一个，这就造成了2，1，1，2，复原后应该是2，1，1，结果变成了1，1，2，把第一个2给删了，真是要吐了，其实直接把had最后一个元素删了就行

### 代码

```java
class Solution {
    int len = 0;
    List<List<Integer>> res;
    public List<List<Integer>> permuteUnique(int[] nums) {
        res = new ArrayList<>();
        len = nums.length;
        if (len == 0) return res;
        List<Integer> had = new ArrayList<>();
        List<Integer> remain = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < len; i++) remain.add(nums[i]);
        work(had, remain);
        return res;
    }
    void work(List<Integer> had, List<Integer> remain) {
        if (had.size() == len) {
            res.add(new ArrayList<>(had));
            return;
        }
        for (int i = 0; i < remain.size(); i++) {
            if (i < remain.size() - 1 && remain.get(i) == remain.get(i + 1)) continue;
            if (remain.size() == len) System.out.println(i);
            Integer temp = remain.get(i);
            had.add(temp);
            int j = had.size() - 1;
            remain.remove(i);
            work(had, remain);
            had.remove(j);
            remain.add(i, temp);
        }
    }
}
```