执行用时 :
36 ms
, 在所有 C++ 提交中击败了
87.97%
的用户
内存消耗 :
12.4 MB
, 在所有 C++ 提交中击败了
82.14%
的用户
```c++ []
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        for(int i=0;i<emails.size();i++){
            string temp="";int flag=1;      //把每个字符串分成3种状态，初始为1，即遇到+号之前的状态
            for(int j=0;j<emails[i].size();j++){
                if(emails[i][j]=='+')       //遇到+号之后，temp不加任何元素
                    flag=0;
                if(emails[i][j]=='@')       //遇到@之后，temp加任何元素
                    flag=2;
                switch(flag){
                    case 1:if(emails[i][j]!='.')temp+=emails[i][j];break;
                    case 2:temp+=emails[i][j];break;
                    case 0:break;
                }
            }
            ans.insert(temp);  
}
        return ans.size();
    }
};
```