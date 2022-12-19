用栈模拟过程。
```
class Solution {
public:
    struct node{
        char x;
        int num;
        node(){}
        node(char _x,int _n){
            x=_x,num=_n;
        }
    };
    stack<node>st;
    string removeDuplicates(string s, int k) {
        for(int i=0;i<s.length();i++){
            if(st.empty()) st.push(node(s[i],1));
            else{
                if(st.top().x==s[i]){
                    st.top().num++;
                    if(st.top().num==k) st.pop();
                }
                else st.push(node(s[i],1));
            }
        }
        string ans="";
        while(!st.empty()){
            int n=st.top().num;
            while(n--) ans+=st.top().x;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
```
