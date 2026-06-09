注意题目里面的
**假设你总是可以到达数组的最后一个位置。**

如果没有这个假设，贪心算法的方式是不能保证能达到全局最优解的，需要回溯或动态规划的方式进行解决
**1.回溯法（本题样例通过91/92）**
```
class Solution {
    int ans=Integer.MAX_VALUE;
    Map<Integer,Integer> map=new HashMap<>();
    public int jump(int[] nums) {
        if(nums.length==0)
            return 0;
        helper(nums,0,0);
        return ans== Integer.MAX_VALUE?0:ans;
    }
    public void helper(int[] nums,int index,int cnt) {
        if(map.get(index)==null) map.put(index,cnt);
        else if(map.get(index)<=cnt)  return;
        if (index >= nums.length)
            return;
        if (index == nums.length - 1) {
            if (cnt < ans) ans = cnt;
            return;
        }
        for (int i = nums[index]; i > 0; i--) {
            helper(nums, index + i, cnt + 1);
        }
    }
}
```
**2.贪心算法**
```
public class Solution {
	public int jump(int[] nums) {
        int n = nums.length;
        int steps = 0;
        int index = 0;
        while(index < n - 1) {
        	steps++;
        	int[] lengths = new int[nums[index]];
        	if(index + nums[index] >= n - 1) {
        		break;
        	}
        	for (int i = index + 1; i <= index + nums[index]; i++) {
				lengths[i - index - 1] = i + nums[i];
			}
        	int max = 0;
        	for (int i = 0; i < lengths.length; i++) {
				if(lengths[i] > lengths[max]) {
					max = i;
				}
			}
        	index = max + index + 1;
        }
        return steps;
    }

```
