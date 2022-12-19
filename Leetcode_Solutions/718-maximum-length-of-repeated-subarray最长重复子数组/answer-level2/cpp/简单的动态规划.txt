```
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int lA = A.size(), lB = B.size();
        //存储子串长度的数组cnt
        int* cnt = new int[lB + 1]{0};
        //最长重复元素个数
        int maxL = 0;

        for (int i = 0; i < lA; i++){
            for (int j = lB; j > 0; j--){
                if (B[j - 1] == A[i]){
                    cnt[j] = cnt[j - 1] + 1;
                    if (cnt[j] > maxL)
                        maxL = cnt[j];
                }
                else
                    cnt[j] = 0;
            }
        }
        return maxL;
    }
};
```
