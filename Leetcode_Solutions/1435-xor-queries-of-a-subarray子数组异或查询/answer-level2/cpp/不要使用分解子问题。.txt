### 解题思路
此处撰写解题思路
1.设A[i,j] = a_i ^.....^a_j;
2.设B[i] = a_0^a_1^......^a_j;B[i]^B[i] = 0;
3.A[i,j] = B[i-1]^A[i,j]^B[i-1]= B[j]^B[i-1];
代码二出现问题，分解的重复子问题，
A[i,j] 为 i为异或的数量，j为异或的起始元素
A[i+1,j] = A[i,j]^arr[j+i+1];
申请的空间过大，O(n^2);
### 代码

```cpp
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector <int> allXor;
        allXor.resize(arr.size()+1);
        allXor[0] = 0;
        for (int i = 1; i < arr.size()+1 ; i++)
        {
            allXor[i]= allXor[i-1]^arr[i-1];
        }
        vector <int>ans;
        ans.resize(queries.size());
        for (int i = 0 ; i < queries.size() ; ++i)
        {
            //if ( queries[i][1] == queries[i][0])
              //  ans[i] = arr[queries[i][0]];
            //else
            {
                ans[i] = allXor[queries[i][1]+1] ^ allXor[queries[i][0]];
            }
        }
        return ans;
    }
};
```
///代码二，超出内存限制
class Solution {
public:
    vector < vector <int> >allXor;
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        allXor.resize(n+1);
        for (int i = 0 ; i<=n ; i++)
        {
            allXor[i].resize(n+1, 0);
        }
        
        for (unsigned int i = 0 ; i < n ; i++)
        {
            allXor[1][i] = arr[i];
            //cout<<" "<<allXor[1][i];
        }
        //cout<<endl;
        for (unsigned int i = 2 ; i <= n ; i++)
        {
            for ( unsigned int j = 0 ; j < n -i+1 ; j++)
            {
                allXor[i][j] = allXor[i-1][j]^arr[j+i-1];
                //cout<<" "<<allXor[i][j];
            }
            //cout<<endl;
        }
        vector <int> ans;
        ans.resize(queries.size());
        for ( unsigned int i = 0 ; i < queries.size()  ; i++)
        {
            ans[i]= allXor[queries[i][1] - queries[i][0]+1][queries[i][0]];
        }
        return ans;
    }
};