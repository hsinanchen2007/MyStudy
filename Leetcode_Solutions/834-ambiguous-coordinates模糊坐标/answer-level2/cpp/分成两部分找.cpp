```
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int i,j,k,len;
        string tmp;
        vector<string> res;
        s.erase(0,1);s.pop_back();
        len = s.length();
        for(k=1;k<len;k++) { //分成左右两部分寻找
            vector<string> left = cal(s.substr(0,k));
            vector<string> right = cal(s.substr(k));
            if(!left.size()||!right.size()) continue; //一个集合不存在元素跳过
            for(i=0;i<left.size();i++) {
                for(j=0;j<right.size();j++) {
                    tmp.clear();
                    tmp.push_back('(');
                    tmp+=left[i];
                    tmp+=", ";
                    tmp+=right[j];
                    tmp.push_back(')');
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
    vector<string> cal(string s) {
        int len = s.length();
        string tmp;
        vector<string> res;
        if(s[len-1]!='0') {//小数情况
            if(s.size()>1&&s[0]=='0') {
                tmp = s;tmp.insert(1,1,'.');
                res.push_back(tmp);
            }else {
                for(int i=1;i<len;i++) {
                    tmp = s;tmp.insert(i,1,'.');
                    res.push_back(tmp);
                }    
            }
        }
        if((s.size()>1&&s[0]!='0')||s.size()==1) res.push_back(s);//整数情况
        return res;
    }
};
```
