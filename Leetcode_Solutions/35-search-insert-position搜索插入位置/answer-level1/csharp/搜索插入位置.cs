**思路1：** 遍历数组
```
public int SearchInsert(int[] nums, int target) {
        for(int i = 0; i<nums.Length;i++)
        {
            if(nums[i]>target) return i;
            if(nums[i] == target) return i;
        }
        return nums.Length;

    }
```

**思路2：** 二分查找的变式，存下mid的值，如果找不到目标值，就将目标值和最后一个mid值进行对比，返回最终应该插入的位置索引。
```
public int SearchInsert(int[] nums, int target)
        {
            int left = 0;
            int right = nums.Length - 1;
            int mid = 0;

            //为什么<=而不是<，试试{1}，1
            while (left <= right)
            {
                //mid = (left + right)/2, 这种写法在left+right的时候可能内存溢出
                mid = left + (right - left);
                if (nums[mid] == target)
                {
                    return mid;
                }
                else if (nums[mid] < target)
                {
                    //为什么mid+1，mid-1，而不是mid
                    //试试{1}，2，会死循环
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            if (mid > 0 && nums[mid] > target)
            {
                mid = mid - 1;
            }
            else if(nums[mid] < target)
            {
                mid = mid + 1;
            }

            return mid;
        }
```
**注：** 如果在leetcode中提交代码你会发现思路1时间消耗更少，其实这个时间非常依赖测试数据，如果测试数据很小，而且目标值很靠前，思路一占优势。