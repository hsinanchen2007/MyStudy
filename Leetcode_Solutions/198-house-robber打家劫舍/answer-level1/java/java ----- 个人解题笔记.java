f(n) = max(f(n-2)+n,f(n-1));
难点是找到递推公式（想了5分钟没有想出来，看了标准答案）
递推直接写代码：：//超出时间限制
测试（[114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240]）的时候；
```
 int[] nums;
    public int rob(int[] nums) {
        this.nums = nums;
        int n = nums.length;
        return maxSteal(n);
        //递推公式是关键 f(n) = Max(f(n-2)+ nums[n],f(n-1); f(1) = nums[0],f(0) = 0;
    }
    int maxSteal(int n){
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return nums[0];
        }
        
        return Math.max((maxSteal(n-2)+nums[n-1]),maxSteal(n-1));
    }
```
递归有很多的重复计算，用迭代试试；有从前往后的迭代（也是dp问题的主要特点之一），有从后向前迭代（不知道怎么写）；
```
 public int rob(int[] nums) {
        this.nums = nums;
        int n = nums.length;
        //递推公式是关键 f(n) = Max(f(n-2)+ nums[n],f(n-1); f(1) = nums[0],f(0) = 0;
        
        int currentMax2 = 0;
        int currentMax1 = 0;
        for(int i = 0; i < n; i++){
            int temp = currentMax1;
            currentMax1 = Math.max(currentMax2+nums[i],currentMax1);
            currentMax2 = temp;;
        }
        
        return currentMax1;
    }
```

