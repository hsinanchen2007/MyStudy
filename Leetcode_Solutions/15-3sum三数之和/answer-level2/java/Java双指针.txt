从左向右遍历列表
指针L从i+1开始增加，指针R从N - 1开始减少
sum: 对i,L,R处求和
- sum < 0 : L++
- sum > 0 : R--
- sum = 0 : 
    1. 添加元素
    2. 将两个指针移动到下一个不同的值
    3. 回去sum
```
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int N = nums.length;
        if(N < 3) return new ArrayList();
        List<List<Integer>> list = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        for(int i = 0; i < N - 2; i++) {
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int L = i + 1, R = N - 1;
            while(L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if(sum == 0 && L < R){
                    List<Integer> subList = new ArrayList<Integer>();
                    subList.add(nums[i]);
                    subList.add(nums[L]);
                    subList.add(nums[R]);
                    list.add(subList);
                    while(L < R && nums[L] == nums[L + 1]) L++;
                    while(L < R && nums[R] == nums[R - 1]) R--;
                    L++;
                    R--;
                }
                else if(sum < 0) L++;
                else R--;
            }
        }
        return list;
    }
}
```
