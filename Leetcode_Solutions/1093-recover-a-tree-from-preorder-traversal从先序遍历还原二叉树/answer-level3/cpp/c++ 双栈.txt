![image.png](https://pic.leetcode-cn.com/99cf2986d4e4c197e385586f5bb47a0331598acc28e1d463b85931923bd7b2d7-image.png)


```c++
class Solution {
private:
    vector<int> data, level;

public:
    TreeNode* recoverFromPreorder(string S) {
        if (S.size() == 0) return NULL;
        createBase(S);
        return createTree(data, level);
    }

    TreeNode* createTree(vector<int>& data, vector<int>& level){
        stack<int> s;  // s存储level
        s.push(0);

        stack<TreeNode*> t;  // t存储当前节点
        TreeNode* root = new TreeNode(data[0]);
        t.push(root);

        int cnt = 1;
        while (cnt < level.size()){
            if (s.top() == level[cnt] - 1){
                TreeNode* node = new TreeNode(data[cnt]);
                t.top()->left = node;
                t.push(node);
                s.push(level[cnt]);
                cnt++;
            }else{
                while (s.top() >= level[cnt]){  // 使得t最上面的节点为cnt节点的父节点，并将cnt节点插入其右指针
                    s.pop();
                    t.pop();
                }
                TreeNode* node = new TreeNode(data[cnt]);
                t.top()->right = node;
                t.push(node);
                s.push(level[cnt]);
                cnt++;
            }
        }
        return root;
    }

    void createBase(string S){
        level.push_back(0);
        int sp = 0, fp = 0;
        while (fp < S.size()){
            while (fp < S.size() && isdigit(S[fp])) fp++;
            data.push_back(stringToNum(S.substr(sp, fp-sp)));
            sp = fp;
            if (sp == S.size()) break;
            while (fp < S.size() && S[fp] == '-') fp++;
            level.push_back(fp-sp);  // root在第0层
            sp = fp;
        }
    }

    int stringToNum(string s){
        int sum = 0;
        for (auto it =s.begin(); it < s.end(); it++){
            sum = sum * 10 + int(*it-'0');
        }
        return sum;
    }
};
```