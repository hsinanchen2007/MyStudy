最近在努力强化非递归版的树的遍历，明明递归版的DFS方便很多，但是为了练习强行把前序遍历以及后续遍历揉到一起写了个非递归版本，权当一次练习，大概最大的好处就是不会用到call stack了？

其实这里的前序遍历和后序遍历说的有没有那么严格，只是以前序的顺序生成前缀和，但是一个`TreeNode`在左孩子和右孩子都被访问过的时候才可以从前缀和中被删掉，所以就暂时认为他是后序遍历了？

代码如下：
```c++
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL) return 0;
        stack<TreeNode*> s;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int res = 0;
        int cursum = 0;
        TreeNode* cur = root;
        TreeNode* pre;
        while(cur!=NULL||!s.empty()){
            while(cur!=NULL){
                cursum += cur->val;
                res += mp[cursum-sum];                
                mp[cursum]++;
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top(); 
            if(cur->right==NULL||cur->right==pre){
                s.pop();
                mp[cursum]--;
                cursum -= cur->val;
                pre = cur;
                cur = NULL;
            }else{
                pre = NULL;
                cur = cur->right;              
            }
        }
        return res;
    }
};
```

以及附上前序遍历以及后续遍历非递归的模板：(TODO的位置是需要自己写的，比如push到一个vector里面之类的)

前序遍历
```c++
stack<TreeNode*> s;
TreeNode* cur = root;
while(cur!=NULL||!s.empty()){
    while(cur!=NULL){
        //TODO:
         s.push(cur);
        cur = cur -> left;
    }
    cur = s.top(); s.pop(); // very important!!!!
    cur = cur->right;
}
```
后续遍历我想了两种：
Solution 1：(也是这道题里面我用的)
```c++
stack<TreeNode*> s;
TreeNode* cur = root;
TreeNode* prev = NULL;
while(cur!=NULL||!s.empty()){
    while(cur!=NULL){
         s.push(cur);
        cur = cur -> left;
    }
    if(cur->right==NULL||prev==cur->right){
        //TODO:
        s.pop();
        prev = cur;
        cur = NULL;
    }else{
        cur = cur->right;
        prev = NULL;
    }
}
```
Solution 2：
```c++
stack<TreeNode*> s;
TreeNode* cur = root;
while(cur!=NULL||!s.empty()){
    while(cur!=NULL){
         s.push(cur);
         s.push(cur);
        cur = cur -> left;
    }
    cur = s.top(); s.pop(); // very important!!!!
    if(!s.empty()&&cur == s.top()){
        cur = cur->right;
    }else{
        //TODO:
        cur = NULL;
    }
}
```

所以这道题我其实在前序遍历和后序遍历的自定义操作部分分别做了前缀和的添加以及前缀和的删除，害，权当练习。
