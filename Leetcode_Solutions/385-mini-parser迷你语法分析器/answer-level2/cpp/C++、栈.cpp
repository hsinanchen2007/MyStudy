执行用时 : 28 ms, 在Mini Parser的C++提交中击败了85.71% 的用户
内存消耗 : 15.5 MB, 在Mini Parser的C++提交中击败了77.50% 的用户
利用栈做的，思路写在注释里了

```
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger F;
        stack<NestedInteger> stk;
        string temp="";
        for(int i=0;i<s.size();i++){
            //当遇到'['时，就创建一个NestedInteger（NI）对象，并压入栈
            if(s[i]=='['){
                auto NewNI=NestedInteger();
                stk.push(NewNI);  
            }
            //当遇到']'时，就从栈中弹出一个NI对象，且如果前一时刻是数字的话（即temp=不为空，比如此时是'...789]'），还要将数字添加到
            //刚弹出的来NI对象中，并清空字符串缓存；然后如果此时栈为空，说明弹出的NI对象是最外层的那个，则程序结束返回；
            //否则，将弹出来的NI对象加入到下一个栈顶的NI对象中
            else if(s[i]==']'){
                NestedInteger cur=stk.top();
                if(temp!="")
                    cur.add(NestedInteger(stoi(temp)));
                stk.pop();
                if(stk.empty())
                    return cur;
                else{
                    //同下，必须为引用
                    NestedInteger& next=stk.top();
                    next.add(cur);
                }
                temp="";
            }
            //如果该位置是数字（含负号），则将其缓存到字符串temp中
            else if('0'<=s[i]&&s[i]<='9'||s[i]=='-'){
                //如果该位置是数字，且栈为空，说明输入只是某数字的字符串，即没有嵌套的情况，则直接返回，比如s="324"
                if(stk.empty())
                    return NestedInteger(stoi(s));
                temp+=s[i];     
            }
            //如果该位置是','，那么有2种情况，即'...789,'或者'[...],',显然是数字的话，需要将其添加到栈顶的NI对象中
            else{
                if(temp!=""){
                    //需要注意的是，必须显示给定NI对象的引用说明，不能使用auto关键字定义cur
                    //因为使用auto的话，stk.top()返回的是栈顶元素的副本，而我们需要对栈顶元素进行修改，必须是引用
                    //或者是不用引用，先将栈顶元素弹出，对其修改后，再push也可
                    NestedInteger& cur=stk.top();
                    cur.add(NestedInteger(stoi(temp)));
                    temp="";
                }
            } 
        }
        return F;
    } 
};
```