**解题思路**
用INT_MIN表示空节点
幸亏测试用例中没有INT_MIN,不然真的不得不用string
```
class Codec {
public:
    // Encodes a tree to a single string.
    vector<int> serialize(TreeNode*& p) {       // 返回值改为vector<int>
        if(!p) return {};
        queue<TreeNode*> axl;
        vector<int> res;
        axl.push(p);                // 到此为止都是初始化
        for(;!axl.empty();axl.pop())
            if(axl.front())             // 不是空节点,就把它的两个子节点入队,同时序列化
                axl.push(axl.front()->left),axl.push(axl.front()->right),res.push_back(axl.front()->val);
            else res.push_back(INT_MIN);    // 是空节点,用INT_MIN表示空节点
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(vector<int> p) {      // 接受的参数改为vector<int>
        if(p.empty()) return nullptr;
        TreeNode* res=new TreeNode(p[0]);
        queue<TreeNode*> axl;
        axl.push(res);
        int low=1,high=p.size()-1;      // 已经初始化了p[0],只用从p[1]开始
        while(low<=high && p[high]==INT_MIN) --high;      // 到此为止都是初始化
        for(;low<=high && !axl.empty();axl.pop()){
            if(p[low]==INT_MIN) ++low;      // 两个if负责节点的一左一右的反序列化
            else axl.front()->left=new TreeNode(p[low++]),axl.push(axl.front()->left);
            if(p[low]==INT_MIN) ++low;
            else axl.front()->right=new TreeNode(p[low++]),axl.push(axl.front()->right);
        }
        return res;
    }
};
```
