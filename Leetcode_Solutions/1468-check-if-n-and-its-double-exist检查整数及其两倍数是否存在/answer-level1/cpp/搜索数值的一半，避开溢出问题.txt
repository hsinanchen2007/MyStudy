### 解题思路
搜索数值的一半，特殊情况：
1、关于零的问题:记录零的个数；
2、关于奇数的问题：奇数不可能是整数的两倍；

### 代码

```cpp
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int size=arr.size();
        if(size<2) return false;
        int zero_count=0;
        for(int i=0;i<size;i++)
        {
            if(arr[i]==0)
            {
                zero_count++;
                if(zero_count==2) return true;
            }
            else if( arr[i]%2==0 && searchHalfelement(arr,0,size-1,arr[i]/2))
                return true;
        }
        return false;
    }
    bool searchHalfelement(vector<int>& arr,int l,int r,int val)
    {
        if(l==r) return arr[l]==val;
        int mid=(l+r)/2;
        return searchHalfelement(arr,l,mid,val) || searchHalfelement(arr,mid+1,r,val);
    }
};
```