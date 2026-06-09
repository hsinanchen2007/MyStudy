```
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> rs = new ArrayList<>();
        h(rs, new ArrayList<>(), 1, k, n);
        return rs;
    }

    private void h(List<List<Integer>> rs, List<Integer> cs, int s, int k, int n) {
        if(n == 0 && k == 0) {
            rs.add(new ArrayList<>(cs));
            return;
        }

        if(n < 0 || k == 0) {
            return;
        }
            
        for(int i = s; i <= 9; ++ i) {
            cs.add(i);
            h(rs, cs, i + 1, k - 1, n - i);
            cs.remove(cs.size() - 1);
        }
    }
}
```
