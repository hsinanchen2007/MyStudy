### 解题思路
需要找到前k个最小的数，正好快排很好用，不用对前k个最小的数，排序，只要把前k个最小的数，放到一起就好了。
使用快排递归实现，
如果一轮结束后，刚好最后基准值所在的位置就是k，那直接返回前k个就好了，因为前k个元素都是比基准值小的，后面的都是比基准值大的。
如果一轮结束后，刚好最后基准值所在的位置小于k，那么只需继续对后面的元素进行递归，因为前面比基准值小的元素个数不足k个
如果一轮结束后，刚好最后基准值所在的位置大雨k，那么只需继续对前面的元素进行递归，因为前面比基准值小的元素多余了k个。

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> result(k,0);
        if(k==0)
            return result;
        quick_sort(arr,0,arr.size()-1,k);
        copy(arr.begin(),arr.begin()+k,result.begin());
        return result;
    }
    void quick_sort(vector<int>& arr,int left,int right,int k){
        if(left==right)
            return;
        int start=left,end=right;
        int base=arr[left];
        while(left<right){
            while(arr[right]>=base&&left<right)
                right--;
            arr[left]=arr[right];
            while(arr[left]<=base&&left<right)
                left++;
            arr[right]=arr[left];
        }
        arr[left]=base;
        if(left==k-1)
            return;
        if(left>k-1)
            quick_sort(arr,start,left-1,k);
        else
            quick_sort(arr,left+1,end,k);
    }
};
```