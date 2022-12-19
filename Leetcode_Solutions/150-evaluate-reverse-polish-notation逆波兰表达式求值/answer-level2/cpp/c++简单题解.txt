```
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>  temp;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i].size()==1&&(tokens[i][0]=='+'||tokens[i][0]=='-'||tokens[i][0]=='*'||tokens[i][0]=='/'))
            {
                int temp1=temp.top();
                temp.pop();
                int temp2=temp.top();
                temp.pop();
                //cout<<"temp1:"<<temp1<<'.'<<"temp2:"<<temp2<<endl;
                if(tokens[i][0]=='+')
                    temp.push(temp1+temp2);
                else if(tokens[i][0]=='-')
                    temp.push(temp2-temp1);
                else if(tokens[i][0]=='*')
                    temp.push(temp1*temp2);
                else 
                    temp.push(temp2/temp1);
            }
            else 
            {
                temp.push(atoi(tokens[i].c_str()));
            }
            
        }
        return temp.top();
    }
};
```
