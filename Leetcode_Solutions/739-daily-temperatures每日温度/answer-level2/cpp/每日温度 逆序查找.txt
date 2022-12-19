`class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result(T.size(), -1);
        result[T.size() - 1] = 0;
        
        for (int i = (int)T.size() - 2; i >= 0; --i) {
            for (int j = i + 1; j < T.size(); ) {
                if (T[j] > T[i]) {
                    result[i] = j - i;
                    break;
                } else {
                    if (result[j] == 0) {
                        result[i] = 0;
                        break;
                    } else {
                        j += result[j];
                    }
                }
            }
        }
        
        return result;
    }
};`