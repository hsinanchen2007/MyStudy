### 解题思路
1.对数组排序 从小到大 ASC
    思路:数组中所有的相邻数字比较，大的放左边，小的放右边
        每次比较如果没有发生位置交换，说明数组已经排好序，直接返回
        否则继续比较数组第二位及之后的所有数字,一直到最后一位数字
2.对排好顺序的数字遍历，如果遍历的数字>0说明后面的数组不能有=0的，直接返回
    比较遍历数字，重复则跳过
    拿到第一份数字num[i] 后拿第二个数字
    因为已经排好序，剩下两个数字从num[i]的下个相邻数字（仅比已经拿到的数字小）和当前数组中最小的数组取
取三个数字之和：
    >0 数字取大了,需要换一个更小的替换掉，左边最小的数字不变，更换右边数字（L++）
    <0 数字取小了,需要大点的数字，当前遍历中最大的是左边的数字，需要更换右边的数字(R--)
    =0 数组对了，放到集合中
    比较时，出现遍历数字和上次遍历数字一样时，跳过 避免重复

### 代码

```java
class Solution {
      public List<List<Integer>> threeSum(int[] nums) {
      sortAsc(nums);
        List<List<Integer>> res = new ArrayList<>(nums.length);
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if (nums[i] > 0) {
                break;
            }
            int L = i +1;
            int R = nums.length - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    List<Integer> group = new ArrayList<>(4);
                    group.add(nums[i]);
                    group.add(nums[L]);
                    group.add(nums[R]);
                    res.add(group);
                    while (L < R && nums[L] == nums[L + 1]) {
                        L++;
                    }
                    while (L < R && nums[R] == nums[R - 1]) {
                        R--;
                    }
                    L++;
                    R--;
                } else if (sum < 0) {
                    L++;
                } else if (sum > 0) {
                    R--;
                }
            }
        }
        return res;
    }
    private static void sortAsc(int[] nums) {
        int temp;
        boolean flag;
        for (int i = 0; i < nums.length - 1; i++) {
            flag = false;
            for (int j = nums.length -1; j > i; j--) {
                if (nums[j-1] > nums[j]) {
                    temp = nums[j-1];
                    nums[j-1] = nums[j];
                    nums[j] = temp;
                    flag = true;
                }
            }
            if (!flag) {
                return;
            }
        }
    }
}
```