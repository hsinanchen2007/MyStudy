### 解题思路


### 代码

```cpp
class Solution {
public:
    int getKth(int lo, int hi, int k) {
        map<int, int> dict;
        function<int(int, int, int&)> getW;
        dict[1] = 0;
        getW = [&](int num, int tmp, int &count) {
            if (dict.find(tmp) == dict.end()) {
                count++;
                if (tmp % 2 == 0)return getW(num, tmp / 2, count);
                else return getW(num, tmp * 3 + 1, count);
            }
            else {
                dict[num] = dict[tmp] + count;
                return dict[num];
            }
        };
        vector<pair<int, int>> arr;
        for (int i = lo; i <= hi; i++) {
            int count = 0;
            arr.push_back({ i,getW(i, i, count)});
        }
        sort(arr.begin(), arr.end(),
            [](const pair<int, int> &a, const pair<int, int> &b) {
                if(a.second == b.second)return a.first < b.first;
                return a.second < b.second; 
            });
        return arr[k-1].first;
    }
};
```