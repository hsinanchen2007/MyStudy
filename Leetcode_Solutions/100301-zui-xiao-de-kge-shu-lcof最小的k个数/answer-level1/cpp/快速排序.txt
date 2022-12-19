### 解题思路
本题的方法参考了快速排序的思想；
首先进行一次快排，获取到一个索引，根据这个索引是不是k-1
来判断，源数组中左侧k个数是不是整个数组的最小的K个数。
思想：如果是K-1的话，那么证明左边的索引左边的数字都比索引所在数字小，右边的数字都比索引所在数字大，然后输出左侧即可。

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.empty()||k<=0)return vector<int>();
        int start=0;
        int end=(int)arr.size()-1;
        int index=Partition(arr,start,end);
        vector<int> res;
        while(index!=k-1){
            if(index>k-1){
                end=index-1;
                index=Partition(arr,start,end);
            }
            else if( index<k-1){
                start=index+1;
                index=Partition(arr,start,end);
            }
        }
        for(int i=0;i<k;++i){
            res.push_back(arr[i]);
        }
        return res;
    }
    int Partition(vector<int>& arr,int low,int high){
        int base=arr[low];
        int left=low;
        while(low<high)
        {
            while(low<high&&arr[high]>=base){
                --high;
            }
            while(low<high&&arr[low]<=base){
                ++low;
            }
            if(low<high){
                int temp=arr[high];
                arr[high]=arr[low];
                arr[low]=temp;
            }
        }
        arr[left]=arr[low];
        arr[low]=base;
        return low;
    }
};
```