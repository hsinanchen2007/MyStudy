class Solution {
public:
    vector<string> res;
    vector<string> permutation(string s) {
        string dum_res;//临时string
        sort(s.begin(), s.end());//题意字典序
        vector<int> visited(s.size(), '0');//回溯标记
        permutation(s, visited, dum_res);
        return res;
    }
    void permutation(string s, vector<int> visited, string dum_res){
        if(dum_res.size() == s.size()) res.push_back(dum_res); //临时string的size达到了原size 说明排好了一次。
        else{
            for(int id=0; id<s.size(); id++){
                if(s[id] == s[id-1] && visited[id-1] == '1') continue;
                if(visited[id] == '0'){
                    visited[id] = '1';//进入递归前，标记'1'
                    dum_res.push_back(s[id]);//同时把标记1的 push进去
                    permutation(s, visited, dum_res);
                    //递归第一次结束，取消标记。比如abc，取消a的标记，因为下个循环开始标记b，此时a需要继续使用
                    visited[id] = '0';
                    dum_res.pop_back();//同理
                }
            }
        }
    }
};