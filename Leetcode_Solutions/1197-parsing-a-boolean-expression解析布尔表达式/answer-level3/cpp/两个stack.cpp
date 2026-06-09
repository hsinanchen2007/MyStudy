### 解题思路
两个stack解决
### 代码

```cpp
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st1;
        stack<char> st2;
        for(auto i : expression){
            if(i != ','){
                st1.push(i);
            }
        }

        vector<char> temp;
        char cha;
        
        while(!st1.empty()){
            temp.clear();
            while(st1.top() != '!' && st1.top() != '|' && st1.top() != '&') {
                st2.push(st1.top());
                st1.pop();
            }
            switch(st1.top()){
                case '!':
                    st2.pop();
                    cha = (st2.top() == 't' ? 'f' : 't');
                    st2.pop();
                    st2.pop();
                    st2.push(cha);
                    break;
                case '|':
                    st2.pop();
                    while(st2.top() != ')'){
                        temp.push_back(st2.top());
                        st2.pop();
                    }
                    cha = 'f';
                    for(int i : temp){
                        if(i == 't'){
                            cha ='t';
                            break;
                        }
                    }
                    st2.pop();
                    st2.push(cha);
                    break;
                case '&':
                    st2.pop();
                    while(st2.top() != ')'){
                        temp.push_back(st2.top());
                        st2.pop();
                    }
                    cha = 't';
                    for(int i : temp){
                        if(i == 'f'){
                            cha ='f';
                            break;
                        }
                    }
                    st2.pop();
                    st2.push(cha);
                    break;
            }
            st1.pop();
        }
        return st2.top() == 't' ? true : false;
    }
};
```