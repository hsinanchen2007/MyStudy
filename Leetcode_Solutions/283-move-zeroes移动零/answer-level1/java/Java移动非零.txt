![image.png](https://pic.leetcode-cn.com/105059457bfbe8a8d8324eecc3e6282ee9fa0f19db4a65b3c5928102f06e9461-image.png)
```
思路：
    （1）遍历数组，遇到不是0的就放在数组的最前面，索引记录进行++，不是0的数量记录进行++
    （2）第一个应该为0的元素（即索引为非0的数值数量）开始赋值为0
public void moveZeroes(int[] nums) {
        int count = 0;
        for (int i = 0,j = 0; i < nums.length; i++) {
            if (nums[i] != 0){
                nums[j++] = nums[i];
                count++;
            }
        }
        for (int i = count; i < nums.length; i++) {
            nums[i] = 0;
        }
    }
```


