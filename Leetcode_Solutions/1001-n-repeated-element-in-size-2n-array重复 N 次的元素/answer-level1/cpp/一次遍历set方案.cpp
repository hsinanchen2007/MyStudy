用unordered_set更快更好，第一次用的是set
```
class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        unordered_set<int> B;
        for(auto iter = A.begin(); iter != A.end(); ++iter){
            if(B.find(*iter) != B.end()) {
                return *iter;
            } else {
                B.insert(*iter);
            }
        }
        return 0;
    }
};
```
![image.png](https://pic.leetcode-cn.com/b00d49ff85e10b552a5a16925d00ff8befc75f4e1ae85510852f6d9a1da001cc-image.png)
