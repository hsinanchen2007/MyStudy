class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> m;
        for (auto i : arr) {
            m[i]++;
        }
        map<int, int>::reverse_iterator iter;
        for (iter = m.rbegin(); iter != m.rend(); iter++)
            if (iter->first == iter->second)
                return iter->first;
        return -1;
    }
};