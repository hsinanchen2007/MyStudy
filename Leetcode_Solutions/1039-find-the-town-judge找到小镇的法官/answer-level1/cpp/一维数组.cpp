### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> vectJudge(N,0);
        vector<int>::iterator iter;
        bool  flag = false;
        int itmp = 0;
        for(int i = 0; i < trust.size(); i++){
            vectJudge[trust[i][1]-1]++;
        }
        for (; itmp < N; itmp++){
            if (vectJudge[itmp] == N-1){
                flag = true;
                break;
            }
        }

        for (int i = 0 ; i < trust.size() ; i++ ){
            if (trust[i][0] == (itmp + 1))
                flag = false;
        }

        if (flag == true ) return itmp+1;
        else return -1;
    }
};
```