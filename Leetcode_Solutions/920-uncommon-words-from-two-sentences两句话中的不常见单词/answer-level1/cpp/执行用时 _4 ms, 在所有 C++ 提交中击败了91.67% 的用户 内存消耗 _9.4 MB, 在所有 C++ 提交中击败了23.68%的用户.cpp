class Solution {
public:
    std::map<std::string,int> splitWithStl(const std::string& str, const std::string& pattern)
    {
        std::map<std::string,int> resVec;

        if ("" == str) {
            return resVec;
        }
        //方便截取最后一段数据
        std::string strs = str + pattern;

        size_t pos = strs.find(pattern);
        size_t size = strs.size();

        while (pos != std::string::npos) {
            std::string x = strs.substr(0, pos);
//            resVec.push_back(x);
            if(resVec.count(x)){
                resVec[x] +=1;
            }else{
                resVec[x] = 1;
            }
            strs = strs.substr(pos + 1, size);
            pos = strs.find(pattern);
        }

        return resVec;
    }

    vector<string> uncommonFromSentences(string A, string B) {
        std::map<std::string,int> avec = splitWithStl(A, " ");
        std::map<std::string,int> bvec = splitWithStl(B, " ");
        std::vector<std::string>res;
        for(auto it : avec){
            if(it.second == 1 && !bvec.count(it.first)){
                res.push_back(it.first);
            }
        }
        for(auto it : bvec){
            if(it.second == 1 && !avec.count(it.first)){
                res.push_back(it.first);
            }
        }
        return res;
    }
};