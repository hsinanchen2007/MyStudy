要求:
1 必须在原数组上操作，不能拷贝额外的数组
2 尽量减少操作次数

解法一
```
    void moveZeroes(vector<int>& nums) {
        int zeroIndex = 0;
        for (int i = 0; i < nums.size(); ++i) 
            if (nums[i])
                nums[zeroIndex++] = nums[i];
            
        for (; zeroIndex < nums.size(); ++zeroIndex)
            nums[zeroIndex] = 0;
    }
```

解法二
```
    void moveZeroes(vector<int>& nums) {
       //必须在原数组上操作，不能拷贝额外的数组
       //尽量减少操作次数
       int zeroIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0)
                if (i != zeroIndex)
                    swap(nums[i], nums[zeroIndex++]);
                else
                    zeroIndex++;
        }
    }
```
