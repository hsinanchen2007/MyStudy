### 解题思路
....怎么说呢。。聪明的我用栈和结构体就完成了。

### 代码

```cpp
#include <stack>

struct Node{
    char c;     //字符
    int count;
    Node(char c, int count = 0){
        this->c = c;
        this->count = count;
    }
};

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<Node> sta;
        sta.push(Node('#'));
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                sta.push(Node('('));
            }else{
                if(sta.top().c == '('){
                    int temp = sta.top().count + 2;
                    sta.pop();
                    sta.top().count += temp;
                }else{
                    sta.push(Node(')'));
                }
            }
        }

        int max = 0;
        while(!sta.empty()){
            int temp = sta.top().count;
            if(temp > max){
                max = temp;
            }
            sta.pop();
        }

        return max;
    }
};
```