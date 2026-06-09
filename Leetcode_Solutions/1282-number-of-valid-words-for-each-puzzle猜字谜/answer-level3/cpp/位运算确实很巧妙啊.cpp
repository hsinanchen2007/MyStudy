### 解题思路
看了产生子集的方法，结合自己的理解写的。
Hash的方法是用二进制，因为最多只有7位，不会超范围
例如abd=1011,acd=1101;

### 代码

```cpp
class Solution {
public:
    int Hash(string s){
        int m=0;
        for(int i=0;i<s.size();i++){
            m|=(1<<s[i]-'a');
        }
        return m;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int i,j,k,m=words.size(),n=puzzles.size();
        vector<int>ans(n,0);
        unordered_map<int,int>u;
        for(i=0;i<m;i++){
            j=Hash(words[i]);
            if(u.count(j))u[j]++;//记录hash值相同的个数
            else u[j]=1;
        }
        for(i=0;i<n;i++){
            k=Hash(puzzles[i]);//谜面Hash一下
            for(j=k;j;j=(j-1)&k){/产生子集
                if(j&(1<<puzzles[i][0]-'a')){//只有子集中有首字母才计算
                    if(u.count(j))ans[i]+=u[j];
                }
            }
        }
        return ans;
    }
};
```