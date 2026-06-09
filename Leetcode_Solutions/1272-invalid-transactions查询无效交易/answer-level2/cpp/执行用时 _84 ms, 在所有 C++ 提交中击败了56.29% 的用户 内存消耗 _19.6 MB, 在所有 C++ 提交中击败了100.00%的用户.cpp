class Solution {
public:
    struct Info{
        int time;
        int jine;
        std::string transaction;
    };
    void splitWithStl(const std::string& str, const std::string& pattern,
                      std::unordered_map<std::string,std::unordered_map<std::string, std::vector<Info> > >& res)
    {
        std::vector<std::string> resVec;
        if ("" == str) {
            return;
        }
        //方便截取最后一段数据
        std::string strs = str + pattern;

        size_t pos = strs.find(pattern);
        size_t size = strs.size();
        while (pos != std::string::npos) {
            std::string x = strs.substr(0, pos);
            resVec.push_back(x);
            strs = strs.substr(pos + 1, size);
            pos = strs.find(pattern);
        }
        //名称，时间（以分钟计），金额以及城市
        Info info;
        info.jine = atoi(resVec[2].c_str());
        info.time = atoi(resVec[1].c_str());
        info.transaction = str;
        res[resVec[3]][resVec[0]].push_back(info);
    }

    bool isValid(const std::string name,const std::string& city, int time,
                 std::unordered_map<std::string,std::unordered_map<std::string, std::vector<Info> > >& all){
        for(auto& it : all){
            if(it.first != city){
                for(int i = 0;i < it.second[name].size();i ++){
                    if(it.second.count(name) && abs(time - it.second[name][i].time) <= 60){
                        return false;
                    }
                }

            }
        }
        return true;
    }

    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> res;
        std::unordered_map<std::string,std::unordered_map<std::string, std::vector<Info> > >allinfortion;
        for(int i = 0;i < transactions.size();i ++){
            splitWithStl(transactions[i], ",", allinfortion);
        }
        for(auto& it : allinfortion){
            for(auto& jiaoyi : it.second){
                for(int i = 0;i < jiaoyi.second.size();i ++){
                    if(jiaoyi.second[i].jine > 1000)
                        res.push_back(jiaoyi.second[i].transaction);
                    else{
                        std::string name = jiaoyi.first;
                        if(!isValid(name,it.first, jiaoyi.second[i].time,allinfortion))
                            res.push_back(jiaoyi.second[i].transaction);
                    }
                }

            }
        }
        return res;
    }
};