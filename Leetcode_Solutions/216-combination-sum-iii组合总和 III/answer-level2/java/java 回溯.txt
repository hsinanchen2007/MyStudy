```java []
class Solution {
    public List<List<Integer>> lists = new ArrayList<>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        if (k == 0 || n < 6) {
            return lists;
        }
        List<Integer> list = new ArrayList<>();
        process(k, n, list, 1);
        return lists;
    }
    public void process(int k, int n, List<Integer> list, int start) {
        if (n == 0 && k == 0) {
            lists.add(new ArrayList<>(list));
        } else if (n > 0 && k > 0) {
            for (int i = start; i <= 9; i++) {
                if (n < i) {
                    return;
                }
                list.add(i);
                process(k - 1, n - i, list, i + 1);
                list.remove(list.size() - 1);
            }
        }
    }
}
```

绕了好一会儿