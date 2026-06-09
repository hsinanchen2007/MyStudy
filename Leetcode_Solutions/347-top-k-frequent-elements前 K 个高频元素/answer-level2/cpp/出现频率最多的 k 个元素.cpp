### 解题思路
创建map表存频率 => 加入vector<pair<int,int> > 后按照频率大小使用快速排序 =>返回数组最后两个的first（key值）  

### 代码

```cpp
class Solution {
public:      
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //新建一个map获取频率
        unordered_map<int ,int> data;
        for(auto it:nums){
            data[it]++;
        }
        //将map全部放入pair<int,int>类型的数组中
        vector<pair<int,int> > arr(data.begin(),data.end());
        
        //快速排序算法，根据频率排顺序从小到大
        quickSort(arr,0,arr.size()-1);
        
        //创建int数组存k个元素的key值
        vector<int> ret(k);
        for(int i=0;i<k;i++){
            ret[i]=arr[arr.size()-1-i].first;
        }
        return ret;
    }
    void quickSort(vector<pair<int,int> > &arr,int low,int high){
        if(low<high){
            int mid=partition(arr,low,high);
            quickSort(arr,low,mid-1);
            quickSort(arr,mid+1,high);
        }
    }

    int partition(vector<pair<int,int> >&arr,int low,int high){
        pair<int,int> temp=arr[low];
        while(low<high){
            while(low<high && arr[high].second>=temp.second)high--;
            swap(arr,low,high);
            while(low<high && arr[low].second<=temp.second)low++;
            swap(arr,low,high);
        }
        return low;
    }
    void swap(vector<pair<int ,int> >&arr,int low,int high){
        if(low<high){
            pair<int,int> temp=arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
        }
    }

};
```