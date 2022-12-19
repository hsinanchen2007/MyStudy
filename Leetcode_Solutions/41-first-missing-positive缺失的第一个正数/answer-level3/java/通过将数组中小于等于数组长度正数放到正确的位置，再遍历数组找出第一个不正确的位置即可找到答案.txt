### 解题思路
此处撰写解题思路
遍历数组将每个位置的数字放到正确的位置(1放在数组下标为0的位置；2放在数组下标为1的位置，以此类推)，然后再次遍历数组，找到第一个位置不对的数组下标，数组下标+1就是最后的结果，如果遍历完毕仍然没有找到位置不对的下标，那么第一个缺少的数字就是数组长度+1；
有如下几种不需要处理的情况：
    1. 数字小于等于0
    2. 数字比数组长度还要大，比如说数组的长度是2，数字是3，那么3是没有位置可以放的
    3. 当前位置的数字已经是正确的数字，比如说数组下标为2应存放3，而且当前数组也是3
    4. 目标位置已经存在一个正确的数字，比如说3，数组下标为2的位置已经存在一个3，也不需要处理
### 代码

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 1;
        }

        int firstMissingNum = 1;
        int len = nums.length;
        for (int i = 0; i < len; ) {
            int numOfPos = nums[i];
            // 当前位置已经是正确的数字、负数或者比当前数组长度大的数不处理
            if (numOfPos <= 0 || numOfPos > len || nums[i] == i + 1 || nums[nums[i] - 1] == nums[i]) {
                i++;
                continue;
            }

            //将它放到对应的位置
            nums[i] = nums[numOfPos - 1];
            nums[numOfPos - 1] = numOfPos;
            // 交换完毕，需要检查交换之后的数字是否是一致的
            if (nums[i] <= 0 || nums[i] == i+1){
                i++;
                continue;
            }

            // 不一致,继续转换
        }

        for (int i = 0; i < len; i++) {
            if (nums[i] == i + 1) {
                firstMissingNum++;
            } else {
                firstMissingNum = i + 1;
                break;
            }
        }

        return firstMissingNum;
    }
}
```