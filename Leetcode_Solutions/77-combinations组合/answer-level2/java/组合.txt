1. 回溯
 ```
import java.util.*;

class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> result = new ArrayList<>();
        process(result, 1, n, k, new ArrayList<>());
        return result;
    }
    public void process(List<List<Integer>> result, int begin, int n, int k, List<Integer> list) {
        if(k == 0) {
            List<Integer> temp = new ArrayList<>(list);
            result.add(temp);
            return;
        }
        if(begin > n)
            return;
        for(int i = begin; i <= n; i++) {
            list.add(i);
            process(result, i + 1, n, k - 1, list);
            list.remove(list.size() - 1);
        }
    }
}
```
