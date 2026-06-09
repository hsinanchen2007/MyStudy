### 题目简介
本题可以简单理解成如果两个单词不同的字母个数为2，则两单词相邻，相邻的单词属于同一集合。如果新来的单词与已有的某个集合内某一个单词相邻，则属同一个集合。从前往后遍历，找出所有的相邻的单词对，再求联通分量的个数即可得到答案。

### 方法一
分别检测每一个单词对是否相邻，如果相邻则利用并查集将他们加入同一个集合内部。最后返回集合个数。设单词个数为$N$，单词长度为$M$，时间复杂度$O(N^2M)$。

### 方法二
对于每一个单词求取其所有的相邻单词，利用字符串哈希判断该相邻单词是否在原数组内，如果存在则将两个集合合并。每次生成新的字符串哈希值只需要$O(1)$的时间，所以时间复杂度为$O(NM^2)$

### 方法选择
如果$N \le M$选择第一个方法，否则选择第二个方法，这样整体复杂度不会超过$O(N^3)$。在$N=M$时取得最大值不会超过$O(20000^{\frac{3}{2}})$，可以接受了。
不过这里的方法选择上没有考虑常数，实验了$N \le M$和$N\le 2M$，后者略快，所以选择了两倍。

```
typedef unsigned long long ULL;

class Solution {
public:
    const int P = 131;
    
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        
        vector<int> father(n,0);
        for(int i = 0 ; i < n ; i++) father[i] = i;
        
        function<int(int)> find = [&] (int x) {
            if(x==father[x]) return x;
            return father[x] = find(father[x]);
        };
        
        int ans = n;
        
        if(n<2*m) {
            for(int i = 0 ; i < n ; i++)
                for(int j = i+1 ; j < n ; j++) {
                    int diff = 0;
                    for(int k=0 ; k < m ;k++)
                        if(A[i][k]!=A[j][k])
                            diff++;
                    if(diff <= 2) {
                        int fa = find(i);
                        int fb = find(j);
                        if(fa != fb) {
                            father[fa] = fb;
                            ans --;
                        }
                    }
                }
            return ans;
        }
        else {
            vector<unsigned long long> p(1,1);
            for(int i = 0 ; i < m ; i++)
                p.push_back(p.back() * P);
            
            function<unsigned long long(string&)> calc = [&] (string &x) {
                unsigned long long res = 0;
                for(auto a:x) {
                    res *= P;
                    res += a;
                }
                return res;
            };
            
            unordered_map<unsigned long long,int> h;
            vector<unsigned long long> hh;
            
            for(int i = 0 ; i < A.size() ; i++)
                hh.push_back(calc(A[i])),
                h[hh.back()] = i;
            
            for(int i = 0 ; i < n ; i++) {
                int fa = find(i);
                for(int x = 0 ; x < m ; x++)
                    for(int y = x+1 ; y < m ; y++) {
                        ULL t = hh[i];
                        t += (A[i][x]-A[i][y]) * (p[m-1-y]-p[m-1-x]);
                        if(h.count(t)) {
                            int fb = find(h[t]);
                            if(fa!=fb) {
                                father[fb] = fa;
                                ans--;
                            }
                        }
                    }
            }
        }
        return ans;
    }
};
```