降序排序，由大到小的全排列（贪心），符合条件，就是答案了
```
class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        vector<string> ans;
        do {
            if( ((A[0] == 2 && A[1] < 4) || A[0] < 2) && A[2] < 6 ) {
                string s = "";
                for(int i = 0; i < 4; i++) s += ('0'+ A[i]);
                s.insert(2, ":");
                return s;
            }
        }while( prev_permutation(A.begin(), A.end()) );
        return "";
    }
};
```
