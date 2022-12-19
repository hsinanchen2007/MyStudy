### 代码

```java
class Solution {
    public static int maxProfit(int[] prices) {
        if(prices.length == 0 || prices.length == 1)
            return 0;
        int[] diff = new int[prices.length];
        for(int i = 1; i < prices.length; i++)
            diff[i] = prices[i] - prices[i - 1];
        int result = findMaximumSubarray(diff, 1, diff.length -1)[2];
        return (result > 0)? result : 0;
    }

    public static int[] findCrossMaxSubarray(int[] array, int low, int high){
        int mid = (low + high) / 2;
        int leftSum = Integer.MIN_VALUE;
        int rightSum = Integer.MIN_VALUE;
        int leftIndex = mid;
        int rightIndex = mid + 1;
        int sum = 0;
        for(int i = mid; i >= 0; i--){
            sum += array[i];
            if(sum > leftSum){
                leftSum = sum;
                leftIndex = i;
            }
        }
        sum = 0;
        for(int i = mid + 1; i <= high; i++){
            sum += array[i];
            if(sum > rightSum){
                rightSum = sum;
                rightIndex = i;
            }
        }
        return new int[]{leftIndex, rightIndex, leftSum + rightSum};
    }

    public static int[] findMaximumSubarray(int[] array, int low, int high){
        if(low == high)
            return new int[]{low, high, array[low]};
        int[] resultLeft;
        int[] resultCross;
        int[] resultRight;
        int mid = (low + high) / 2;
        resultLeft = findMaximumSubarray(array, low, mid);
        resultRight = findMaximumSubarray(array, mid + 1, high);
        resultCross = findCrossMaxSubarray(array, low, high);
        if(resultCross[2] >= resultLeft[2] && resultCross[2] >= resultRight[2])
            return resultCross;
        else if(resultLeft[2] >= resultCross[2] && resultLeft[2] >= resultRight[2])
            return resultLeft;
        else
            return resultRight;
    }
}
```