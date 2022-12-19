**Time: O(n); Space: O(right);  n=节点数量, right = 右节点数量**

迭代版前序遍历的思路是：**a.沿着左侧分支不断向下直到空节点，中途遇到右节点压入栈中；b.然后更新当前节点为栈顶节点并弹出，继续沿左侧分支向下；c.重复a, b, 直至栈空。**

注意点：
1.针对空的左节点，右节点入栈时需要判断提前对左节点判断是否为空并进行`s+="()"`处理。
2.由于每次当前节点更新为栈顶节点后，层数的信息就会丢失，由于需要补全右括号，新增`level`和栈`S2`变量用于补全右括号。
3.最后需要将右括号补齐至底层
```    
string tree2str(TreeNode* t){
        if(t == nullptr)
            return "";
        string s;
        stack<TreeNode*> S1;
        stack<int> S2;
        int level = 0; //记录入栈的右节点的层数。
        S1.push(t);
        while(true){
            while(t){
                s += "("; //对于根节点统一处理，返回时再去掉
                s += to_string(t->val);
                if(t->right){
                    S1.push(t->right);
                    S2.push(level+1);
                    if(!t->left)
                        s += "()";
                }           
                t = t->left;
                level++;
            }
            if(S1.empty() || S2.empty())
                break;
            t = S1.top();
            S1.pop();
            //从当前层数到右栈层数所需要的")"
            for(int i = S2.top(); i<level;i++){
                s +=")";
            }
            level = S2.top();
            S2.pop();
        }
        //从当前层数更新至底层(i = 0)所需要的")",由于最底层不需要")"，所以终止条件是level - 1
        for(int i = 0; i < level-1; i++)
            s += ")";
        return s.substr(1);
    }
```