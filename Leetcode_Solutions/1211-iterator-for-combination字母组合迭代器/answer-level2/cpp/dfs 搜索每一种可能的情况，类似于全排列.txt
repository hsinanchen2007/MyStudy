### 解题思路

可以加一点剪枝

### 代码

```cpp
class CombinationIterator {
public:
    int nextpoint=0;
    int len;
    vector<string> vec;

    CombinationIterator(string characters, int combinationLength) {
        len=characters.length();
        string s;
        dfs(0,combinationLength,0,s,characters);
        sort(vec.begin(),vec.end());
        // for (auto s: vec) cout<<s<<endl;
    }
    
    void dfs(int step,int n,int beg,string s,string &characters) {
        if (beg>len) return;
        if (step==n) {
            vec.push_back(s);
            return ;
        }
        for (int i=beg;i<=step+len-n;i++) {
            dfs(step+1,n,i+1,s+characters[i],characters);
        }
    }
    
    string next() {
        return vec[nextpoint++];
        // return "";
    }

    bool hasNext() {
        if (nextpoint<vec.size()) {
            return true;
        }
        else return false;
        // return false;
    }
};
```