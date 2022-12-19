### 解题思路
此处撰写解题思路
鄙人菜鸡
首先判断其中一个容器是否为空，如果为空，则直接计算另一个容器内得中位数
其次判断一个容器的最小值是否大于另一个容器的最大值，如果满足，则直接进行插入运算，然后求中位数
最后一般情况，遍历nums1，如果nums2的值小于nums1的值，则进行插入运算，最后如果nums2没有遍历完，则直接将剩余的数插入到nums1末尾。
### 代码

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0)
        {
            if(nums2.size()%2==0)
            {
                return (double)(nums2[nums2.size()/2]+nums2[nums2.size()/2-1])/2;//偶数
            } else
                return nums2[nums2.size()/2];//奇数
        }
        if(nums2.size()==0)
        {
            if(nums1.size()%2==0)
            {
                return (double)(nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2;//偶数
            } else
                return nums1[nums1.size()/2];//奇数
        }
        if(nums2.front()>nums1.back())
        {
            for(vector<int>::iterator it2=nums2.begin();it2!=nums2.end();it2++)
            {
                nums1.push_back(*it2);
            }
            if(nums1.size()%2==0)
            {
                return (double)(nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2;//偶数
            } else
                return nums1[nums1.size()/2];//奇数
        }
        if(nums1.front()>nums2.back())
        {
            for(vector<int>::iterator it2=nums1.begin();it2!=nums1.end();it2++)
            {
                nums2.push_back(*it2);
            }
            if(nums2.size()%2==0)
            {
                return (double)(nums2[nums2.size()/2]+nums2[nums2.size()/2-1])/2;//偶数
            } else
                return nums2[nums2.size()/2];//奇数
        }
        vector<int>::iterator it2=nums2.begin();
        int flag=1;//判断是否到达了it1位置
        double num1=0;
        double num2=0;
        for(vector<int>::iterator it=nums1.begin();it!=nums1.end();)
        {

            //nums1的值大于nums2的值，就将nums2的值插入到nums1中
            if(it!=nums1.end())
            {
                if(*it>*it2)
                {
                    it=nums1.insert(it,*it2);//注意更新插入成功的迭代器
                    it2++;
                    if(it2==nums2.end())
                    {
                        break;
                    }
                }
                else
                    it++;
            }
        }
        if(it2!=nums2.end())
        {
            for(;it2!=nums2.end();it2++)
            {
                nums1.push_back(*it2);
            }
        }
        if(nums1.size()%2==0)
        {
            return (double)(nums1[nums1.size()/2]+nums1[nums1.size()/2-1])/2;//偶数
        } else
            return nums1[nums1.size()/2];//奇数
    }
};
```