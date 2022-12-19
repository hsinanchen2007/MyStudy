### 解题思路
此处撰写解题思路
，先将nums2的数组元素放入nums1中，再利用冒泡排序将nums1进行排序
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int  len=m+n;
        int i=m;
        for(int j=0;j<n;j++)
        nums1[i++]=nums2[j];
        bubble(nums1,m+n);

    }
    void  bubble(vector<int>& a, int len)
    {
        bool  flag;
        for(int i=0;i<len;i++)
        {
            flag=false;
            for(int j=0;j<len-1-i;j++)
                if (a[j] > a[j + 1])
                {
                    int  temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    flag=true;
                }
                if(flag==false)
                break;
        }
        for(int k=0;k<len;k++)
        cout<<a[k];
    }
};
```