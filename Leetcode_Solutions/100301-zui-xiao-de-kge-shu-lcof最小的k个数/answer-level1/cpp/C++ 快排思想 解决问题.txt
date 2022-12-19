### 解题思路
借鉴快速排序的思想。取一个元素作为分界值进行划分，每次可以将数组分成两部分。假定划分后分界值所在下标为m，如果`m=k`或者`m+1=k`(即找到了m个元素比分界值小), 则数组的前k个元素是最小的k个数，结束； 如果`m<k`，则应该在分界值的右半部分继续进行划分； 如果`m>k`，则应该在左半部分进行划分。

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(k == arr.size())        return arr;
        vector<int> ans;
        int low,high;
        low = 0, high= arr.size()-1;
        while(low<high){
            int temp = arr[low];
            int t_low = low;
            int t_high = high;
            while(t_low < t_high){
                while(t_low < t_high && arr[t_high] >= temp) --t_high;
                arr[t_low] = arr[t_high];
                while(t_low < t_high && arr[t_low] < temp) ++t_low;
                arr[t_high] = arr[t_low];
            }
            arr[t_low] = temp;
            if(t_low+1 == k || t_low == k) {
                break;
            }
            if(t_low > k) high = t_low-1;
            if(t_low < k) low = t_low + 1;
        }
        
        ans.assign(arr.begin(),arr.begin()+k);
        return ans;
    }
};
```