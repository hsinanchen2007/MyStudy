### 解题思路
反向思考这个问题。假设数组能被三等分，原始数组的和为`totalSum`，每个子数组的和为`sum`，那么等式`3*sum == totalSum`肯定成立，且遍历出来两个子数组后，角标没有达到尾部，否则就不满足三等分的要求。因此我们可以按照以下的步骤检验数组是否符合：
1. 遍历原始数组A，求出数组的和`totalSum`；
2. 判断`totalSum`是否能被3整除，可以的话算出单个子数组的和`sum`，不可以的话直接返回false；
3. 从头再次遍历原始数组A，以此找出和为`sum`的数组，当遍历出来两个且角标没有到达尾部，则满足要求，返回true即可；

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] a) {
        int totalSum = 0;
        for (int i = 0; i < a.length; i++) {
            totalSum += a[i];
        }
        // 如果总和不能被3整除，说明不能三等分，直接返回false即可
        int sum = totalSum / 3;
        if (sum * 3 != totalSum){
            return false;
        }
        int temp = 0;
        int count = 0;
        for (int j = 0; j < a.length; j++) {
            temp += a[j];
            if (temp == sum){
                count++;
                temp = 0;
                if (count == 2 && j < a.length - 1){
                    // 已经找到2个和为sum的数组，而且还没有到达尾部，说明剩余的数据和也为sum
                    return true;
                }
            }
        }
        return false;
    }
}
```

时间复杂度：O(N)