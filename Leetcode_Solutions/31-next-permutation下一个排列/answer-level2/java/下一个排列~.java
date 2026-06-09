### 解题思路
从右边开始寻找第一个拐点，及第一个减小的点（例如 {6,3,8,4,2,1}中，3就是拐点。）
三种情况：
1： 不存在拐点
    即最大的排列 {8,6,4,3,2,1} 这样的，题目有漏掉的说可以循环过来，那么它的下一个就是最小的排列，只需要递增排序就好。
2： 存在拐点
    这时候只需要把拐点右边最小的数字和拐点进行交换，然后把拐点索引后面的进行递增排序就好。
    例如{6,3,8,4,2,1}中，3是拐点index = 1，4是大于拐点最小的数字index = 3。
    先交换它们，得到{6,4,8,3,2,1}，然后再将拐点index = 1后面的进行排序 => {6,4,1,2,3,8}

目前时间消耗1ms，击败 Java 99.94% 的用户。


### 代码

```java
class Solution {
    public void nextPermutation(int[] nums) {
        if (nums == null) {
            return;
        }

        int guiadian = nums[nums.length - 1];
        int i = nums.length - 2;
        for (; i >= 0; i--) {
            if (nums[i] >= guiadian) {
                guiadian = nums[i];
            } else {
                break;
            }
        }

        if (i < 0) {
            //  the max pailie
            Arrays.sort(nums);
            return;
        }

        for (int replace = nums.length - 1; replace > i; replace--) {
            if (nums[replace] > nums[i]) {
                int tmp = nums[i];
                nums[i] = nums[replace];
                nums[replace] = tmp;
                break;
            }
        }

        Arrays.sort(nums, i + 1, nums.length);
        //System.out.println("result :" + Arrays.toString(nums));
    }
}
```