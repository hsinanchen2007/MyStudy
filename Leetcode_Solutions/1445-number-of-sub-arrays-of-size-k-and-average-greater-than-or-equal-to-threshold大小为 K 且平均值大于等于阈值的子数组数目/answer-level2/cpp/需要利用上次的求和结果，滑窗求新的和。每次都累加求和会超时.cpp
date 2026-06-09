### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        vector<vector<int>> output;
        int lastSum = 0;
        for (int i = 0; i <= arr.size() - k; i++) {
            int sum = 0;
            if (i == 0) {
                sum = std::accumulate(arr.begin() + i, arr.begin() + i + k, 0);
            }
            else {
                sum = lastSum - arr[i - 1] + arr[i + k - 1];
            }
            lastSum = sum;

            int mean = sum / k;
            if (mean >= threshold) {
                count++;
            }
        }

        return count;
    }
};
```