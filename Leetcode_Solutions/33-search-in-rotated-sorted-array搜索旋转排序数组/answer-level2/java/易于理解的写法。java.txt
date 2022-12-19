  public int search(int[] nums, int target) {
      int len=nums.length;
      if(len==0)
      {
          return -1;
      }
      int i=0;
      int j=len-1;
      int min=0;
      //寻找全局最小点
      while(i<j)
      {
          int mid=i+(j-i)/2;
          //这个循环真正能够结束的条件是 j-i==1的时候，而不是利用i<j的来结束的。
          //注意：没有j-i<=1，只用while(i<j)会陷入死循环，因为更新节点是到mid而不是mid+1，当只剩两个数字的时候，永远进行不完
          //（包括<0是为了防止单个元素数组的情况）
          if((j-i)<=1)
          {
              //这里可能出现正好j是全局最小点，也有可能这是一个全升数组，i是最小点
              min=nums[i]>nums[j]?j:i;
              break;
          }
          //迭代更新两端
          if(nums[i]<nums[mid])
          {
             i=mid;
          }else
          {
              j=mid;
          }
      }

    //判断target到底属于哪个区间，是最小点左边区间还是最小点右边区间
    if(target<=nums[len-1]&&target>=nums[min])
    {
        i=min;
        j=len-1;
    }else if(min<=1||(target>=nums[0]&&target<=nums[min-1]))
    {
        i=0;
        j=min;
    }//这里不用加else判断target不属于左右两个区间的任何一个这种情况，是因为
    //如果target不属于任何一个区间，那么此时j=i+1,那么下边二分搜索中的mid只会经过一轮
    //对比就会直接跳出下边二分搜索循环，直接返回-1；

    //确定区间后的就是一个全升的区间，直接二分搜索就可以
    while(i<=j)
    {   int mid=i+(j-i)/2;
        if(target>nums[mid])
        {   
             i=mid+1;
        }else if(target<nums[mid])
        {
             j=mid-1;
        }else
        {
            return mid;
        }
    }
    return -1;
    }