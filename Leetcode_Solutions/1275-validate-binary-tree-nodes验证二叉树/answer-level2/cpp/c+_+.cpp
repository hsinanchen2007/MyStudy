### 解题思路
![image.png](https://pic.leetcode-cn.com/85ce49e35c9f61f96af5b7a04b9a48f1b6bef056e335de481b364ff25330cf36-image.png)


### 代码

```cpp
const int N = 1e4+10;
class Solution {
public:
    bool vis[N];
    bool ind[N];
    int sum = 0;
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        for(int i = 0;i < n;++i){
            if(leftChild[i] != -1)
                ind[leftChild[i]] = true;
            if(rightChild[i] != -1)
                ind[rightChild[i]] = true;
        }
        int root = -1;
        for(int i = 0;i < n;++i) 
            if(!ind[i]) {
                root = i;
                break;
            }
        return dfs(root, n, leftChild, rightChild) && sum == n;
    }
    bool dfs(int cur, int n, vector<int>& left, vector<int>& right){
        if(cur == -1 || vis[cur]) return false;
        if(sum == n) return true;
        vis[cur] = true; ++sum;
        bool dfs1 = true, dfs2 = true;
        if(left[cur] != -1)
            dfs1 = dfs(left[cur], n, left, right);
        if(right[cur] != -1)
            dfs2 = dfs(right[cur], n, left, right);
        return dfs1 && dfs2;
    }
};
```