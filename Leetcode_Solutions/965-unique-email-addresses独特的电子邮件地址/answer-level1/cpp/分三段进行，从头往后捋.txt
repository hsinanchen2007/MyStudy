### 解题思路
一.标准化每个邮箱为tmp后放到set，返回set.size()。
二.每一个字符串 分为三段进行，从头往后捋：
    1.tmp+=email[i],遇到'+'或者'@'停下；
    2.while(email[i]!='@')  i++;
    3.tmp+=email[i++]。

### 代码

```cpp
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> res;
        for(int i = 0;i<emails.size();i++){
            string cur = getemail(emails[i]);
            res.insert(cur);
        }
        return res.size();
    }
    string getemail(string email){
        string tmp;
        int i=0;
        while(email[i]!='@'&&email[i]!='+'){
            if(email[i]!='.')
                tmp+=email[i];
            i++;
        }
        while(email[i]!='@')
            i++;
        while(i<email.size())
            tmp+=email[i++];
        return tmp;
    }
};
```