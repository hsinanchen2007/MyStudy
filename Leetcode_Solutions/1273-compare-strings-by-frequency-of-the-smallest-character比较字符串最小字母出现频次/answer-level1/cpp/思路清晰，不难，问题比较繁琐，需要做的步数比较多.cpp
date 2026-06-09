```
class Solution {
public:
    int fuc(string s){  //f函数，输出最小字母的计数
        int res=0;
        char temp=s[0];
        for(int i=0;i<s.size();i++){
            if(s[i]-'a'<temp-'a'){
                temp=s[i];
                res=1;
            }else if(s[i]==temp){
                res++;
            }
        }
        return res;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fwords, fqueries, res;       //直接将两个字符串数组转化为f函数输出的整型数组
        for(int i=0;i<words.size();i++){
            fwords.push_back(fuc(words[i]));
        }
        sort(fwords.begin(),fwords.end(),greater<int>()); //将words的计数从大到小排序
        for(int i=0;i<queries.size();i++){
            fqueries.push_back(fuc(queries[i]));
        }
        for(int i=0;i<fqueries.size();i++){  //遍历queries数组，每次输出words中比他大的数量
            int count=0;
            for(int j=0;j<fwords.size();j++){
                if(fqueries[i]<fwords[j]){
                    count++;
                }else{
                    break;
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
```
