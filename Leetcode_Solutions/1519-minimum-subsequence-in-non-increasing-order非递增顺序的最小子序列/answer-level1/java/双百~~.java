思路：
将数组内数据进行排序（从小到大）
依次从最大的数进行累加
依次将剩余的数进行累加
比较两累加和

```
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        List<Integer> list = new ArrayList<>();
        int len = nums.length;
        //排序
        Arrays.sort(nums);
        int sum = 0;
        for (int i = len - 1; i >= 0; i--) {
            int temp = 0;
            //最大数累加和
            sum += nums[i];
            list.add(nums[i]);
            //剩余的数累加和
            for (int j = i - 1; j >= 0; j--) {
                temp += nums[j];
            }
            //不严格大于
            if (sum >= temp) {
                //需再加上该数之前的一个
                if (sum == temp) {
                    list.add(nums[i - 1]);
                    sum += nums[i - 1];
                }
                if (sum > temp) {
                    return list;
                }
            }
        }
        return list;
    }
}
```
