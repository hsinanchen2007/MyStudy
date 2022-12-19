### 解题思路
利用快排思想划分数组
注：两种快排过程，第一种取`base=q[l+r >>1]`和用`do ;while();`更快；

### 代码

```cpp []
class Solution {
    void quick_sort(vector<int> &q,int k,int l,int r)
    {
        if(l>=r)  return ;
        
        int i=l-1,j=r+1;
        int base= q[l+r >>1];

        while(i<j)
        {
            do i++;while(q[i]<base);
            do j--;while(q[j]>base);
            if(i<j)   swap(q[i],q[j]) ;
        }

        if(j-l+1 ==k ) return ;
        else if(j-l+1 >k) quick_sort(q,k,l,j);
        else  quick_sort(q,k-(j-l+1),j+1,r);


    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k);
        if(arr.size()==0 || k==0)
            return res;
        quick_sort(arr,k,0,arr.size()-1);
        for(int i=0;i<k;i++)  res[i]=arr[i];
        return res;
    }
};
```
```cpp []
class Solution {
    void quick_sort(vector<int> &q,int k,int l,int r)
    {
        if(l>=r)  return ;
        int base = q[l];
        int i=l,j=r;
        while(i<j)
        {
            while(i<j && q[j]>base)
                j--;
            while(i<j && q[i]<=base)
                i++;
            if(i<j)
                swap(q[i], q[j]);
        }
        //基数归位
        swap(q[i], q[l]);

        if(i-l+1==k) return ;
        else if(i-l+1>k) quick_sort(q,k,l,i-1);
        else  quick_sort(q,k-(i-l+1),i+1,r);
    }
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res(k);
        if(arr.size()==0 || k==0)
            return res;
        quick_sort(arr,k,0,arr.size()-1);
        for(int i=0;i<k;i++)  res[i]=arr[i];
        return res;
    }
};
```
