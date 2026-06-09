##  解法1：

```C++ []
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;//慢指针
        for(int j=0//快指针;j<nums.size();j++)
        {
            if(nums[j]!=val)//寻找不需要剔除的元素
            {
                nums[i]=nums[j];
                i++;
            }
        }
        return i;
    }
};
```

##  解法2：
主要思想：当遇到val==nums[i]时，将当前元素与最后一个元素替换，并释放最后一个元素。
```C++ []
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            if(nums[i]==val)
            {
                nums[i]=nums[n-1];
                n--;
            }
            else i++;
        }
        return n;
    }
};
```
**觉得本文对你有帮助，点个赞噢谢谢**
