**第一种方法（暴解） 面向测试用例**
最后一个用例是基本都是1和-1 所以直接跳过就不会超时，不过时间效率太低
```
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        Arrays.fill(res,1);

        for(int i=0;i<nums.length;i++)
        {   if(nums[i]==1)
            continue;
            for(int j=0;j<nums.length;j++)
            {   if(j==i)
                continue;
                res[j] *= nums[i];
            }
        }
        return res;
    }
```
**第二种方法 用一个left[]和right[]进行保存i左边和右边的乘积 **
两次遍历得到结果
```
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];
        Arrays.fill(left,1);
        Arrays.fill(right,1);
        for(int i=0;i<nums.length;i++)
        {   if(i==0) {
            left[i] = nums[i];
            continue;
        }   left[i] = nums[i]*left[i-1];
        }
        for (int i = nums.length-1; i >=0; i--) {
            if(i==nums.length-1) {
                right[i] = nums[i];
                continue;
            }right[i] = nums[i]*right[i+1];
        }
        for(int i=0;i<nums.length;i++)
        {   if(i==0)
        {
            res[i] = right[i+1];
            continue;
        }
        if(i==nums.length-1)
        {
            res[i] = left[i-1];
            continue;
        }
            res[i] = left[i-1]*right[i+1];
        }
        return res;
    }
```

**第三种跟第二种差不多，其实我们用一个常量去保持右边遍历的right[] 就可以了 然后一直更新left[] 就可以达到空间复杂度为O（n）的情况**
首先还是遍历一次left[],其次从后往前更新乘积即可
```
    public int[] productExceptSelf(int[] nums) {
        int[] res = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            if(i==0)
            {
                res[i] = nums[i];
                continue;
            }
            res[i] = res[i-1]*nums[i];
        }
        int right = 1;
        for(int i=nums.length-1;i>=0;i--)

        {   if(i==0)
        {
            res[i] = right;
            continue;
        }
            res[i] = right*res[i-1];
            if(i==nums.length-1)
            {
                right = nums[i];
            }
            else
                right = right*nums[i];

        }
return res;
    }
```


