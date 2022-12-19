### 代码

```java
class Solution {
    boolean res = false;
    double eps = 0.001;
    public boolean judgePoint24(int[] nums) {
        List<Double> arr = new ArrayList<>();
        for (int i = 0; i < nums.length; i ++) {
            arr.add((double)nums[i]);
        }

        helper(arr);
        return res;
    }

    public void helper(List<Double> arr) {
        if (res) {
            return;
        }
        if (arr.size() == 1 && (Math.abs(arr.get(0) - 24)) < eps) 
        {
            res = true;
            return;
        }
        for (int i = 0; i < arr.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                List<Double> next = new ArrayList<>();
                double p1 = arr.get(i);
                double p2 = arr.get(j);
                next.addAll(Arrays.asList(p1 + p2, p1 - p2, p1 * p2, p2 - p1));
                if (Math.abs(p2) > eps) next.add(p1 / p2);
                if (Math.abs(p1) > eps) next.add(p2 / p1);
                arr.remove(i);
                arr.remove(j);
                for (Double n : next) {
                    arr.add(n);
                    helper(arr);
                    arr.remove(arr.size() - 1);
                }
                arr.add(j, p2);
                arr.add(i, p1);
            }
        }
    }
}
```