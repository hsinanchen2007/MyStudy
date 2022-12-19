**从后向前遍历A，对于某个A[i]，如果在A[i+1]、A[i+2]……A[length-1]中存在比A[i]小的数，在这些数中找到小于A[i]的最大值max，将距离A[i]最近的（即索引最小的）最大值和A[i]交换即可**


```
class Solution {
    public int[] prevPermOpt1(int[] A) {
        int length = A.length;
        /**
         * min为数组A中某个数之后的所有数中的最小值
         */
        int min = A[length - 1];
        /**
         * 数组A中某个数之后的数字 -> 数字出现的所有位置中的最小索引
         */
        Map<Integer, Integer> map = new HashMap<>();
        map.put(min, length - 1);

        for (int i = length - 2; i >= 0; i--) {
            /**
             * 如果在A[i+1]、A[i+2]……A[length-1]中存在比A[i]小的数，在这些数中找到小于A[i]的
             * 最大值，将距离A[i]最近的（即索引最小的）最大值和A[i]交换即可
             */
            if (A[i] > min) {
                /**
                 * A[i+1]、A[i+2]……A[length-1]中小于A[i]的最大值
                 */
                int max = Integer.MIN_VALUE;

                for (int num : map.keySet()) {
                    if (num < A[i]) {
                        max = Math.max(max, num);
                    }
                }
                /**
                 * A[i]之后距离A[i]最近的（即索引最小的）最大值的索引位置
                 */
                int index = map.get(max);
                /**
                 * 将A[i]和A[index]交换即可
                 */
                int temp = A[index];
                A[index] = A[i];
                A[i] = temp;
                return A;
            } else {
                min = Math.min(min, A[i]);
                map.put(min, i);
            }
        }
        return A;
    }
}
```
