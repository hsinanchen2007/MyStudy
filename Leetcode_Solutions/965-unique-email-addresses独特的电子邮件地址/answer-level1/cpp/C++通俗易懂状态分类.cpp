```
class Solution {
public:
int numUniqueEmails(vector<string>& emails)
{
set<string>ans;
for(int i=0;i<emails.size();i++)
{
string temp="";
int flag=1;//每次开始前初始化标记位
for(int j=0;j<emails[i].size();j++)
{
if(emails[i][j]=='+')flag=2;//遇到'+' 本身与后面直到@前都不要
if(emails[i][j]=='@')flag=3;//@后 大人全都要
switch(flag)
{
case 1:if(emails[i][j]!='.')temp+=emails[i][j];break;
case 2:break;
case 3:temp+=emails[i][j];break;
}
}
ans.insert(temp);
}
return ans.size();//set<string>ans;容器会自动去重
}
};


```
