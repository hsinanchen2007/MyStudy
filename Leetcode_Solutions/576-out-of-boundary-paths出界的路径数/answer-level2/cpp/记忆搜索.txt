```
#define mod 1000000007
class Solution {
public://dp别人已经写了，写了个记忆搜索
    int m,n,max_cnt,res;
    unordered_map<string,int> len;//用来存储当前点出发的所有路径
    int findPaths(int M, int N, int maxi, int i, int j) {
        m = M;n = N;max_cnt = maxi;
        return dfs(i,j,0)%mod;
    }
    long long dfs(int i,int j,int cnt) {
        if(cnt>max_cnt) return 0;
        if(i<0||i>m-1||j<0||j>n-1) return 1;
        string s = trans(i,j,cnt);
        if(len.count(s)) return len[s];
        return len[s] = (dfs(i-1,j,cnt+1)%mod + dfs(i+1,j,cnt+1)%mod + dfs(i,j-1,cnt+1)%mod + dfs(i,j+1,cnt+1)%mod)%mod;
    }
    string trans(int a,int b,int c) {//将(横坐标，纵坐标，访问的次数)作为结点转为字符串处理，不然会超时
        static stringstream ss;
        static string tmp,res;
        res = "";
        ss.clear();
        ss << a;ss >> tmp;res += tmp;res.push_back('|');
        ss.clear();
        ss << b;ss >> tmp;res += tmp;res.push_back('|');
        ss.clear();
        ss << c;ss >> tmp;res += tmp;
        return res;
    }
};
```
