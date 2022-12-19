### 解题思路
冒泡排序
![image.png](https://pic.leetcode-cn.com/40fb3c76e0a13246ced3ffbe8240ad78a36b6a2700e1de59fa7c8191f78c035b-image.png)

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<n+m;i++)
        {
            nums1[i]=nums2[i-m];
        }
        while(1)
        {
            bool flag=false;
            for(int i=0;i<n+m-1;i++)
            {
                if(nums1[i]>nums1[i+1]) 
                {
                    swap(nums1[i],nums1[i+1]);
                    flag=true;
                }

            }
            if(flag==false) break;
        }
        for(int i=0;i<n+m;i++)
        {
            cout<<nums1[i]<<" ";
        }

    }
};
```