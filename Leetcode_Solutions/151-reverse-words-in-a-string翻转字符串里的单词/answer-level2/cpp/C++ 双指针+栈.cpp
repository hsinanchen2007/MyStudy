### 解题思路

![Snipaste_2020-04-04_13-58-38.png](https://pic.leetcode-cn.com/280effb3e33a52d09002f13cd28101755fe379e23adc859abfc3fd47ed81f839-Snipaste_2020-04-04_13-58-38.png)

思路比较简单，从左向右遍历一遍将每个识别到的单词入栈，最后一个一个弹出就好了。

### 代码

```cpp
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<string> stk;
        int i=0,j=0,len=s.length();
        //i、j指针用来指向每个单词的首、尾
        while(1){
            i=j;
            while(i<len && s[i]==' ') i++;
            if(i>=len) break;
            j=i;
            while(j<len && s[j]!=' ') j++;
            stk.push(s.substr(i,j-i));//入栈
        }
        if(stk.empty()) return ans;
        ans=stk.top();
        stk.pop();
        while(!stk.empty()){
            ans+=" ";
            ans+=stk.top();
            stk.pop();
        }
        return ans;
    }
};
```