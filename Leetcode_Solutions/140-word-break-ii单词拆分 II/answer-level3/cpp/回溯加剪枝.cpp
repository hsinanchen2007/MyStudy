    /*
    回溯的部分挺简单的，但是如果不剪枝的话有一个测试用例过不去，这里用了一个visit数组记录了index后续的序列是否可拆分，
    实现了剪枝，减少了失败情况下的重复计算，运行时间在10-20ms之间
    */
    int m;
    string temp="";
    vector<string> resource;
    bool backtracking(string &s,vector<string> &wordDict,vector<bool> &visit,int index){
        if(index==m){
            resource.push_back(temp.substr(0,temp.size()-1));
            return true;
        }
        if(visit[index]==false)return false;
        
        bool res=false;
        for(string str:wordDict){
            if(s.substr(index,str.size())==str){
                int tempsize=temp.size();
                temp.append(str);
                temp.append(" ");
                res=backtracking(s,wordDict,visit,index+str.size())||res;
                temp.erase(tempsize,str.size()+1);
            }
        }
        visit[index]=res;
        return res;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        m=s.size();
        vector<bool> visit(m,true);
        backtracking(s,wordDict,visit,0);
        return resource;
    }