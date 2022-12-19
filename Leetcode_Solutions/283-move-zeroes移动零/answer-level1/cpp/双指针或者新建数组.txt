方法一 拷贝额外的数组
     
```
    void moveZeroes(vector<int>& nums) {  
        if(nums.size() == 1) return;
        vector<int> ans;
        <!-- 非零元素先放前面 -->
        for(int i:nums)
        {
            if(i != 0)
                ans.push_back(i);
        }
        <!-- 填补零元素 -->
        for(int i:nums)
        {
            if(i == 0)
                ans.push_back(i);
        }
        nums = ans;
    }
```

方法二 双指针
```
   void moveZeroes(vector<int>& nums) {   
        if(nums.size() == 1) return;
        int i,j;
        for(i = 0;i<nums.size()-1;i++)
        {
            //慢指针先指向零元素
            if(nums[i] == 0 )
            {
                j = i;
                //移动快指针 直到找到第一个非零元素或者指到了末尾
                //若指到最后一个元素且为0 则结束
                while(j < nums.size()-1 && nums[++j] == 0 );
                if(nums[j] == 0) return;    //最后一个元素为0
                swap(nums[i],nums[j]);
            }
        }
   }
```

    


