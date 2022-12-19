
- 对于每个 i，我们期望找到最大的 j≤i，使得区间 [j, i] 被替换后原字符串平衡。容易看出 j 是随着 i 单调不减的。
- 我们首先统计出每种字符出现次数，同时维护区间内每种字符的出现次数，二者做差可以得到区间外每种字符的出现次数。如果区间外每种字符的出现次数都小于等于 n/4，则这个区间是合法的。
- 时间复杂度
每个位置最多遍历两次，故时间复杂度为 O(n)。
- 空间复杂度
仅需要常数的额外空间记录每种字符的出现次数。

### 代码

```cpp
class Solution {
public:
    int balancedString(string s) {
        int n = s.size(),ans = INT_MAX,k=n/4;
        unordered_map<char,int>mp;
        mp['Q']=0,mp['W']=1,mp['E']=2,mp['R']=3;
        vector<int>sum(4);
        for(int i=0;i<n;i++) sum[mp[s[i]]]++;//统计所有字符出现次数
        if(sum[0]==sum[1] && sum[0]==sum[2] && sum[0]==sum[3])return 0;
        vector<int>total(4);//区间j-i的各个字符出现次数
        for(int i=0,j=0;i<n;i++){
            total[mp[s[i]]]++;
            while(j<=i && check(sum,total,i,k)){//j-i区间合法
                ans = min(ans,i - j + 1);
                total[mp[s[j]]]--;
                j++;
            }
        }
        return ans;
    }
    bool check(vector<int> &sum,vector<int> &total, int i, int& target){
        for(int i=0;i<4;i++){
            if(sum[i]-total[i]>target)return false;
        }
        return true;
    }
};
```