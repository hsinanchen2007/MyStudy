### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int maxProfit(int[] prices) {
    if (prices == null || prices.length <= 1) {
            return 0;
        }
        int totalLength = prices.length;
        int beforeMini = prices[0];
        int beforeMaxDiff = 0;
        int afterMax = prices[totalLength - 1];
        int afterMaxDiff = 0;
        int currentValue = 0;
        int rightCurrentValue;
        //i之前包含i的最大差
        int[] leftDiff = new int[totalLength];
        //i之后不包含i的最大差
        int[] rightDiff = new int[totalLength];
        for (int i = 1; i < totalLength; i++) {
            currentValue = prices[i];
            if (currentValue > beforeMini + beforeMaxDiff) {
                beforeMaxDiff = currentValue - beforeMini;
            } else if (currentValue < beforeMini) {
                beforeMini = currentValue;
            }
            leftDiff[i] = beforeMaxDiff;

            rightCurrentValue = prices[totalLength-1 - i];
            if (rightCurrentValue < afterMax - afterMaxDiff) {
                afterMaxDiff = afterMax - rightCurrentValue;
            } else if (rightCurrentValue > afterMax) {
                afterMax = rightCurrentValue;
            }
            rightDiff[totalLength-1 - i] = afterMaxDiff;

        }
        int totalMaxTake = 0;
        int currentMax = 0;
        // System.out.println("左边:"+ Arrays.toString(leftDiff));
        // System.out.println("右边:"+ Arrays.toString(rightDiff));
        for (int i = 0; i < totalLength; i++) {
            currentMax = leftDiff[i] + rightDiff[i];
            if (currentMax > totalMaxTake) {
                totalMaxTake = currentMax;
            }
        }
        return totalMaxTake;
    }
}
```