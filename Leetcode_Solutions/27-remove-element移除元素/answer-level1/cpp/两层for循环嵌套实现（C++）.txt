### 解题思路
使用外层for循环从头到尾检查一遍数组，当发现等于val的值时，再用内层for循环将该值与从数组末尾开始不等于val的值交换。利用count统计不等于val的值的个数，这样数组中前count个数都是不等于val的值。
【注意】：内存for循环处必须交换两个值，而不仅仅是赋值：nums[i]=nums[j]，不然nums[j]处原来的值会被重复统计。

### 代码

```cpp
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int count=0;
        for(int i=0;i!=nums.size();i++)
        {
            if (nums[i]==val )
            {
                for (int j=nums.size()-1;j>i;j--)
                {
                    if (nums[j]!=val)
                    {
                        int temp=nums[i];
                        nums[i]=nums[j];
                        nums[j]=temp;
                        count++;
                        break;
                    } 
                }
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};
```