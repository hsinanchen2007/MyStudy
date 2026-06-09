![image.png](https://pic.leetcode-cn.com/eb277398079cd47f3b38a5ae8efc36109a7f229e6922a81d4b17c5fa3e94ce31-image.png)

### 解题思路
维护一个栈用来DFS。

在发现其长度-1=当前层数后，这道题就很清晰了，考虑可能的三种处理情况。

注释和代码如下

### 代码

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    int readLayer(const string & S, size_t & idx)
    {// 读出'-'的数量，并移动idx到之后
        int cnt = 0;
        while(idx < S.size() && S[idx] == '-')   
            ++idx,++cnt;
        return cnt;
    }
    int readValue(const string & S, size_t & idx)
    {// 读出数字，并移动idx到之后
        int temp = 0;
        while(idx < S.size() && isdigit(S[idx]))   
        {
            temp = int(S[idx] - '0') + temp * 10;
            ++idx;
        }
        return temp;
    }
public:
    TreeNode* recoverFromPreorder(string S) {
        size_t len = S.size(),idx = 0;
        TreeNode* ans = new TreeNode(readValue(S, idx));
        int value, layer;
        stack<TreeNode *> st({ans});
        // 遍历S
        while(idx < len)
        {   // 读取layer和value
            layer = readLayer(S, idx);
            value = readValue(S, idx);
            TreeNode * toadd = new TreeNode(value);
            if(st.size()-1 == layer) // 要加入的节点和栈顶元素在同一layer上
            {
                st.pop();
                st.top()->right = toadd;
                st.push(toadd);
            }
            else    if(st.size() == layer)// 要加入的节点在栈顶元素下一层
                    { 
                        st.top()->left = toadd;
                        st.push(toadd);
                    }
                    else// 要加入的节点在栈顶元素上某层
                    {   // pop直到top是要加入节点的父节点
                        for(int diff = st.size()-layer; diff > 0; --diff)
                            st.pop();
                        st.top()->right = toadd;
                        st.push(toadd);
                    }
        }
        return ans;
    }
};
```