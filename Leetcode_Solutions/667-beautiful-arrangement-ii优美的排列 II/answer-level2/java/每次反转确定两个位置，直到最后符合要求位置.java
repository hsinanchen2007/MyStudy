这题直接生成很简单，自己做的方法太傻了，但是既然写了还是贴出来吧，每一次过程生成符合k和k-1的的位置，并令k = k -2，不断循环到k = 0为止。
```
class Solution {
    public int[] constructArray(int n, int k) {
        int[] ans = new int[n];
        for(int i = 0;i < n;i++)
        {
            ans[i] = i+1;
        }
        while(k > 0)
        {
            process(ans,k);
            k = k - 2;
        }
        return ans;
    }
    
    private void process(int[] nums,int k)
    {
        for(int i = 0;i < k-1;i++)
        {
            swap(nums,i,i+1);
        }
    }
    
    public void swap(int[] nums,int i,int j)
    {
        nums[i] = nums[i]^nums[j];
        nums[j] = nums[i]^nums[j];
        nums[i] = nums[i]^nums[j];
    }
}
```
