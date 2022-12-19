我是易安,努力写最清晰易懂的code.
```
class Solution {
public:
    int calculate(string s) {
        char op = '+';
        int val;
        istringstream iss(s);
        stack<int> st;

        while(iss>>val){
            if(op=='+'){
                st.push(val);
            }else if(op=='-'){
                st.push(-val);
            }else{
                int val2 = st.top(); st.pop();
                if(op=='*') st.push(val*val2);
                else if(op=='/') st.push(val2/val);
            }
            iss>>op;
        }

        int res = 0;
        while(st.size()){
            res += st.top(); st.pop();
        }
        return res;
    }
};
```
