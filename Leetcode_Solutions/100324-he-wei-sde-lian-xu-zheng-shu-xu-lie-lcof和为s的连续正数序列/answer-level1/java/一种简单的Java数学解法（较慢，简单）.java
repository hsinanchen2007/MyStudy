### 解题思路

根据递推公式:a1+..+an = (a1+an)*n/2 = (a1+an)*(an-a1+1)/2反推a1和an.

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {
        if (target <= 2) {
            return new int[0][];
        }
        List<int[]> result = new ArrayList<>();
        for (int i = 1; i <= target/2; i ++) {
            for (int j = i+1; j <= target/2+1; j ++) {
                int ans = (j+i)*(j-i+1)/2;  
                if (ans == target) {
                    int[] subArray = new int[j-i+1];
                    for (int k = 0; k < subArray.length; k ++) {
                        subArray[k] = k+i;
                    }
                    result.add(subArray);
                }
                if (ans > target)
                    break;
            }
        }
        return result.toArray(new int[0][]);
    }
}
```