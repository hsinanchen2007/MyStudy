滑窗算法 Java 时间复杂度O(n)

```java []
/**
 * @author ：***
 * @date ：2019-06-14
 * @description ：长度最小的子数组
 */
public class MinSubArray {

    public static int minSubArrayLen(int s, int[] nums) {

        int n = nums.length;

        // i: 左边界，j: 右边界，sum: 窗口和，result: 返回值
        int i = 0, j = 0, sum = 0, result = n;


        // 由于左边界必须小于右边界（i <= j ），判断条件可写为 j < n
        while(j < n) {

            // sum = [i,j) 的和，所以需要加上j的值
            if(sum + nums[j]< s){
                sum += nums[j++];

            }else {

                // i、j为下标，故需要 + 1
                result = Math.min(result, j - i + 1);
                sum -= nums[i++];
            }
        }
        return result;
    }
}

```
