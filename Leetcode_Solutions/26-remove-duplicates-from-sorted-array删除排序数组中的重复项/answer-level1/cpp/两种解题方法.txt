## 利用set
利用了set元素的唯一性，申请了额外的空间来实现
```
int removeDuplicates(vector<int>& nums) {
        int i, len = nums.size();
        set<int> ms;
        for(i=0; i<len; i++)
        {
            ms.insert(nums[i]);
        }
        len = ms.size();
        set<int>::iterator it;
        for(i=0, it=ms.begin(); i<len; i++, it++)
            nums[i] = *it;
        return len;
    }
```

## 双指针
指针 i、j，直到 j 指向不同值的下标时，nums[i+1] = nums[j]，然后 i、j 都自增1，最后返回 i+1。
注意边界情况的判断（ j 始终比 i 大，所以只用拿 j 做判断即可）。
```
int removeDuplicates(vector<int>& nums) {
        int i=0, j=1, len=nums.size();
        if( !len ) return 0;
        while( j < len )
        {
            while( j<len && nums[i] == nums[j] )
                j++;
            if( j < len )
            {
                if( i+1 != j )
                    nums[i+1] = nums[j];
                i++;
                j++;
            }
        }
        return i+1;
    }
```