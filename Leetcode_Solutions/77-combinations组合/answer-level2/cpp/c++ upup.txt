### 解题思路
此处撰写解题思路
执行用时 :
28 ms
, 在所有 C++ 提交中击败了
82.78%
的用户
内存消耗 :
11.9 MB
, 在所有 C++ 提交中击败了
64.48%
的用户
### 代码

```cpp
class Solution {
public:
vector<vector<int>> ans;
    void dps(vector<int>& vec, int n, int k, int idx)
    {
        if (vec.size() == k)
        {
            ans.push_back(vec);
            return;
        }

        for (int i = idx; i<=n; i++)
        {
            vec.push_back(i);
            dps(vec, n, k, i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> vec;
        dps(vec, n, k, 1);
        return ans;
    }
};

/*
class Solution {
public:
    void pushvec(vector<bool> & vecflag, int n, vector<vector<int>> & vecs)
    {
        vector<int> vec;
        for(int i = 0; i < n; i++) if (vecflag[i]) vec.push_back(i+1);
        vecs.push_back(vec);
    }
    bool getNext(vector<bool> &vecflag, int n)
    {
        bool ifMove = false;
        int pos = -1;
        for (int i =0; i<n-1; i++)
        {
            if (vecflag[i] && !vecflag[i+1])
            {
                vecflag[i] = false;
                vecflag[i+1] = true;
                pos = i;
                ifMove = true;
                break;
            }
        }
        
        int zero = 0;
        for (int i = 0; i < pos; i++)
        {
            if (vecflag[i]) break;
            zero++;
        }
        for (int i = pos-1; i >=0; i--)
        {
            if (zero-->0) vecflag[i] = false;
            else vecflag[i] = true;
        }
       
        //for (int i = 0; i < pos-zero; i++)
        {
            //vecflag[i] = vecflag[i+zero];
        }
        //for (int i = pos-zero; i < pos; i++)
        {
            //vecflag[i] = false;
        }
       

        return ifMove;
    } 
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> vecs;
        if (k>n) return vecs;
        bool ret = false;
        vector<bool> vecflag(n, false);
        for (int i = 0; i<k; i++) vecflag[i] = true;

        do
        {
            pushvec(vecflag, n, vecs);
            ret = getNext(vecflag, n);
        }while(ret);

        return vecs;
    }
};
*/
```