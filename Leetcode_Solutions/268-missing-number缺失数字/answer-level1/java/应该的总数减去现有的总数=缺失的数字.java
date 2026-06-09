   先求出现有数列的和
   应该的数列和则根据等差数列求和公式Sn = n * (A0 + An) / 2求出
   两者相减求出缺损数字

        int sum = 0;
        for (int i = 0; i < nums.length; i ++) {
        	sum += nums[i];
        }
        
        return (nums.length + 1) * nums.length / 2 - sum;