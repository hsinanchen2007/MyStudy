```java
class Solution {
    public int findBestValue(int[] arr, int target) {
        int[] newArr = new int[arr.length + 1];
        System.arraycopy(arr, 0, newArr, 1, arr.length);
        Arrays.sort(newArr);
        int length = newArr.length;

        // 如果总和比 target 还小，则不需要替换。
        if (Arrays.stream(newArr).sum() <= target) {
            return newArr[length - 1];
        }
        // 已经遍历过的数字的和
        int sum = 0;
        // 剩下的数字个数
        int leftNum;
        // 剩下的数字和达到 target 需要的平均数
        double leftAverage;
        for (int i = 0; i < length - 1; i++) {
            sum += newArr[i];
            leftNum = length - i - 1;
            leftAverage = (target - sum) / (double) leftNum;
            // 如果平均数比下一个数小，则说明后面的数都要被替换
            if (leftAverage <= newArr[i + 1]) {
                // 如果 leftAverage <= x.5 ，则取 Math.floor(leftAverage);否则相反
                return (int) (leftAverage - Math.floor(leftAverage) <= 0.5 ? Math.floor(leftAverage)
                        : Math.ceil(leftAverage));
            }
        }
        // 只剩最后一个元素，因为数组总和大于 target，所以最后的结果必然为 target - sum
        return target - sum;
    }
}
```