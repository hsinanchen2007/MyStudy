### 解题思路
* 标准回溯法
* 根据条件要求获取结果。

### 代码

```java
class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(1,n,k,new ArrayList<>(),result);
        return result;
    }
    
    private void backtrack(int start,int n,int k,List<Integer> selected,List<List<Integer>>result) {
        if(selected.size() == k) {
            result.add(new ArrayList<>(selected));
            return;
        }
        for(int i = start; i <= n; i++) {
            selected.add(i);
            backtrack(i+1,n,k,selected,result);
            selected.remove(selected.size()-1);
        }
    }
}
```