### 解题思路
此处撰写解题思路
    采用队列先进先出，主要是在前一题得基础上加了对当前节点与孩子节点得计数；
    最开始准备在前一题的基础上进行reverse，结果发现总是超时；

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==nullptr) return result;
        queue<TreeNode*> que;
        int i=0; //记录第几层
        int cur_sum=1; //记录当前层节点数，因为root此时肯定存在，所以在第0层初始化为1
        int children_sum=0;//记录孩子节点数
        que.push(root);
        result.push_back(vector<int>());
        while(!que.empty()){
            TreeNode* cur=que.front();
            que.pop();
            cur_sum--;          //当前节点进行操作，则当前节点数递减
            if(cur->left!=nullptr){ //加入左右孩子节点，并且孩子节点数递加
                que.push(cur->left);
                children_sum++;
            }
            if(cur->right!=nullptr){
                que.push(cur->right);
                children_sum++;
            }
            if(i%2==1) result[i][cur_sum]=cur->val; //如果时奇数层则反序保存
            else result[i].push_back(cur->val);     //偶数层正序保存
            if(cur_sum==0&&children_sum!=0){        //当前层已操作完，并且不是最终的层
                if(i%2==0) result.push_back(vector<int>(children_sum));//主要是vector的特点，必须要定义一定空间
                else  result.push_back(vector<int>());                 //才能用下标访问
                cur_sum=children_sum;
                children_sum=0;
                i++;
            }

        }
        return result;

    }
};
```