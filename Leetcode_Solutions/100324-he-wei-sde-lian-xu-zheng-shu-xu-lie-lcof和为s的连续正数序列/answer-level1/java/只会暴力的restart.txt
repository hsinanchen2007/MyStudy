### 解题思路
利用连续自增的特性，进行遍历
### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        List<int[]> ans = new ArrayList<>();
        //  List<Integer> every= new ArrayList<>();
        int sum = 0;
        for (int i = 1; i < (target / 2+1); ++i) {
            for (int j = i; ; ++j) {
                sum = sum + j;
                if (sum > target) {
                    sum = 0;
                    break;
                } else if (sum == target) {
                    int[] a = new int[j - i+1];
                    for (int l = i; l <=j; ++l)
                        a[l - i] = l;
                    ans.add(a);
                }
            }

        }
        return ans.toArray(new int[0][]);
    }
}
```