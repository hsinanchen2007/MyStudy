### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans;
        if(arr.size()==0 || k==0) return ans;
        if(arr.size()==k) return arr;

        int index = Partition(arr, 0, arr.size()-1, 0); //第一次快排返回的枢轴下标

        //直到快排返回的枢轴下标等于k，得到最小的k个数
        while(index!=k){
            if(index < k) index = Partition(arr, 0, arr.size()-1, index+1); //更新枢轴
            if(index > k) index = Partition(arr, 0, arr.size()-1, index-1);
        }
        for(int i=0; i<k; i++)
        {
            ans.push_back(arr[i]);
        }
        return ans;

    }

    int Partition(vector<int>& arr, int s, int e, int p){
        swap(arr[s], arr[p]);   //将arr[p]作为枢轴
        int pivot = arr[s];
        while(s<e)
        {
            while(s<e && arr[e]>=pivot)
                e--;
            swap(arr[s], arr[e]);
            while(s<e && arr[s]<=pivot)
                s++;
            swap(arr[s], arr[e]);
        }
        return s;
    }
};
```