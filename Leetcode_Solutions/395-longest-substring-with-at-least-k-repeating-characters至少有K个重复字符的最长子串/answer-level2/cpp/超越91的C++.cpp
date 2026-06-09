        class Solution {

        public:

            int longestSubstring(string s, int k) {
                int end = s.size(); 
                if (end == 0) return 0;
                map<char, size_t> cntMap;
                for (auto i : s) {
                    cntMap[i]++;
                }
                vector<size_t> idxVector;
                
                idxVector.reserve(end + 2);
                idxVector.push_back(-1);
                for (auto i = 0; i < end; i++) {
                    if (cntMap[s[i]] < k) {
                        idxVector.push_back(i);
                    }
                }
                
                idxVector.push_back(end);
                if (idxVector.size() == end + 2)  return 0;
                if (idxVector.size() == 2)  return end;
                cntMap.clear();
                int res = 0;
                for (auto i = 1; i < idxVector.size(); i++) {
                    if (idxVector[i - 1] + 1 < idxVector[i]) {
                        res = max(res, longestSubstring(s.substr(idxVector[i - 1] + 1, idxVector[i]), k));
                    }
                }
                return res;
            }
        };