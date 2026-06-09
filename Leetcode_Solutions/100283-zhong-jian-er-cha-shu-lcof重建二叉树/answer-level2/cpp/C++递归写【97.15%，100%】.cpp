主要求当前节点的左子树大小和右子树大小。然后跳到对应的在中序遍历和前序遍历中的区间。

具体模拟这代码写一遍小数据就懂了。

注意，val 不是 1~n，所以 rig 是 map<int,int>

ps:题目中说了 val 不重复。

```c++
class Solution {
public:
    TreeNode *buildTree(vector<int> &pre, vector<int> &vin) {
        if(pre.size() == 0) return nullptr;
        map<int,int> rig;
        for(int i = 0;i < vin.size();++ i) rig[vin[i]] = i;
        return solve(rig,pre,0,pre.size() - 1,0,pre.size() - 1);
    }
    TreeNode* solve(map<int,int> &rig,vector<int> &pre,int l,int r,int ll,int rr) {
        if(rr < ll || r < l) return nullptr;
        TreeNode* head = new TreeNode(pre[l]);
        int lefsz = rig[pre[l]] - ll;
        int rigsz = rr - rig[pre[l]];
        if(lefsz > 0) head -> left = solve(rig,pre,l + 1,l + lefsz,rig[pre[l]] - lefsz,rig[pre[l]] - 1);
        if(rigsz > 0) head -> right = solve(rig,pre,l + lefsz + 1,r,rig[pre[l]] + 1,rig[pre[l]] + rigsz);
        return head;
    }
};
```
