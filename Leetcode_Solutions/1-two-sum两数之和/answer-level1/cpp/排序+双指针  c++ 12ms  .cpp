**快是快但是内存消耗太大了，就是写着试试**
思想很简单，就是排序后，左右两个指针j向中间移动，直到找到答案或j指针汇合
细节处理比较麻烦所以看起来e很多，多备份了一个数组，所以内存开销很大。
a和b可以不用定义，但是这样写着方便

```
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> back = nums;//备份nums
        auto a = back.begin();
        auto b = back.end();
        sort(nums.begin(), nums.end());//排序
        int len = nums.size();
        int i = 0, j = len - 1;
        while (i < j)
        {
            if (nums[i] + nums[j] == target)
            {
                int x ,y;
                if(nums[i]==nums[j]){      //两个加数值相等时需要在find第一个后改变数组中它的值，如[3，3] 
                    x = (int)(find(a, b, nums[i]) - a);
                    back[x]=back[x]+1;
                    y = (int)(find(a, b, nums[j]) - a);
                }
                else {
                    x = (int)(find(a, b, nums[i]) - a);
                    y = (int)(find(a, b, nums[j]) - a);
                }    
                if(x>y)                     //返回升序结果
                    return {y, x};
                else
                    return {x, y};
            }
            else if (nums[i] + nums[j] > target)//大于目标，右边指针左移
                j--;
            else                                //小于目标，左边指针右移
                i++;
        }
        return {};                              //没有找到
    }
};
```
