

首先利用栈储存pair，pair中的first为char，保存字符串中的符号，即'('和')'，second为int类型，保存下标。然后新开一个与string长度相同的数组p，初始化为0，用于存放括号匹配情况。
主要思路就是遍历一遍，把'('压入栈，遇到')'，则弹出栈，同时获取其下标位置，在p中将相应下标的值改为2，遍历后便可得到括号匹配情况。
如"(()))"对应的p数组的值为2 2 0 0 0；"()()(("对应的p数组的值为 2 0 2 0 0 0；"((()))()(" 对应的p数组为 2 2 2 0 0 0 2 0 0
针对数组p进行分析可知最长的有效括号长度即为当2和0数量匹配的最长子串长度。如上面所举第一个例子，出现了两个2，则后面会有两个0与之匹配，此时若下一个为0，则到此为止；若下一个为2则继续寻找0进行匹配。进行一遍遍历后便可得到最长长度

```c++ []
class Solution {
public:
    typedef pair<char,int> PCI;
    int longestValidParentheses(string s) {
        if(s.empty()) return 0;
        int l=s.length();
        int *p=new int[l]{0};
        int maxL=0;
        stack<PCI> stk;
        for(int i=0;i<l;i++){
            if(s.at(i)==')'){
                if(!stk.empty()){
                    p[stk.top().second]=2;
                    stk.pop();
                }
            }
            else stk.push({s.at(i),i});
        }
        for(int i=0;i<l;i++){
            int single=0;
            if(p[i]!=0){
                single+=2;
                int con=1;
                i++;
                //寻找2和0的匹配
                while(i<l && con>=0){
                    if(p[i]==0) con--;
                    else con++,single+=2;
                    i++;
                }
                i--;
                maxL=max(maxL,single);
            }
        }
        return maxL;
    }
};
```


