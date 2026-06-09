1. 最后一个肯定是0；    
2.对于其他任意的i，可以逐步的向后查找。      
3. 向后查找最大值时的优化：        
如果T[i] > T[j] ; 那么j=j+output[j] . 因为下一个比[j]高距离为output[j]. 如果output[j]=0,表明当前值是从当前往后的最大值。可以终止查找。
```
class Solution {
    public int[] dailyTemperatures(int[] T) {
        if (T == null) {
            return new int[0];
        }

        int[] output = new int[T.length];
        if (T.length <= 1) {
            return output;
        }

        for (int i = T.length - 2; i >= 0; i--) {
            int j = i + 1;
            while (T[j] <= T[i] && output[j] != 0) {
                j += output[j];
            }
            if (T[i] < T[j]) {
                output[i] = j - i;
            } else {
                output[i] = 0;
            }
        }

        return output;
    }
}
```