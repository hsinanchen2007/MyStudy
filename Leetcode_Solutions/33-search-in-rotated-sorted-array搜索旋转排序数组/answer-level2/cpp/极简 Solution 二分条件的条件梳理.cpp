> 参考 https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/ji-jian-solution-by-lukelee/
> 的题解，他的答案很精巧，难点在于关于移动二分的左还是右，因此写这个题解帮助读者梳理条件的判断。

## 思路
+ 使用二分查找
+ 找到目标
+ 完事儿

## 定义
按照我们将整个数组先分为高处和低处，高处在左侧，低处在右侧，两者都是递增的，同时低处的最大值小于高处的最小值，即如图。
```

（高处）           
       ╱
    ╱
 ╱
             ╱
          ╱     （低处）
------------------------------
 0 1 2 3 4 5 6 7 ...
````
> 抽象派大师作画别在意。

## 条件划分
+ 由于数组不是单调递增
+ 所以移动左还是移动右要分条件
+ 不妨作图协助分析
+ 作图省略对等号的判断
```

                                            ┌ nums[mid] > target（移动右点）  
                                            │   
                   ┌ nums[mid] < nums[0] ─┼ 
                   │ （中点在右侧）        │
                   │                       └ nums[mid] < target (移动左点)
nums[0] > target ─┼
(目标在低处)       │
                   │
                   └ nums[mid] > nums[0] ── 移动左点 (此时肯定有 nums[mid] > target)
                     （中点在左侧）
                 
                               
                   ┌ nums[mid] < nums[0] ── 移动右点 (此时肯定有 nums[mid] < target) 
                   │ （中点在右侧）  
                   │           
nums[0] < target ─┼
(目标在高处)       │                       ┌ nums[mid] > target（移动右点）   
                   │                       │
                   └ nums[mid] > nums[0] ─┼
                      （中点在左侧）        │
                                            └ nums[mid] < target (移动左点)

```
## 分析
已经有了对条件的梳理，我们不妨得出一个结论。
只要
+ nums[0] > target
+ nums[mid] < nums[0]
+ nums[mid] < target

这三个条件中，符合一个或三个，就移动左点，否则移动右点。
由此可以想到使用异或的方式，来写代码。

## 代码
``` c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r){
            mid = l + (r - l) / 2;
            if ((nums[0]> target) ^ (nums[mid] < nums[0]) ^ (nums[mid] < target))
                l = mid + 1;
            else
                r = mid;
        }
        return l == r && nums[l] == target? l:-1;
    }
};
```