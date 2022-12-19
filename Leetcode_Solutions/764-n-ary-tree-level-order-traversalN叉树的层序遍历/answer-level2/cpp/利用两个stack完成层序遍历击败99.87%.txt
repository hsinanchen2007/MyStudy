### 解题思路
使用两个stack，第一个stk用于正向遍历数值，第二个stk2用于临时存储子节点，待遍历完成后再挨个放进stk。
需要学习的地方：学习队列
不足：内存消耗过多

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        stack<Node*> stk;
        stack<Node*> stk2;
        stk.push(root);
        vector<vector<int>> re;
        //很多题目都要注意这种边边角角的地方，不小心就会错。。。
        if (NULL == root)
            return re;
        //第一个大循环，每执行一次遍历一层
        while (!stk.empty()) {
            vector<int> lvl_data;
            //从stk中取出节点数据，依次存入lvl_data。取出的同时stk弹出，stk2存入下一层的节点
            while(!stk.empty()) {
                Node* node = stk.top();
                lvl_data.push_back(node->val);
                for (int i=0; i<node->children.size(); i++) {
                    stk2.push(node->children.at(i));
                }
                stk.pop();
            }
            //一层的数据计入答案
            re.push_back(lvl_data);
            //取出stk2的数据给stk，正好把节点的顺利也倒过来
            while(!stk2.empty()) {
                stk.push(stk2.top());
                stk2.pop();
            }
        }
        return re;
    }
};
```