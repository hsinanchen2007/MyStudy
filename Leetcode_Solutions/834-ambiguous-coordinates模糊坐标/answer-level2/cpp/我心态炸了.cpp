![批注 2020-04-03 002338.png](https://pic.leetcode-cn.com/76f0ad7048cd5ad5c8239ddabf7cea411ce1f10025035f39b6c327b0a50e640f-%E6%89%B9%E6%B3%A8%202020-04-03%20002338.png)
我心态炸了！
我心态炸了！
我心态炸了！
谨以此纪念我逝去的青春，生活不易，且行且珍惜！
```
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        vector<pair<string,string>> cur;
        S = S.substr(1,S.size()-2);
        for(int i =1;i<S.size();++i){
            cur.push_back({S.substr(0,i),S.substr(i,S.size()-i)});
        }
        for(int i =0;i<cur.size();++i){
            if(is_digit(cur[i].first))
            {
                if(is_digit(cur[i].second))
                {
                    string tmp = '('+cur[i].first+", "+cur[i].second+')';
                    res.push_back(tmp);
                }
                if(is_float(cur[i].second)){
                    int sz = cur[i].second.size();
                    string tmp = '('+cur[i].first+", "+cur[i].second.substr(0,1)+"."+cur[i].second.substr(1,sz-1)+')';
                    res.push_back(tmp);
                    if(cur[i].second[0]!='0'){
                    for(int j =1;j<sz-1;++j){
                            string curTmp = '('+cur[i].first+", "+cur[i].second.substr(0,j+1)+"."+cur[i].second.substr(j+1,sz-j-1)+')';
                            res.push_back(curTmp);
                        }
                    }
                }
            }
            if(is_float(cur[i].first)){
                if(is_digit(cur[i].second))
                {
                    int sz = cur[i].first.size();
                    string tmp = '('+cur[i].first.substr(0,1)+"."+cur[i].first.substr(1,sz-1)+", "+cur[i].second+')';
                    res.push_back(tmp);
                    if(cur[i].first[0]!='0'){
                        for(int j =1;j<sz-1;++j){
                            string curTmp = '('+cur[i].first.substr(0,j+1)+"."+cur[i].first.substr(j+1,sz-j-1)+", "+cur[i].second+')';
                            res.push_back(curTmp);
                        }
                    }
                }
                if(is_float(cur[i].second)){
                    int sz1 = cur[i].first.size();
                    int sz2 = cur[i].second.size();
                    if(cur[i].first[0]=='0'){
                         string tmp1 = '('+cur[i].first.substr(0,1)+"."+cur[i].first.substr(1,sz1-1)+", ";
                         if(cur[i].second[0]=='0')
                         {
                             string tmp2 = tmp1+cur[i].second.substr(0,1)+"."+cur[i].second.substr(1,sz2-1)+")";
                             res.push_back(tmp2);
                         }
                         else
                         {
                             string tmp2 = tmp1+cur[i].second.substr(0,1)+"."+cur[i].second.substr(1,sz2-1)+")";
                             res.push_back(tmp2);
                             for(int j =1;j<sz2-1;++j){
                            string curTmp = tmp1+cur[i].second.substr(0,j+1)+"."+cur[i].second.substr(j+1,sz2-1)+")";
                            res.push_back(curTmp);
                         }
                    }
                    }
                    else
                    {
                        int sz1 = cur[i].first.size();
                        int sz2 = cur[i].second.size();
                        string tmp1 = '('+cur[i].first.substr(0,1)+"."+cur[i].first.substr(1,sz1-1)+", ";
                        if(cur[i].second[0]=='0')
                         {
                             string tmp3 = tmp1+cur[i].second.substr(0,1)+"."+cur[i].second.substr(1,sz2-1)+")";
                             res.push_back(tmp3);
                             for(int j =1;j<sz1 - 1;++j){
                                 string curTmp1 = '('+cur[i].first.substr(0,j+1)+"."+cur[i].first.substr(j+1,sz1-j-1)+", ";
                             string tmp2 = curTmp1+cur[i].second.substr(0,1)+"."+cur[i].second.substr(1,sz2-1)+")";
                             res.push_back(tmp2);
                             }
                         }
                         else{
                             string tmp2 = tmp1+cur[i].second.substr(0,1)+"."+cur[i].second.substr(1,sz2-1)+")";
                             res.push_back(tmp2);

                             for(int k =1;k<sz2-1;++k){
                                     string curTmp2 = tmp1+cur[i].second.substr(0,k+1)+"."+cur[i].second.substr(k+1,sz2-k-1)+")";
                                     cout<<curTmp2;
                                     res.push_back(curTmp2);
                             }

                             for(int j =1;j<sz1 - 1;++j){
                                 string curTmp1 = '('+cur[i].first.substr(0,j+1)+"."+cur[i].first.substr(j+1,sz1-j-1)+", ";
                                     string curTmp3 = curTmp1+cur[i].second.substr(0,1)+"."+cur[i].second.substr(1,sz2-1)+")";
                                     res.push_back(curTmp3);
                             
                                     for(int k =1;k<sz2-1;++k){
                                     string curTmp2 = curTmp1+cur[i].second.substr(0,k+1)+"."+cur[i].second.substr(k+1,sz2-k-1)+")";
                                     res.push_back(curTmp2);
                                     }
                                 
                             }
                         }

                    }
                    

                }
            }
        }
        return res;
    }
    bool is_digit(string s)
    {
        if(s.size()==1)
            return true;
        else{
            if(s[0]=='0')
                return false;
            else
                return true;
        }
    }
    bool is_float(string s){
        if(s.size()==1)
            return false;
        else{
            if(s[s.size()-1]=='0')
                return false;
            else
                return true;
        }
    }
};
```
