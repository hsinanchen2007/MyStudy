### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int len = pushed.size();
        if(!len) return true;
        int i=0,j=0;
        stack<int>s;
        while(i < len || s.size()){
            if(s.size() && s.top() == popped[j]){
                j++;
                s.pop();
            }
            else{
                if(i >= len)
                    return false;
                s.push(pushed[i]);
                i++;
            }
        }
        return true;
        // return j==len?true:false;
    }
};
```