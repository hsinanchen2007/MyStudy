排序后找到使得和大于0的最后n个元素
因为每往前增加一个元素，相当于增加从该元素到最大元素的和

例如[-1,-8,0,5,-9]
排序后[-9,-8,-1,0,5]

当选择 0和5 ，sum1 = 0 * 1 + 5 * 2
当选择 -1/0/5 ，sum2 = -1 * 1 + 0 * 2 + 5 * 3 = sum1 + -1 + 0 + 5

```
class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);

        int sum = 0;
        int i = satisfaction.length - 1;
        for (; i >= 0; i--) {
            if (sum + satisfaction[i] <= 0) {
                break;
            } else {
                sum += satisfaction[i];
            }
        }
        if (sum == 0) {
            return 0;
        }
        sum = 0;
        int k = 1;
        for (int j = i + 1; j < satisfaction.length; j++, k++) {
            sum += satisfaction[j] * k;
        }

        return sum;
    }
}
```
