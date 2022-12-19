class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        
        vector<int> vctWordFreq(11,0);
        vector<int> vctRes;
        auto freqOfMinChar = [&](const string& str) ->int
        {
            char min = 'z';
            size_t minFreq = 0;
            for (char ch : str)
            {
                if (ch < min)
                {
                    min = ch;
                    minFreq =1;
                }
                else if (ch == min)
                {
                    ++minFreq;
                };
            }
            return minFreq;
        };
        //将单词表转换成可直接索引的 
        for_each(words.cbegin(),words.cend(),[&](const string& str){
            short minFre = freqOfMinChar(str);
            ++vctWordFreq[minFre];
        });
        
        for_each(queries.cbegin(),queries.cend(),[&](const string& str){
             int sum = 0;
            short minFre = freqOfMinChar(str);
            for_each(vctWordFreq.begin() +minFre+1,vctWordFreq.end(),[&](const int i){sum += i;});
             vctRes.push_back(sum);
        });
        
        return vctRes;
    }
};