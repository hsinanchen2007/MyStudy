


用**队列**可以实现对二叉树的层序遍历，但是这里要求输出二维数组，每一层遍历结果都要归到一个数组中。

# 1.第一种情况，先说普通的层序遍历，只把遍历结果作为一维数组输出。
![1583376461(1).png](https://pic.leetcode-cn.com/b6228ac8694b483f74e570fbbfa741c226223172dc6b41d0c4c7233948be3481-1583376461\(1\).png)


```
class Solution {
public:
       vector<int> levelOrder(TreeNode* root) {
       
       vector<int>  ans;
       if(!root) return ans;      //如果根节点为空直接返回
       queue<TreeNode*> q;      //队列用来实现层序遍历
       q.push(root);           //第一步先将根节点入队

       while(q.empty()==0)   //队列不为空的时候保持循环
       {
          TreeNode * p=q.front();         //获得队头元素
          q.pop();                       //队头元素出队
          ans.push_back(p->val);
          if(p->left)  q.push(p->left);
          if(p->right) q.push(p->right);
       }
       return ans;
    }
    
};
```






# 2.第二种情况，就是按照题目的要求，每一层遍历结果要单独用一个数组保存。
  所以这种情况，每一层节点出队的结果要保存在一个数组中，我们需要对出队的节奏进行控制；
```
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
       
       vector<vector<int>> ans;
       if(!root) return ans;      //如果根节点为空直接返回
       queue<TreeNode*> q;      //队列用来实现层序遍历
       q.push(root);     

       while(q.empty()==0)  
       {
           vector<int> temp; 
           int width=q.size();         //这是关键，每次访问前，查清本层有多少个节点
           for(int i=0;i<width;i++)    //一趟for循环访问一层
           {
               TreeNode * p=q.front();
               temp.push_back(p->val);
               q.pop();                 //使用过后出队
               if(p->left)  q.push(p->left);
               if(p->right) q.push(p->right);
           }
           ans.push_back(temp);
       }
       return ans;
    }
    
};
```


