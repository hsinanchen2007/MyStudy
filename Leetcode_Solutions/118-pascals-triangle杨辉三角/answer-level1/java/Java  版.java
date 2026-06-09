
```
class Solution {
   public List<List<Integer>> generate(int numRows) {

        List<Integer> start = new ArrayList<>();
        start.add(1);

        List<List<Integer>> res = new ArrayList<>();
        if (numRows == 0) return res;
        res.add(start);

        for (int i = 1; i < numRows; i++) {
            List<Integer> curr = getNext(res.get(i - 1), i);
            res.add(curr);
        }

        return res;
    }

    public List<Integer> getNext(List<Integer> pre, int line) {
        List<Integer> curr = new ArrayList<>();
        curr.add(1);
        for (int i = 1; i < line; i++) {
            curr.add(pre.get(i - 1) + pre.get(i));
        }
        curr.add(1);
        return curr;
    }
}
```
