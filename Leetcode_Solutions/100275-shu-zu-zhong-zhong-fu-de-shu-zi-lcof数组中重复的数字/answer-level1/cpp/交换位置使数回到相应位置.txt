请认真看完根据样例做出的算法分析过程，这样有助于理解算法。
解题思路：数组中n个数的范围为0～n-1，如果没有重复数字，那么每个数字都在对应位置，例如nums[0]=0,nums[1]=1，以此类推。现在出现了重复数字，说明有些数字在对应位置上出现过(nums[nums[i]]==nums[i])，还在其他位置也出现过(nums[i]!=i)。所以有如下的思路，遍历数组中的数字，如果数字在对应位置，不作处理，数字不在对应位置，先看数字在是否等于对应位置的数字，如果不等于，就进行交换，如果等于，那么该数字重复。
```
拿样例举例
1 3 2 0 2 5 3
i=0 (nuns[i]=1) != (i=0)
    (nums[i]=1) != (nums[nums[i]]=3)
    swap(nums[i],nums[nums[i]])
    数组变为3 1 2 0 2 5 3

i=0 (nums[i]=3) != (i=0)
    (nums[i]=3) != (nums[nums[i]=0])
    swap(nums[i],nums[nums[i]])
    数组变为0 1 2 3 2 5 3

i=1 i=2 i=3都符合nums[i]==i

i=4 (nums[i]==2) != (i=4)
    但nums[nums[i]]=2，即已经出现过
    所以2是重复数字
    结束程序返回2
```
看了下样例，样例中有两个重复数字，结果是2或者3都可以AC。于是我根据样例写出了两种版本的代码，核心思想不变，只是结束条件有所改变。
代码如下:
```
//找到重复的数字2
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int ans=0;
        bool res=false;
        for(int i=0;i<nums.size() && res!=true;i++)
        {
            while(nums[i]!=i)
            {
                if(nums[i]!=nums[nums[i]])
                {
                    swap(nums[i],nums[nums[i]]);
                }
                else
                {
                    ans=nums[i];
                    res=true;
                    break;
                }
            }
        }
        return ans;
    }
};
```

```
//找到重复的数字3
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]!=i)
            {
                if(nums[i]!=nums[nums[i]])
                {
                    swap(nums[i],nums[nums[i]]);
                }
                else
                {
                    ans=nums[i];
                    break;
                }
            }

        }
        return ans;
    }
};
```

