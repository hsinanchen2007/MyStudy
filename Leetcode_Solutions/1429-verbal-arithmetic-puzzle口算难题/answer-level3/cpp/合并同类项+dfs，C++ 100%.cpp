### 解题思路
思路来自于@face4 dalao:

将方程看作是$\sum words[i] - result = 0$
然后将每一个words看作十进制形式：
$\sum_i^n c_i*10^i$，其中c是对应位的数字
将words和result都以十进制形式拆开，然后合并同类项，这样的可以得到一个有$m$个未知数的方程。其中$m$是所有单词中不同字母的个数。
最后暴力搜索，尝试将不同的字母映射为不同的数字，检查结果是否为0.
除此之外，还要注意不能包含前导零。

### 实现
1. 统计所有出现的字母
2. 统计哪些字母不能是0
3. 合并同类项，计算所有未知数的系数$coe$
4. 暴力搜索所有可能
代码如下：

### 代码

```cpp
class Solution {
public:
    bool isSolable(vector<string>& words, string result) {
        vector<char> h;
        vector<int> base;
        vector<int> coe(26,0);
        vector<bool> not_zero(26,false);

        words.push_back(result);
        base.push_back(1);
        for(int i = 1 ; i <= 8 ; i++) base.push_back(base.back()*10);

        for(int j = 0 ; j < words.size() ; j++) {
            string x = words[j];
            for(int i = 0 ; i < x.size() ; i++) {
                if(i==0) not_zero[x[i]-'A'] = true;
                h.push_back(x[i]);
                int flag = j==words.size()-1?-1:1;
                coe[x[i]-'A'] += flag * base[x.size()-1-i];
            }
        }
        sort(h.begin(),h.end());
        h.erase(unique(h.begin(),h.end()),h.end());

        function<bool(int,int,int)> dfs = [&] (int pos,int used, int sum) {
            if(pos == h.size()) return sum == 0;
            for(int i = 0 ; i < 10 ; i++) {
                if(used>>i & 1) continue;
                if(i==0 && not_zero[h[pos]-'A']) continue;
                if(dfs(pos+1,used | 1<<i, sum+i*coe[h[pos]-'A'])) return true;
            }
            return false;
        };
        return dfs(0,0,0);
    }
};
```