
- 如果数组所有元素的最大公约数为1，则满足条件
- 求所有数组的最大公约数即可
```
    public boolean isGoodArray(int[] nums) {
        if (nums.length == 1)return nums[0] == 1;
            for (int i = 1; i < nums.length; i++) 
                c = bcd(nums[i],nums[i-1]);
        return c == 1;
    }
    //求两个数的最大公约数
    private int bcd(int a, int b) {
        if (0 == b)return a;
        if (a<b)return bcd(b,a);
        return bcd(a%b,b);
    }
```


