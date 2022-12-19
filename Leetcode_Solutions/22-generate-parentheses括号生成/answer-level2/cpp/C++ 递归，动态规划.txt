```
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results; 
        std::unordered_map<int, vector<string>> subs;
        if(n==0)
            results.push_back("");
        else{
            vector<string> temp1;
            vector<string> temp2;
            for(int i =0;i < n;++i){
                if(subs.find(i)==subs.end()) subs[i] = generateParenthesis(i);
                if(subs.find(n-i-1)==subs.end()) subs[n-i-1] = generateParenthesis(n-i-1);
                temp1 = subs[i];
                temp2 = subs[n-i-1];
                for(auto str1 = temp1.begin();str1<temp1.end();++str1)
                    for(auto str2 = temp2.begin();str2<temp2.end();++str2){
                        
                        results.push_back("("+*str1+")"+*str2);
                    }
            }
        }
        return results;
    }
};

```
先确定与最左边"("对应的")", 对其他能出现的位置进行遍历。确定")"的位置后，问题被分为最左侧"("和其对应的")"中间部分和")"右侧部分两个子问题。递归求解子问题即可。另外，发现相同的n对应的解一定相同，于是用hash_map记录找到的每个子问题的解，空间换时间。