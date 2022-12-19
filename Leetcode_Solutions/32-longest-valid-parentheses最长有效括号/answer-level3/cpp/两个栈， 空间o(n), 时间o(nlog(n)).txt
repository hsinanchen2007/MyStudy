### 解题思路
1.由常规的有效字符串栈的解法改编而来
2.使用两个栈记录下所有能构成有效括号字串的边界点。将边界点复制到数组里，排序，并求相邻点最大差值即可。
3.两个边界点得处理好

### 代码

```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int k=0;
        stack<int> s1, s2;
        while(k<s.size()){
            if(s[k]=='(')s1.push(k);
            else{
                if(s1.empty())s2.push(k);
                else{
                    s1.pop();
                }
            }
            k++;
        }
        vector<int> vec;
        while(!s1.empty()){
            vec.push_back(s1.top());
            s1.pop();
        }
        while(!s2.empty()){
            vec.push_back(s2.top());
            s2.pop();
        }
        sort(vec.begin(), vec.end());
        int len=0;
        if(vec.size()==0)len = s.size();
        else if(vec.size()==1)len = s.size()-vec[0]-1>=vec[0]?s.size()-vec[0]-1:vec[0];
        else{
            for(int i=0;i<vec.size()-1;i++){
                if(i==0)len = vec[0];
                if(len<vec[i+1]-vec[i]-1)len = vec[i+1]-vec[i]-1;
            }
            len = s.size()-vec[vec.size()-1]-1>len?s.size()-vec[vec.size()-1]-1:len;
        }
        return len;
    }

};
```