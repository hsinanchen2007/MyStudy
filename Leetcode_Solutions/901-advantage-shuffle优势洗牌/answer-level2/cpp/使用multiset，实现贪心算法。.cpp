    vector<int> advantageCount(vector<int>& A, vector<int>& B)
    {
        vector<int> ans;
        multiset<int> valueSet(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++) {
            multiset<int>::iterator it = valueSet.upper_bound(B[i]);
            if (it != valueSet.end()) {
                ans.push_back(*it);
                valueSet.erase(it);
            } else {
                ans.push_back(*valueSet.begin());
                valueSet.erase(valueSet.begin());
            }
        }

        for (auto &it : valueSet) {
            ans.push_back(it);
        }

        return ans;
    }