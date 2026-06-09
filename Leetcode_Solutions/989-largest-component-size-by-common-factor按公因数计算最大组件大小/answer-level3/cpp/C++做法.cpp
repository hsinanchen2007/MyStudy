### 解题思路
用并查集，然后首先找到最大的元素作为并查集大小；
然后取开方去找公因数。所以不止要添加 i， 同时还要添加 a/i。数字本身在初始化的时候已经添加了，所以不用在意；
当存在一个数又多个公因数的情况，可以把一个公因数指向另一个公因数，因为这个数存在，所以这个数是可以让这两个公因数所代表的的几何连通的。
最后找size最大的parent

我也是看大神的视频才做出来的：
https://www.bilibili.com/video/BV1at411D7gp?from=search&seid=3772215062504495975

### 代码

```cpp
class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n = *max_element(A.begin(),A.end());
        UF uf(n+1);
        for(int a : A){
            int t = sqrt(a);
            for(int i = 2; i<=t ; i++){
                if(a % i == 0){
                    uf.merge(a,i);
                    uf.merge(a, a/i);
                }
            }
        }
        int ans = 0;
        unordered_map<int,int> mp;
        for(int a:A){
            ans = max(ans,++mp[uf.find(a)]);
        }
        return ans;

    }
private:
    class UF{
        private: 
            vector<int>parent;
        public:
            UF(int n):parent(n){
                for(int i = 0;i<n;i++){
                    parent[i] = i;
                }
            }
            int find(int x){
                if(x != parent[x]) parent[x] = find(parent[x]);
                return parent[x];
            }
            void merge(int x,int y){
                parent[find(x)] = find(y);
            }
    };
};
```