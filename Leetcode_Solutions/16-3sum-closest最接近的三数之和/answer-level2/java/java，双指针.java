这道题目和三数之和几乎是一样的思想，没有什么差别。完全是换汤不换药。唯一的差别就是，使用一个min变量，记录全局中最接近target的三个数的和。然后返回min，当然，如果正好有三个数之和就是target，那么min此时就是target
```
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int min=Integer.MAX_VALUE;
        int len=nums.length;
        int res=0;
        for(int i=0;i<len;i++)
        {
            int left=i+1;
            int right=len-1;
            while(left<right)
            {
                int temp=nums[i]+nums[left]+nums[right];
                int distance=Integer.MAX_VALUE;
                distance=Math.abs(temp-target);
                //全局范围内距离最近的值
                if(distance<min)
                {
                    min=distance;
                    res=temp;
                }
                //根据三个数加起来的情况，移动指针
                if(temp<target)
                {
                    left++;
                }else if(temp>target)
                {
                    right--;
                }else
                {
                    return  target;
                }
            }
        }
        return res;
    }
```
