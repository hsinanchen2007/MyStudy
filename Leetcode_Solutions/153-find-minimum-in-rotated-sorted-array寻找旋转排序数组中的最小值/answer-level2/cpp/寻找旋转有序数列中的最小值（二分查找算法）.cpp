# 寻找旋转有序数列中的最小值（二分查找算法）
对于有序序列，使用BF算法显然不明智，虽然此题的输入序列是旋转过的有序序列，但是仍然可以用二分查找算法解决。
## 解题思路
寻找到更新l值/r值的两种情况，最终逼近最小值。
1. 何时更新l值 eq. list:3,4,5,6,7,8,9,0,1，这里l=0, r=8, m=4, target=7
    显然，想要的更新操作是 l=m+1，那么判断条件是什么？ 
    **list[r] < list[m]**
    解释：list[r] < list[m]说明m->(target-1)升序，target->r升序，
    令l=m+1, 缩小了查找范围，且保证在target在此范围内。 
2. 何时更新r值 eq. list:7,8,0,1,2,3,4,5,6，这里l=0, r=8, m=4, target=7
    此时想要的更新操作是 r=m，那么判断条件是什么？ 
    **list[r] > list[m]**
    解释：list[r] > list[m]说明l->(target-1)升序，target->m升序，
    令r=m, 缩小了查找范围，且保证在target在此范围内。 
3. 特殊情况 eq. list:0,1,2,3,4,5,6,7,8，这里l=0, r=8, m=4, target=7
    显然，这种情况在2中是兼容的，无需另外考虑。

## c++实现代码
```
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int m, l = 0, r = nums.size()-1;
        while(l < r){
            m = (l + r) / 2;
            if (nums[m] > nums[r])
                l = m+1;
            else
                r = m;
        }
        return nums[l];
    }
};
```
