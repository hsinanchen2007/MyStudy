### 解题思路
C++版本的单调递增栈方法。时间消耗和内存消耗都是战胜100%的用户

### 代码

```cpp
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        int n = postorder.size()-1;
        
        stack<int> mstack;
        int root = INT_MAX;
        for(int i=n;i>=0;i--)
        {
            if(postorder[i]>root)
                return false;
            if(i==n)
                mstack.push(postorder[i]);
            else if(postorder[i]>mstack.top())
                mstack.push(postorder[i]);
            else  //left-child nodes
            {
                //find root node
                while(!mstack.empty())
                {
                    if(mstack.top()>postorder[i])
                    {
                        root = mstack.top();
                        mstack.pop();
                    }
                    else
                        break;
                }
                mstack.push(postorder[i]);

            }
        }

        return true;
    }
};
```