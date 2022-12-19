### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
       int n=arr.size();
       if(n==k)return arr;
       if(n<k||k<=0||n==0)return vector<int> ();
       int l=0,r=n-1;
       int index=patition(arr,l,r);
       while(index!=k-1){
           if(index>k-1)r=index-1;
           else l=index+1;
           index=patition(arr,l,r);
       }
       return vector<int>(arr.begin(),arr.begin()+k);
    }
    int patition(vector<int>&arr,int l,int r)
    {   int temp=arr[l];
        while(l<r)
        { while(l<r&&arr[r]>=temp)
        r--;
        arr[l]=arr[r];
          while(l<r&&arr[l]<=temp)
        l++;
        arr[r]=arr[l];
        }
        arr[l]=temp;
        return l;
    }
};
```