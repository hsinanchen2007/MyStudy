
### 代码

```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        ArrayList<List<Integer>> res = new ArrayList<>();
        ArrayList<Integer> tmp = new ArrayList<>();
        getCombine(res, tmp, n, k, 1);
        return res;
     }
    public void getCombine(List<List<Integer>> res, List<Integer> tmp, int n, int k, int m) {
        if(tmp.size() == k) {
            res.add(new ArrayList(tmp));
            return;
        }
        for(int i = m; i <= n-k+tmp.size()+1; i++){
            tmp.add(i);
            getCombine(res, tmp, n, k, i+1);
            tmp.remove(tmp.size()-1);
        }
    }
}
```