
> 53 / 53 个通过测试用例
> 状态：通过
> 执行用时：42 ms
> 内存消耗：37.1 MB

```java
class Solution {
    public int numTeams(int[] rating) {
        int count = 0;
        // 需要的名额
        int n = 3;
        for(int i = 0; i < rating.length; i ++) {
            // 找递增
            count += findNext(rating[i], i + 1, rating, n-1, 1);
            // 找递减
            count += findNext(rating[i], i + 1, rating, n-1, -1);
        }
        return count;
    }
    
    // compare > 0表示递增，compare < 0 表示递减
    public int findNext(int v, int start, int[] rat, int n, int compare) {
        if(n == 0) {
            return 1;
        }
        int count = 0;
        for(int i = start; i < rat.length; i ++) {
            int a = rat[i];
            if(a == v) {
                continue;
            }
            if((a > v) != (compare > 0)) {
                continue;
            }
            count += findNext(a, i + 1, rat, n - 1, compare);
        }
        return count;
    }
}
```