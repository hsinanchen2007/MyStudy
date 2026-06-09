![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/2a0cb081c0454e360f86683873f607f9b437efe6f40f28467229e7ed8a163f51-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)

建立一个二维数组，存数值和原始序号。按照数值增序排列。获得比它小的数字的个数，生成结果。

### 代码

```java
public class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        if(nums == null) return null;
        int len = nums.length;
        //创建二维数组，[nums数组中的数值，在nums中的序号]
        int[][] arr = new int[len][2];
        for (int i = 0; i < len; i++) {
            arr[i][0] = nums[i];
            arr[i][1] = i;
        }
        // 按照数值的升序排列
        Arrays.sort(arr, (int[] ints, int[] t1) -> ints[0] - t1[0]);
        int[] res = new int[len];
        int count = 0;
        res[arr[0][1]] = 0;
        for (int i = 1; i < len; i++) {
            if (arr[i][0] == arr[i - 1][0]) {
                res[arr[i][1]] = count;
            } else {
                res[arr[i][1]] = i;
                count = i;
            }
        }
        return res;
    }
}

```