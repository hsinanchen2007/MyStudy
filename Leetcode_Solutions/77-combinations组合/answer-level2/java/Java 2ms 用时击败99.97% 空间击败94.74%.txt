```
class Solution {
    public static List<List<Integer>> combine(int n, int k) {
        if(k > n)
            return null;
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> entry = new ArrayList<>();
        createAns(ans,entry,0,0,n,k);
        return ans;
    }
    public static void createAns(List<List<Integer>> ans, List<Integer> entry, int prev, int count, int n, int k){
        if(count == k){
            ans.add(new ArrayList<>(entry));
            return;
        }
        for (int i = prev + 1; i <= n - k + count + 1; i++) {
            entry.add(i);
            createAns(ans,entry,i ,count+1,n,k);
            entry.remove(count);
        }
    }
}
```
