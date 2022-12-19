```
 public void moveZeroes(int[] nums) {
        if(nums == null || nums.length == 0 || nums.length == 1) return;
        int i = 0,j = 0,size = nums.length;
        while(i < size && j < size){
             while(nums[i] != 0 && ++i < size);
             if(j <= i) j = i + 1;
             if(j >= size)  return;
             while(nums[j] == 0 && ++j < size);
             if(j >= size)  return;
             nums[i] = nums[j];  
             nums[j] = 0;
             i++;j++;
        }
    }
```
![image.png](https://pic.leetcode-cn.com/40a40203868964086add8d0fd44031c21b88322c09b3bbaeb4b1ca0f1587315e-image.png)

这个内存消耗怎么计算的 那位大佬能讲解下