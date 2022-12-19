### 解题思路
（(首项+尾项)*项数)/2 - 实际总和

### 代码

```cpp
class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int sum = 0;
        for(auto t:arr){
            sum += t;
        }
        int len = arr.size();
        return ((arr[0]+arr[len-1])*(len+1)/2) - sum;
    }
};
```