### 解题思路
首先遍历数组，获得数组A的最大值max和min，再创建数组`count[max - min + 1`]用于统计数组A中每个元素的个数。
1. 开始查找数组`count`中元素大于1的下标位置k，而后在数组`count`中从`k + 1`开始查找元素为0的下标`zeroIndex`
2. 而后对count[k]进行减一操作，而在当前zeroIndex的位置已经存放了count[k]的元素，并记录增加次数sum += (zeroIndex - k);
3. `zeroIndex ++`，若当前`zeroIndex < n`，则查找下一个`count[zeroIndex] = 0`的情况，以便存放**下一个**`count[k]`，若`zeroIndex >= n`，则直接存放，因为zeroIndex的位置必定没有元素存放。

### 代码

```java
class Solution {
    public int minIncrementForUnique(int[] A) {
        if(A == null || A.length < 2) return 0;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for(int i : A){
            min = Math.min(min, i);
            max = Math.max(max, i);
        }
        int[] count = new int[max - min + 1];
        int n = max - min + 1;
        for(int i : A){
            count[i - min] ++;
        }
        int sum = 0;
        int zeroIndex = 0;
        int k = 0;
        while(true){
            while(k < n && count[k] < 2) k ++;
            if(k == n) break;
            if(zeroIndex <= k){
                zeroIndex = k + 1;
                while(zeroIndex < n && count[zeroIndex] > 0) zeroIndex ++;
            }
            while(count[k] > 1){
                count[k] --;
                sum += (zeroIndex - k);
                zeroIndex ++;
                if(zeroIndex < n){
                    while(zeroIndex < n && count[zeroIndex] > 0) zeroIndex ++;
                }
               
            }
        }
        return sum;
    }
}
```