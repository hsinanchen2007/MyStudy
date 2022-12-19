```
public int removeDuplicates(int[] nums) {
        //这个题不排除空数字过不了
    	if(nums.length==0) return 0;
    	//记录相同数字出现的次数
        int times=1;
        int left=0;
        int right=0;
        while(true)
        {
            nums[left]=nums[right];
            right++;
            //将循环结束条件放在这里比直接放在while里更加合理，以为上边进行right++以后，有可能会导致下边nums[right]溢出
            if(right>=nums.length)
            {
                break;
            }
            //如果是相同的，那么就要判断是第几次出现，对于小于2次的出现，需要正常left++并在下一轮while中赋值
            //如果超过2次，left不移动，下一次while循环会赋给相同位置一个相同的值，这样就相当于删除了一个相同数字
            if(nums[left]==nums[right])
            {   
                times++;
                if(times<=2)
                {
                    left++;
                }
            }
            //如果不相同，那说明遇到了新的数字，就不用判断了，直接正常left++并在下一轮中赋值，同时要让times重新置1
            else
            {
                times=1;
                left++;
            }
        }
        return left+1;
    }
```
