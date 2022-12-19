由于本题只需要前k小的数，而不需要这k个数有序
可以很直接的想到partition函数，它的返回值index就表示前面index个数都不大于arr[index]，后面的数都不小于arr[index]
因此只需要index==k-1就找到了前面最小的k个数。
```
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int n=arr.size();
        if(n==k) return arr;
        if(n<k || k<=0 || n==0) return vector<int>();
        int l=0,r=n-1;
        int index=partition(arr,l,r);
        while(index!=k-1){
            if(index>k-1) r=index-1;
            else l=index+1;
            index=partition(arr,l,r);
        }
        return vector<int>(arr.begin(),arr.begin()+k);
    }
    int partition(vector<int>&arr,int l,int r){
        int temp=arr[l];
        while(l<r){
            while(l<r && arr[r]>=temp) r--;
            arr[l]=arr[r];
            while(l<r && arr[l]<=temp) l++;
            arr[r]=arr[l]; 
        }
        arr[l]=temp;
        return l;
    }
};
```

