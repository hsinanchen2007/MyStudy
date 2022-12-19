```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        
        for(auto x:tokens)
        {
            if(x=="+")
            {
                int temp=0;
                int a=stoi(st.top());
                st.pop();
                int b=stoi(st.top());
                st.pop();
                temp+=b+a;
                st.push(to_string(temp));
            }
            else if(x=="-")
            {
                int temp=0;
                int a=stoi(st.top());
                st.pop();                
                int b=stoi(st.top());
                st.pop();                
                temp+=b-a;
                st.push(to_string(temp));
            }
            else if(x=="*")
            {
                int temp=0;
                 int a=stoi(st.top());
                st.pop();
                int b=stoi(st.top());
                st.pop();
                temp+=a*b;
                st.push(to_string(temp));
            }
            else if(x=="/")
            {
                int temp=0;
                int a=stoi(st.top());
                st.pop();
                int b=stoi(st.top());
                st.pop();
                temp+=b/a;
                st.push(to_string(temp));
            }
            else
            {
                st.push(x); 
            }
            
        }
        return stoi(st.top());

    }
};
```


