- 使用栈操作即可
```cpp
class Solution {
public:
    NestedInteger deserialize(string S) {
        if(S[0]!='[')return NestedInteger(stoi(S));//如果不是列表直接返回单个数的对象即可
        stack<NestedInteger*>s;
        string num="";
        int n = S.size();
        for(int i=0;i<n;i++){
            if(S[i]=='['){  //是个列表则插入该空列表
                NestedInteger* newNest = new NestedInteger();
                s.push(newNest);
            }else if(S[i]==']'){//如果前面是个数字则把数字插到栈顶列表里面出栈，此时如果栈为空则说明是最后一个]则返回整个列表
                                //否则将出栈的列表插到它的上层列表里面，最后将num清空
                NestedInteger* cur = s.top();
                if(num!="")cur->add(NestedInteger(stoi(num)));
                s.pop();
                if(!s.empty())s.top()->add(*cur);
                else return *cur;
                num="";

            }else if((S[i]>='0' && S[i]<='9') || S[i]=='-' ){//是数字时
                num+=S[i];
            }else{
                if(num!=""){    //是逗号时有两种情况，一种是[... 888,一种是[... ],[...]
                                //将第一种情况的数插入栈顶的列表中再将num清空
                    s.top()->add(NestedInteger(stoi(num)));
                    num="";
                }
            }
        }
        return NestedInteger();
    }
};
```