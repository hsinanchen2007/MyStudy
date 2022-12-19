BFS遍历A树各个节点，对每个节点与B树进行判断，具体为以B树为主导的BFS。
代码写的丑了点。
```cpp
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL)
            return false;

        if(A == NULL)
            return false;

        deque<TreeNode*> deq;
        deq.push_back(A);
        while(!deq.empty())
        {
            auto root = deq.front();
            deq.pop_front();
            int flag = true;
            deque<TreeNode*> sA, sB;
            sA.push_back(root);
            sB.push_back(B);
            while(!sB.empty())
            {
                if(sA.front()->val != sB.front()->val)
                {
                    flag = false;
                    break;
                }

                auto tA = sA.front();
                sA.pop_front();
                auto tB = sB.front();
                sB.pop_front();
                if(tB->left!=NULL)
                {
                    if(tA->left==NULL)
                    {
                        flag = false;
                        break;
                    }
                    sA.push_back(tA->left);
                    sB.push_back(tB->left);
                }
                if(tB->right!=NULL)
                {
                    if(tA->right==NULL)
                    {
                        flag = false;
                        break;
                    }
                    sA.push_back(tA->right);
                    sB.push_back(tB->right);
                }
            }
            if(flag)
                return true;

            if(root->left!=NULL)
                deq.push_back(root->left);

            if(root->right!=NULL)
                deq.push_back(root->right);
        }
        return false;
    }
};
```