单层循环数组，
定义两个参数：count；i；
count计录数组中非0的个数，
i表示循环到到数组的第几位；
循环数组的过程中，发现nums[i]不为0，count++；
并且将当前的nums[i] 赋值给nums[count-1];这里为什么是count-1呢，因为count是数量，不是下标 减1之后才是下标；
nums[i]变成0；做这一步的好处是不用再次循环，将数组后面的数字全部置为1。

```

 public void moveZeroes(int[] nums) {
        int count =0; //非0的个数
        int i =0;
        while(i<nums.length){
          
            if(nums[i]!=0){
                 count++;
                if(count<i+1){
                   
                    nums[count-1] = nums[i];
                    nums[i] =0;
                   
                }     
            }
            i++;

        }

    }
```
