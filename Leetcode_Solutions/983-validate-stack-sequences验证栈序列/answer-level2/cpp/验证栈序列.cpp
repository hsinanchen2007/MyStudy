1.引入一个栈stack
2.把pushed序列按顺序放到栈stack中，每放一个数据对比栈顶与序列popped中元素是否相同，
若相同，则栈stack执行pop操作，移到popped的下一个元素，继续对比栈顶与该元素是否相同。

注意：while中的条件位置不可改变，否则会出现数组溢出
```
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=popped.size();    /*获取序列的大小*/
        stack<int> s;
        int k=0;
        int test=0;
        for(int i=0;i<n;i++)
        {
            s.push(pushed[i]);
            /*三个条件的顺序很重要*/
            while((!s.empty())&&(k<n)&&(s.top()==popped[k]))
            {
                    s.pop();
                    k++;
            }
        }
        if(!s.empty())  /*如果非空，则返回false*/
        {
            return false;
        }
        return true;
    }
};
```
