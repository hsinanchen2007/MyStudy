回溯的模板还是很清晰的,按步走就行
```
public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        if (n < k)
            return res;
        List<Integer> temp = new ArrayList<>();
        backtrack(n, k, 1, res, temp);
        return res;
    }
    private void backtrack(int n, int k, int start, List<List<Integer>> res, List<Integer> temp) {  
        if (temp.size() == k && n == 0) {
            res.add(new ArrayList<>(temp));
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (n < 0)
                continue;//剪枝
            temp.add(i);
            backtrack(n - i, k, i + 1, res, temp);
            temp.remove(temp.size() - 1);
        }
    }

```
