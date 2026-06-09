### 解题思路
c++ 快速排序  找到前k个就返回  速度比用sort要快 因为没有全部排序

### 代码

```cpp
class Solution {
public:
vector<int> res;

    void quick_sort(vector<int> &q,int k,int l,int r)
    {
        if(l>=r)  return ;
        
        int i=l-1,j=r+1,mid=q[l+r >>1];

        while(i<j)
        {
            do i++;while(q[i]<mid);
            do j--;while(q[j]>mid);
            if(i<j)   swap(q[i],q[j]) ;
        }

        if(j-l+1 ==k ) return ;
        else if(j-l+1 >k) quick_sort(q,k,l,j);
        else  quick_sort(q,k-(j-l+1),j+1,r);


    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
         quick_sort(arr,k,0,arr.size()-1);
        for(int i=0;i<k;i++)  res.push_back(arr[i]);
        return res;
    }
};
```