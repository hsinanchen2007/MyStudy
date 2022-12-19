Hash思路，遍历一遍数组array，若array[i]在数组下表范围内（0 - array.length)，则将array[i] 与  array[array[i] - 1]交换位置。具体看一下例子:
Target: [3,4,-1,1]
Step 1: [-1,4,3,1] （使array[3-1] 与 array[0]交换位置）
Step 2: [-1,4,3,1] （因为此时array[0]不在数组范围内，所以不变）
Step 3: [-1,1,3,4] （使array[4-1 与 array[1]交换位置）
Step 4: [1,-1,3,4] （使array[1-1]与 array[1]交换位置）
Step 5：再次遍历数组，找到答案
还有一些小问题可以看我的代码（有点丑陋，见谅OvO）：
```
    public int firstMissingPositive(int[] nums) {
        if(nums.length < 1) return 1;
        int index = 0; 
        while (index < nums.length) {
            if (nums[index] >= 1 &&
                nums[index] <= nums.length &&
                nums[index] != index+1 &&
                nums[nums[index]-1]!=nums[index])  //判断要交换的两个数是否相等
            {
                int temp = nums[nums[index]-1];
                nums[nums[index]-1] = nums[index];
                nums[index] = temp;
            }else{
                index++;
            }
        }
        
        int rst = 1; //再次遍历找到答案
        
        for(int i = 0; i < nums.length; i++){
            if(nums[i] != i+1) break;
            else rst++;
        }
        
        return rst;
    }
```

