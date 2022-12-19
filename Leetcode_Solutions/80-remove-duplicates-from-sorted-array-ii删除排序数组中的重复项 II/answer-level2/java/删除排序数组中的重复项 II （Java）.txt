自己想的解法，感觉挺通俗简单易懂。
```
public int removeDuplicates(int[] nums) {
        if(nums.length < 3){
            return nums.length;
        }
        int index = 2;
        int flag = 2;
        for(int i=2;i<nums.length;i++){
            //初始偏移值为2 只要去除一个元素  则偏移值+1
            if(nums[i] != nums[i-flag]){
                nums[index] = nums[i];
                index++;
            }else{   //有两个相等的情况下 跳过第三个相同数的记录
                //偏移值+1
                flag++;
                continue;
            }
        }
        return index;
    }
```
