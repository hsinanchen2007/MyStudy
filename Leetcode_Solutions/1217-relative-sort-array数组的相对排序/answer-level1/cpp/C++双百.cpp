![image.png](https://pic.leetcode-cn.com/60c5a7cf601cd0f12e929a97651a47ca78feee1dc8bff7b295e6d6ea298235db-image.png)

vector<int> order;
    bool cmp(int a, int b)
    {
        if (order[a] == -1 && order[b] == -1) {
            return a < b;
        }
        if (order[a] == -1 && order[b] != -1) {
            return false;
        }
        if (order[a] != -1 && order[b] == -1) {
            return true;
        }
        return order[a] < order[b];
    }

class Solution {
public:
    
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        for (int i = 0; i < 1001; i++) {
            order.push_back(-1);
        }
        for (auto i = 0; i < arr2.size(); i++) {
            order[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), cmp);
        order.clear();
        return arr1;
    }
};


