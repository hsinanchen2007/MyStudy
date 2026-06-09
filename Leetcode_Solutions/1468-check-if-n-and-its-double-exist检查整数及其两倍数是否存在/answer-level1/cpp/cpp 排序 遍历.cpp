瞎写暴力就能ac，注意有负数

```
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] >= 0) {
                    if (arr[j] == 2 * arr[i]) {
                        return true;
                    }
                    if (arr[j] > 2 * arr[i]) {
                        break;
                    }
                } else {
                    if (arr[i] == 2 * arr[j]) {
                        return true;
                    }
                    if (arr[i] < 2 * arr[j]) {
                        break;
                    }
                }
            }
        }
        return false;
    }
};
```
