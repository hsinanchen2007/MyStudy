本题要明确，输出的最大值为nums.length+1
所以可以遍历nums，使nums[i]=i
然后再遍历一次nums,找到nums[i]!=i的地方，输出

public int firstMissingPositive(int[] nums) {
    if(nums.length<=0)
        return 1;

    int n = nums.length;
    for(int i=0; i<n; i++){
        while(nums[i]>0 && nums[i]<n && nums[i]!=i){    
            if(nums[nums[i]%n]==nums[i]%n)      //当要交换的Nums[i]已经等于i时，就跳出循环
                break;
            int temp = nums[i];             //否则交换
            nums[i] = nums[nums[i]%n];
            nums[temp%n] = temp;
        }
    }

    for(int i=1; i<n; i++){
        if(nums[i]!=i)
            return i;
    }

    return nums[0]==n ? n+1 : n;
}