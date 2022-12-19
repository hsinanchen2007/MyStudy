# 思路：
#### 记录当前结点是左/右孩子，即记录当前路径的方向
#### 搜索其孩子时，根据上一条路径方向判断
#### 如果当前路径方向相反，路径长度+1，如果相同，路径长度置为1
```
class Solution {
    int ans=0;
    void dfs(TreeNode* root,int dir,int dis){//(当前结点，左/右孩子，路径长度)
        if(!root)return;//空结点返回
        ans=max(ans,dis);//更新最大值
        if(dir){//如果当前结点是其父结点的右孩子
            dfs(root->left,0,dis+1);//搜索其左孩子时，满足ZigZig，路径长度+1
            dfs(root->right,1,1);//搜索其右孩子时，不满足ZigZig，路径长度置为1
        } 
        else{//如果当前结点是其父结点的左孩子
            dfs(root->left,0,1);//搜索其左孩子时，不满足ZigZig，路径长度置为1
            dfs(root->right,1,dis+1);//搜索其右孩子时，满足ZigZig，路径长度+1
        }       
    }
public:
    int longestZigZag(TreeNode* root) {
        dfs(root->left,0,1);//0左节点
        dfs(root->right,1,1);//1右结点
        return ans;
    }
};
```

### 3月9日 updata
![image.png](https://pic.leetcode-cn.com/ad746ce1bd23f8b1106c1a6cd3d8c3588a00208ce0c42bdf7567729ce213be3e-image.png)
