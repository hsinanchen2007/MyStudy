### 解题思路
这里要懂得当出现:
"adf" , "abc", "bcd" 这样的例子，主要就是同行相邻列元素相同时，需要判断其后续,才能决定是否需要删除;

### 代码

```cpp
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int m=A.size();
        int n=A[0].size();

        vector<bool> cuts(n, false);

        int ans = 0;

        Judge(A, cuts, ans);
       return ans;
        
    }
private: 
    void Judge(vector<string>& A,  vector<bool>& cuts, int& ans) {
        int m=A.size();
        int n=A[0].size();

        for (int i = 0; i < n; i++) {   //列;
            bool flag = false;
            for (int j = 0; j < m-1; j++) {   
                if (!cuts[j]  && A[j][i] > A[j+1][i]) { //如果当前行不满足升序且需要作比较;
                    ans++;
                    flag = true;
                    break;
                }
            }

            if (flag)
                continue;

            for (int j = 0; j < m-1; j++) {
                if (A[j][i] < A[j+1][i]) {  //每行保持有序时，标记;
                    cuts[j] = true;
                }
            }

        } 

        return ;
    }
  
};
```