### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    List<List<Integer>> ret = new ArrayList<>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        if(n < k || n > 9 * k){
            return ret;
        }
        List<Integer> already = new ArrayList<>();
        backtracking(already, 1, k, n);
        return ret;
    }
    private void backtracking(List<Integer> already, int start, int k, int n){
        if(k == 0 && n == 0){
            ret.add(new ArrayList<>(already));
            return;
        }
        if(start == 10){
            return;
        }
        for(int i = start; i < 10; i++){
            if(i <= n){
                already.add(i);
                backtracking(already, i+1, k-1, n-i);
                already.remove(already.size() - 1);
            }
        }
        return;
    }
}
```