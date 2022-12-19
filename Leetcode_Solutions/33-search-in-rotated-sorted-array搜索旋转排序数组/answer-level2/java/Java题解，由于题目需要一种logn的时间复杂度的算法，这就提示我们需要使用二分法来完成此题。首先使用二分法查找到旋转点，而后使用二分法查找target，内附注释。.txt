class Solution {
    public int search(int[] nums, int target) {
        
        int n = nums.length;
        int s1=0;
        int s2=0;//判定输出结果是否有效
        
        if(n==0)//长度为0
        {
            return -1;
        }
        
        //首先以二分法先寻找旋转点
        int left=0;
        int right=n-1;
        int rot = 0;//旋转点下标
        if(nums[0]<=nums[n-1])//这里用来判断数组是否进行了旋转
            //如果未进行旋转，则旋转点下标为0
        {
            rot=0;
        }
        else
        {//数组进行了旋转，使用二分法差点旋转点下标
        while(left<=right)
        {   
            int mid = (left+right)/2;
            
            if(nums[mid]>nums[mid+1])
            {
                rot=mid+1;
                break;//查找旋转点下标判断方法：前一个数大于后一个数
            }
            else
            {
                if(nums[mid]>=nums[left])//这里注意，因为是旋转数组，所以left和right的变换条件要有参照物
                    //这里是以nums[left]为参照的
                {
                    left=mid+1;
                }else
                {
                    right=mid-1;
                }
            }
        }
        }
        //旋转点即为nums[rot],同时旋转点也为数组中最小的那个数
        //再根据旋转点将数组分为两半，对其再使用二分法查找目标值。
        
        if(nums[rot]==target)
        {
            return rot;
        }
        else //因为旋转点为数组中最小的数
            //所以需要进行两次二分法的判断
            //例如题目的示例2：查找3，需同时在两边进行查找
        {
            s1=sea(0,(rot-1),target,nums);//0-(旋转点下标-1)
            s2=sea(rot,n-1,target,nums);//旋转点下标-(n-1)
        }
        
        if(s1==-1 && s2==-1)//判定最终输出
        {
            return -1;
        }
        else
        {
            if(s1==-1)
            {
                return s2;
            }
            else
            {
                return s1;
            }
        } 
               
    }
    
    public int sea(int left,int right,int target,int[] nums)//二分法查找数
    {
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return -1;
    }
}