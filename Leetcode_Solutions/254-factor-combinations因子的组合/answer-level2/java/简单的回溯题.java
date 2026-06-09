```
class Solution {
    public List<List<Integer>> getFactors(int n) {
        List<List<Integer>> res = new ArrayList<>();
        dfs(res, new ArrayList<>(), n, 2);
        return res;
    }

    private void dfs(List<List<Integer>> res, List<Integer> item, int n, int start){
        if(n == 1){
            if(item.size() > 1){
                res.add(new ArrayList<>(item));
            }
            return;
        }
        for(int i = start; i * i <= n; i++){
            if(n % i == 0){
                item.add(i);
                item.add(n / i);
                res.add(new ArrayList<>(item));
                item.remove(item.size() - 1);
                dfs(res, item, n/i, i);
                item.remove(item.size() - 1);
            }
        }
    }
}
```