/*
递归
 */
```
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> V;
        if (!root)
            return V;
        V.push_back(root->val);
        for (auto node : root->children)//node是root的所有孩子结点
        {
            for (auto num : preorder(node))//所有的孩子结点再递归生成vector，而num是这个孩子结点vector中的每个元素
            {
                V.push_back(num);
            }
        }
        return V;
    }
};
```
/*
迭代
 */
```
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        stack<Node *> S;
        vector<int> V;
        if (!root)
        {
            return V;
        }
        S.push(root);//先将root放入栈中，之后每从栈里取出一个元素，就放入V，并且在栈中去除后
        while (!S.empty())
        {
            Node *temp = S.top();
            S.pop();
            V.push_back(temp->val);
            vector<int>::reverse_iterator iter;//反向遍历vector，因为栈是先入后出，这样从右往左进，最后从左往右出
            for (auto iter = temp->children.rbegin(); iter != temp->children.rend(); iter++)//必须加auto，因为iter是int型，而真正进入S的是Node*型
            {
                S.push(*iter);
            }
        }
        return V;
    }
};
```


