package 四数之和;
import java.util.*;
public class Solution {
	public List<List<Integer>> fourSum(int[] nums, int target) {
		int i, j, m, n;
		List<List<Integer>> result = new ArrayList<List<Integer>>();
		//排序，方便指针移动
		Arrays.sort(nums);;
		for (i = 0; i < nums.length - 3; i++) {
			//去重
			while (i > 0 &&i<nums.length&& nums[i] == nums[i - 1])
				i++;
			for (j = i + 1; j < nums.length - 2; j++) {
				//去重
				while (j > i + 1 &&j<nums.length-2&& nums[j] == nums[j - 1])
					j++;
				m = j + 1;
				n = nums.length - 1;
				while (m < n) {
					List<Integer> temp = new ArrayList<Integer>();
					if (nums[i] + nums[j] + nums[m] + nums[n] == target) {
						temp.add(nums[i]);
						temp.add(nums[j]);
						temp.add(nums[m]);
						temp.add(nums[n]);
						result.add(temp);
						//去重
						while (m<n&&m+1<nums.length&&nums[m] == nums[m + 1])
							m++;
						while (m<n&&nums[n] == nums[n - 1])
							n--;
						m++;
						n--;
					} 
					else if(nums[i] + nums[j] + nums[m] + nums[n]<target)
						m++;
					else {
						n--;
					}
				}

			}
		}

		return result;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
           Solution solution=new Solution();
           int[] nums=new int[] {-7,-5,0,7,1,1,-10,-2,7,7,-2,-6,0,-10,-5,7,-8,5};
           int target=28;
           System.out.println(solution.fourSum(nums, target));
	}

}
