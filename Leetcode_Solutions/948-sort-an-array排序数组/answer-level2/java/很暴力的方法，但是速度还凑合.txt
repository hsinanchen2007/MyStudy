### 解题思路
根据题目已知范围为-50000至50000,所以用了两个数组和，一个存正数，一个存负数。

### 代码

```java
class Solution {
    public int[] sortArray(int[] nums){
        //存放正数
        int[] positiveNums = new int[50000];
        //存放负数
        int[] negativeNums = new int[50000];
        //0出现的次数
        int zoreNums = 0;


        for (int num : nums) {
            //大于0，则出现次数+1
            if (num > 0) {
                positiveNums[num]++;
            } else if (num < 0) {
            //小于0，则出现次数+1
                negativeNums[-num]++;
            } else {
            //等于0，则出现次数+1
                zoreNums++;
            }
        }

        int[] result = new int[nums.length];
        int flag = 0;

        //负数中，绝对值大的数最小，所以从最大的位置开始遍历
        for (int i = negativeNums.length - 1; i >= 0; i--) {
            if (negativeNums[i] > 0) {
                for (int i1 = 0; i1 < negativeNums[i]; i1++) {
                    result[flag++] = -i;
                }
            }
        }
        //出现0的次数
        for (int i = 0; i < zoreNums; i++) {
            result[flag++] = 0;
        }
        //正数，及出现的次数
        for (int i = 0; i < positiveNums.length; i++) {
            if (positiveNums[i] > 0) {
                for (int i1 = 0; i1 < positiveNums[i]; i1++) {
                    result[flag++] = i;
                }
            }
        }


        return result;
    }
}
```