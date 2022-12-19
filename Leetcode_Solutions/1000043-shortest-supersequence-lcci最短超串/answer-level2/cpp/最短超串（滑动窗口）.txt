```
class SlidingWindow {
private:
    unordered_map<int, int> mp;
public:
    SlidingWindow(vector<int>& num_list) {
        this->mp = get_maping(num_list);
    }
    unordered_map<int, int> get_maping(vector<int>& num_list) {
        unordered_map<int, int> tmp;
        for (int i = 0; i < num_list.size(); i++) {
            tmp[num_list[i]]++;
        }
        return tmp;
    }
    void push(int element) {
        if (mp.count(element) != 0) {
            mp[element]--;
        }
    }
    void pop(int element) {
        if (mp.count(element) != 0) {
            mp[element]++;
        }
    }
    bool check() {
        for (auto pair : mp) {
            if (pair.second > 0) {
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        vector<int> ans;
        SlidingWindow _sliding_window(small);

        int left = 0;
        for (int right = 0; right < big.size(); right++) {
            _sliding_window.push(big[right]);
            while (left <= right && _sliding_window.check()) {

                if(ans.empty() || right - left < ans[1] - ans[0]){
                    ans = vector<int> {left, right};
                }
                _sliding_window.pop(big[left++]);
            }
        }
        return ans;
    }
};
```
