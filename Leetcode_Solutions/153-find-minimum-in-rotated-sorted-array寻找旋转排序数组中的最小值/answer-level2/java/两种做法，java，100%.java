这道题目比《***》中那道题目简单，因为它规定了数组中不存在重复元素。

**注意：这道题中有个重要的地方需要理解，就是那个三个min对于。必须有这三个语句，否则会出现`[4,5,6,7,0,1,2] ，返回1的这种错误。原因在于：由于使用了mid+1和mid-1这个操作，所以导致i和j位置所在的值会被忽略（因为每次只对于mid的值），因此必须对i和j所在的位置也进行对比。这样跳跃过后不会发生错误。`**

---

**题解一：**

自己写的

```java
   public int findMin(int[] nums) {
        int len=nums.length;
        if(len==0)
        {
            return -1;
        }
        int i=0;
        int j=len-1;
        int min=Math.min(nums[0],nums[len-1]);

        while(i<=j)
        {
            int mid=i+(j-i)/2;
            //这里三个min是关键
            min=Math.min(nums[i],min);
            min=Math.min(nums[j],min);
            min=Math.min(nums[mid],min);
            if(nums[i]<nums[mid])
            {
                i=mid+1;
            }else
            {
                j=mid-1;
            }
        }
        return min;
    }
```



**题解二：**

这是leetcode的官方题解。

关键思想是：对于数组中的某一段来说，只要右边的数字比左边的大，那么这段区间内，一定是有序的。

```JAVA
public int findMin(int[] nums) {
    if (nums.length == 1) 
    {
      return nums[0];
    }
    int left = 0, right = nums.length - 1;
    if (nums[right] > nums[0])
    {
      return nums[0];
    }
    while (left<=right)
     {
          int mid = left + (right - left) / 2;
		  //这个的两个if和上边自己写的三个min是一样的作用。	
          if (nums[mid] > nums[mid + 1])
          {
            return nums[mid + 1];
          }
          if (nums[mid - 1] > nums[mid]) {
            return nums[mid];
          }
		  //只要右边比左边大，那么这一段一定是有序的
          if (nums[mid] > nums[0]) {
            left = mid + 1;
          } else {
            right = mid - 1;
     	  }
    }
    return -1;
  }
```



