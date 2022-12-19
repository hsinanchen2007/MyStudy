* 并查集判断所有点是否联通
*  判断所有点的出度都不大于2
*  判断是否有且仅有一个点入度为0，且其他点入度都为1

![关注 HelloNebula 获取更多知识~](https://pic.leetcode-cn.com/17a22c81a9e3baf181671425d98154975d0d92bad3a71a04525655fca7d3d24e-qrcode_for_gh_6e5f8557b1f8_258.jpg)


```
const int MAXN = 10000;
int inDegree[MAXN] = {0}, outDegree[MAXN] = {0};
int fa[MAXN];
class Solution {
    int find(int x) {
        int t = x;
        while(t != fa[t]) {
            t = fa[t];
        }
        while(x != fa[x]) {
            int tmp = fa[x];
            fa[x] = t;
            x = tmp;
        }
        return x;
    }
    bool link(int u, int v) {
        int fu = find(u);
        int fv = find(v);
        if(fu == fv) {
            return false;
        }
        fa[fu] = fv;
        return true;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i = 0; i < n; i++) {
            fa[i] = i;
        }
        memset(inDegree, 0, sizeof(int)*n);
        memset(outDegree, 0, sizeof(int)*n);
        int rootCnt = n;
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                if(++outDegree[i] > 2) {
                    return false;
                }
                if(++inDegree[leftChild[i]] > 1) {
                    return false;
                }
                if(link(i, leftChild[i]) == false) {
                    return false;
                }
                --rootCnt;
            }
            if(rightChild[i] != -1) {
                if(++outDegree[i] > 2) {
                    return false;
                }
                if(++inDegree[rightChild[i]] > 1) {
                    return false;
                }
                if(link(i, rightChild[i]) == false) {
                    return false;
                }
                --rootCnt;
            }
        }
        if(rootCnt != 1) {
            return false;
        }
        return true;
    }
};
```
