```java
class Solution {
    List<List<Integer>> res = new ArrayList<>();
    int n;
    int k;
    public List<List<Integer>> combinationSum3(int k, int n) {
        this.n = n;
        this.k = k;
        helper(new ArrayList<>(), 0, 0, 1);
        return res;
    }
    
    void helper(List<Integer> cur, int curLen, int sum, int start) {
        if (curLen == k && sum == n) {
            res.add(new ArrayList<>(cur));
        }

        for (int i = start; i <= 9; i ++) {
            cur.add(i);
            helper(cur, curLen + 1, sum + i, i + 1);
            cur.remove(cur.size() - 1);
        }
    }
}
```