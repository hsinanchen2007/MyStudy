```
public int findLengthOfLCIS(int[] nums) {
        if(nums.length==0) return 0;
        int temp = nums[0];//取第一个作为临时
        int max = 0;
        int count = 1;
        for(int i: nums){
             if(i > temp){
               count++;
              }else{// 1.取连续增长最大值 2.初始化计数
               max = Math.max(count,max);  //math.max() 写在else里面可以减少比较次数
               count = 1;
             }
             temp = i; 
        }
        return Math.max(count,max);
    }
```
