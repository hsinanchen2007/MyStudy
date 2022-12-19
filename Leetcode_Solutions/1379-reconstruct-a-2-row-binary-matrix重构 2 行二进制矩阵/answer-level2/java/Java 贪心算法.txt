```
class Solution {
    public List<List<Integer>> reconstructMatrix(int upper, int lower, int[] colsum) {
        if (colsum.length <= 0) {
            return new ArrayList<>();
        }
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> line0 = new ArrayList<>();
        List<Integer> line1 = new ArrayList<>();
        result.add(line0);
        result.add(line1);
        int sum0 = 0, sum1 = 0;
        for (int i = 0; i < colsum.length; i++) {
            line0.add(0);
            line1.add(0);
            if (colsum[i] < 0 || colsum[i] > 2) {
                return new ArrayList<>();
            } else if (colsum[i] == 2) {
                if (sum0 >= upper && sum1 >= lower) {
                    return new ArrayList<>();
                }
                line0.set(i, 1);
                line1.set(i, 1);
                sum0++;
                sum1++;
            }
        }

        for (int i = 0; i < colsum.length; i++) {
            if (colsum[i] == 1) {
                if (sum0 >= upper && sum1 >= lower) {
                    return new ArrayList<>();
                } else if (sum0 < upper) {
                    sum0++;
                    line0.set(i, 1);
                } else {
                    sum1++;
                    line1.set(i, 1);
                }
            }
        }
        if (sum0 == upper && sum1 == lower) {
            return result;
        }
        return new ArrayList<>();
    }
}
```
