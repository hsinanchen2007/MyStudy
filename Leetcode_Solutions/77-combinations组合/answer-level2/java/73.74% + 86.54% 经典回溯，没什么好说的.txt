
```
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> rs = new ArrayList<>();
        h(new ArrayList<>(), rs, k, n);
        return rs;
    }

    private void h(List<Integer> c, List<List<Integer>> rs, int k, int i) {
        if(c.size() == k) {
            rs.add(new ArrayList<>(c));
            return;
        }

        if(i == 0)
            return;

        h(c, rs, k, i - 1);
        
        c.add(i);
        h(c, rs, k, i - 1);
        c.remove(c.size() - 1);
    }
}
```
