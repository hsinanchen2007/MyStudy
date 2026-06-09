完成了题目给出的两种方法，一种是计数排序，一种是原地算法

# 1.计数排序

计数排序是一种适用在一些特殊场合下的排序方法，我们知道通用的的排序方法最佳的时间复杂度为O(nlogn)，而计数排序则能达到O(n)。当然计数排序是有限制的，但在这题能很好的运用计数排序。
因为题目已经给出了数组元素的限制（只可能是0，1，2）。假如让我们排序一个只有0-100出现的数组，也是可以使用计数排序的。

代码如下（击败100%的c++提交）：
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;     //若是只有0-100排序，可以用数组count[100]来代替，这里我偷懒用了3个变量
        int white = 0;
        int blue = 0;
        for(auto i : nums)
        {
            if(i == 0)
                red++;
            if(i == 1)
                white++;
            if(i == 2)
                blue++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(red > 0)
            {
                nums[i] = 0;
                red--;
                continue;
            }
            else if(white > 0)
            {
                nums[i] = 1;
                white--;
                continue;
            }
            else if(blue > 0)
            {
                nums[i] = 2;
                blue--;
                continue;
            }
        }
    }
};
```

# 原地算法

如下（击败90.22%的c++提交）
```
class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i;j<nums.size();j++)
            {
                if(nums[i]>nums[j])
                    swap(nums[i],nums[j]);
            }
        }
    }
};
```



