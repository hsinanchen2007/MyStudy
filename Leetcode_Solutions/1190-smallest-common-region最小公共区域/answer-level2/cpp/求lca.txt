先把x,y爬到同一层, 再x,y一起向上爬
```
typedef vector<vector<string>> vvs;
#define MAXN ((int)1e5+7) //之前只开到了1e4+7  wa到自闭
int pre[MAXN],/* pre[]存前驱节点 */ cnt = 0; /* cnt统计节点个数 */
string* str[MAXN]; //映射节点编号和string

class Solution {
public:
    int hei(int now) {
        int ret = 0;
        while(pre[now] != -1) now = pre[now], ret ++;
        return ret;
    }
    string findSmallestRegion(vvs& arr, string s1, string s2) {
        unordered_map<string, int> mp; //映射节点编号和string
        memset(pre, -1, sizeof(pre)); 
        for(int i=0; i<arr.size(); i++) { //建树
            int& r0 = mp[arr[i][0]];
            if(!r0) r0 = ++cnt, str[cnt] = &(arr[i][0]); //开点 r0是根
            for(int k=1; k<arr[i].size(); k++) {
                int& chl = mp[arr[i][k]];
                if(!chl) chl = ++cnt, str[cnt] = &(arr[i][k]); //开点
                pre[chl] = r0; //设置父节点为r0
            }
        }
        int x = mp[s1], y = mp[s2];
        int hx = hei(x), hy = hei(y), ans = 0;
        while(x!=-1 && y!=-1) { //求x,y的lca
            if(x==y) { ans = x; break; } //xy是同一个节点, 就结束
            //先把x,y爬到同一层, 再x,y一起向上爬
            if(hx > hy) { hx--; x = pre[x]; continue ; } //爬x 
            if(hy > hx) { hy--; y = pre[y]; continue ; } //爬y
            hx --, hy --, x = pre[x], y = pre[y]; //x,y一起爬
        }
        return *(str[ans]);
    }
};
```
