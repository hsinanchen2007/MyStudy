public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
        IList<IList<int>> ans=new List<IList<int>>();
        if(nums==null||nums.Length<4) return ans;
        Array.Sort(nums);
        for(int i=0;i<nums.Length-3;i++)
        {
            if(i!=0&&nums[i]==nums[i-1]) continue;
            if(nums[i]>target/4) break;
            for(int j=i+1;j<nums.Length-2;j++)
            {
                if((j!=i+1&&nums[j]==nums[j-1])) continue;
                int sum=target-nums[i]-nums[j];
                int start=j+1;
                int end=nums.Length-1;
                while(start<end)
                {
                    if(sum==nums[start]+nums[end])
                    {
                        ans.Add(new int[]{nums[i],nums[j],nums[start],nums[end]});
                        while(start<end&&nums[start]==nums[start+1])    start++;
                        while(start<end&&nums[end]==nums[end-1])    end--;
                        start++;
                        end--;
                    }
                    if(start<end&&sum<nums[start]+nums[end]) end--;
                    if(start<end&&sum>nums[start]+nums[end]) start++;
                }
            }
        }
    return ans;
    }
}