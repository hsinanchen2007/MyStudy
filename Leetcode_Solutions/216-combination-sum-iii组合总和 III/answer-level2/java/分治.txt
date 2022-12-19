### 解题思路
这题也是常规结题思路，这个模板也可以用于其他几道题，但是忘记了是哪几道。

### 代码

```java
class Solution {
    List<List<Integer>> lists = new ArrayList<>();
    public List<List<Integer>> combinationSum3(int k, int n) {
        
        if(k <= 0 || n < 1)
            return lists;

        List<Integer> list =  new ArrayList<>();
        combine(1, list, k, n);
        return lists;
    }

    public void combine(int start, List<Integer> list, int k, int n){
        if(k == 0 && n > 0){
            return;
        }
        if(n < 0 && k > 0){
            return;
        }
        if(n == 0 && k == 0){
            lists.add(new ArrayList<>(list));
            return;
        }

        for(int i = start; i < 10; i++){
            list.add(i);
            combine(i+1, list, k-1, n-i);
            list.remove(list.size() - 1);
        }
    }
}
```