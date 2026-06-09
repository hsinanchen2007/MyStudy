### 解题思路
核心思路：预设一个栈，每次循环中压入pushed序列中的一个元素，然后反复检测栈顶是否等于当前popped指向的元素，不断弹出和向前移动popped内的指针pos，最后结束判断一下栈是否为空即可
执行用时 :16 ms, 在所有 C++ 提交中击败了33.28%的用户
内存消耗 :15.3 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size()==0&&popped.size()==0)return true;
        if(pushed.size()==0||popped.size()==0)return false;
        stack<int>s;
        int pos=0;
        for(int i=0;i<pushed.size();i++){
            s.push(pushed[i]);
            while(!s.empty()&&pos<pushed.size()&&s.top()==popped[pos]){
                s.pop();
                pos++;
            }
        }
        return s.empty();
    }
};
```