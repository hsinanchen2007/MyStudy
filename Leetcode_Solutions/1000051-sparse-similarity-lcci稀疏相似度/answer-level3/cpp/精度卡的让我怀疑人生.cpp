### 解题思路
暴力枚举 ，O(n^2*c), 勉强k过，精度卡的让我怀疑人生
还可以利用以每一个数来枚举相同对， 这样最多n^2而且，题目有说大于0的不超过一千对，所以应该会更少

### 代码
### 方法1
```cpp
class Solution {
public:
    using ve2 = vector<vector<int>>;
    using ve1 = vector<int>;
    using si = ve1::size_type;
    vector<string> ans;
    
    inline string itoa(int a) {
        string s;
        if (a == 0) return "0";
        while (a) {
            s += (a%10)+'0';
            a/=10;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    string out(int a) {
        string s = ": ";
        s += itoa(a/10000);
        s += '.';
        a %= 10000;
        string ss;
        for (int i = 0; i < 4; ++i) {
            ss += ((a%10)+'0');
            a/=10;
        }
        reverse(ss.begin(), ss.end());
        return s+ss;
    }
    void similarity(ve1 &a, ve1 &b, string &s) {
        int k = 0;
        for (si i = 0, j = 0; i < a.size() && j < b.size();) {
            if (a[i] == b[j]) k++,i++,j++;
            else if (a[i] > b[j]) j++;
            else i++;
        }
        if (k == 0) return ;
        double an = k*1./(a.size()+b.size()-k);
        k = an*100000;
        if (k%10 > 5 || (k%10 == 5 && k/10 > 0))
            k+=10;
        k/=10;
        if (k == 0) return;
        s += out(k);
        ans.push_back(s);
        return ;
    }
    void sol(ve2 &v) {
        for (si i = 0; i < v.size(); ++i) {
            for (si j = i+1; j < v.size(); ++j) {
                        string a = itoa(i)+","+itoa(j);
                        similarity(v[i], v[j], a);
            }
        }
    }

    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        for (auto & i : docs)
            sort(i.begin(), i.end());
        sol(docs);
        return ans;
    }
};
```
### 方法2
```cpp
class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        map<int, vector<int>> ma;
        map<pair<int, int>, int> counts;
        vector<int>cnt;
        for (int i = 0; i < docs.size(); ++i) {
            cnt.push_back(docs[i].size());
            for (auto &d : docs[i]) {
                ma[d].push_back(i);
            }
        }
        
        for (const auto &[a, b] : ma) {
            for (int i = 0; i < b.size(); ++i) {
                for (int j = i+1; j < b.size(); ++j) {
                    ++counts[{b[i],b[j]}];
                }
            }
        }
        vector<string>ans;
        for (const auto &[a, b] : counts) {
            int fm = cnt[a.first]+cnt[a.second]-b;
            double f = b*1./fm;
            char s[20];
            sprintf(s, "%d,%d: %.4f", a.first, a.second, f+1e-9);
            ans.push_back(s);
        }
        return ans;
    }
};
```