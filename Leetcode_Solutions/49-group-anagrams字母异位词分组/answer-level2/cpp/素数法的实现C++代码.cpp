每个字符对应一个素数,
记录每个字符串计算的数值,同时记录计算的这个字符串在原来List中的位置
每个字符串计算出来一个数值,对这个数值数组排序,最终数值相同的会排在相邻位置,
然后根据下表和相邻数据对字符串分组.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        double p[26] = {
            2, 3, 5, 7, 11, 13, 17, 19,
            23,29,31,37,41,43,47,53,
            59,61,67,71,73,79,83,89,
            97,101
            
        };
        int len = strs.size();
        vector<vector<string>> ret;
        if(len <= 0)return ret;
        
        struct Double{
            double val;
            int index;
        };
        
        Double *pFlag = new Double[len];
        
        for(int i = 0; i < len; ++i){
            pFlag[i].val = 1.0;
            pFlag[i].index = i;
            
            string &s = strs[i];
            int strLen = s.length();
            for(int j = 0; j < strLen; ++j){
                pFlag[i].val *= p[s[j] - 'a'];
            }
        }
        
        sort(pFlag, pFlag + len, [](Double &a, Double &b){
            return a.val < b.val;
        });
        
        int i = 0;
        
        while(i < len){
            vector<string> vs;
            vs.push_back(strs[pFlag[i].index]);
            ++i;
            while(i < len && pFlag[i].val == pFlag[i - 1].val){
                vs.push_back(strs[pFlag[i].index]);
                ++i;
            }
            ret.push_back(vs);
        }
        
        delete []pFlag;
        return ret;        
    }
};