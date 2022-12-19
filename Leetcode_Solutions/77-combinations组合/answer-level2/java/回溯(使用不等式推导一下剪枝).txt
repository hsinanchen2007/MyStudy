

```
class Solution {
   
    private List<List<Integer>> res = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        if (n < k) {
            return res;
        }

        generateCombination(n, 1, k, new Stack<>());

        return res;
    }

    // 从index...n选k个
    private void generateCombination(int n, int index, int k, Stack<Integer> stack) {
        if (stack.size() == k) {
            res.add(new ArrayList<>(stack));
            return;
        }

        // [i, n]中选l=(k-stack.size())个元素
        // n-i+1 >= l ==> i <= n+1-l
        for (int i = index; i <= n+1-(k-stack.size()); i ++) {
            stack.push(i);
            generateCombination(n, i+1, k, stack);
            stack.pop();
        }
    }
}
```
