```
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>>res;
        map<vector<int>,int>mp;
        for(int i=0;i<words.size();i++){
            string s=words[i],ss;
            reverse(s.begin(),s.end());
            ss+=words[i]+s;//寻找word[i]在前面的回文对
            for(int j=0;j<=words[i].size();j++){
                if(ss.substr(0,j)==ss.substr(ss.size()-j)){//word[i]有从左边开始的长度为j的回文串
                    string str=ss.substr(words[i].size(),ss.size()-j-words[i].size());//word[i]除去回文部分的倒序
                    vector<string>::iterator it=find(words.begin(),words.end(),str);//倒序是否存在于字典中
                    int k=std::distance(words.begin(),it);//倒序在字典中的索引
                    if(words.size()>k&&k!=i&&mp.count({k,i})==0){//倒序存在，且不是自身，且未被压入res
                        res.push_back({k,i});
                        mp[{k,i}]=1;
                    }
                }
            }
            ss.erase(0);
            ss+=s+words[i];//寻找word[i]在后面的回文对
            for(int j=0;j<=words[i].size();j++){
                if(ss.substr(0,j)==ss.substr(ss.size()-j)){//word[i]有从右边开始的长度为j的回文串
                    string str=ss.substr(j,words[i].size()-j);//word[i]除去回文部分的倒序
                    vector<string>::iterator it=find(words.begin(),words.end(),str);//倒序是否存在于字典中
                    int k=std::distance(words.begin(),it);//倒序在字典中的索引
                    if(words.size()>k&&k!=i&&mp.count({i,k})==0){
                        res.push_back({i,k});
                        mp[{i,k}]=1;
                    }
                }
            }
        }
        return res;
    }
};
```
