这个 题相对来说 简单，需要求最小的数，那我们最好的想法就是 先给他排序，然后，他需要几个最小的数，我们就给他循环输出来就是了

### 代码

```cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        //给定 数组  我们排序  然后 需要啥就出啥 
        sort(arr.begin(),arr.end());

        vector<int> result;
        for(int i=0; i<k; i++)
        {
            result.push_back(arr[i]);
        }
        return result;
    }
};
```