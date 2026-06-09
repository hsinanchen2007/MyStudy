### 解题思路
快排思路，只不过将不用排整体的数组，也不用整体有序，只需要当枢纽位置到达k即可
一次排序使得枢纽位置在mid
若mid小于k，我们直接去(mid+1,r)即可，(l,mid)不用再排,其中的数必然是前k小的数
若mid大于k，同理则去右边的区间
### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        int l = 0, r = arr.size() - 1;
        while(l < r) {
            int mid = _bin(arr, l, r);
            if(mid == k) break;
            if(mid > k) r = mid - 1;
            else l = mid + 1;
        }
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }

    int _bin(vector<int>& arr, int l, int r) {
        int low = l, high = r, num = arr[l];
        while(low < high) {
            while(low < high && arr[high] >= num) high--;
            arr[low] = arr[high];
            while(low < high && arr[low] <= num) low++;
            arr[high] = arr[low];
        }
        arr[low] = num;
        return low;
    }
};
```