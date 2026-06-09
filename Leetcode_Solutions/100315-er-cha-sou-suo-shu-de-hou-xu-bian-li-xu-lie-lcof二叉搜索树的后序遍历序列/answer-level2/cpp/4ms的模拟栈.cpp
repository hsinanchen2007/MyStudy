### 解题思路
我们都知道先序（后序）和中序唯一确定一棵树，其建树过程的工作栈的不同操作唯一地对应一棵树，所以如果模拟栈操作不合法，就代表没有能形成的树。
先序相当于入栈，中序为出栈。
后序的话，将后序变为先序即可（左右根逆序为根右左），再将搜索树降序得到右左，即可完美化归成先序+中序
这种我们已经熟悉的情况
### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        vector<int> t(postorder.begin(),postorder.end());
        stack<int> s;
        sort(t.begin(),t.end(),greater<int>());//降序为右左
        reverse(postorder.begin(),postorder.end());//左右根变为根左右
        int j=0;
        for(int i=0;i<t.size();i++){
            s.push(postorder[i]);
            while(!s.empty()&&s.top()==t[j]){
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};
```