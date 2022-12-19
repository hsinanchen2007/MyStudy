    class Solution {
    private:
        static bool campare(pair<string,int> p1,pair<string,int> p2){
            if(p1.second < p2.second)
                return false;
            if(p1.second > p2.second)
                return true;
            
            return p1.first < p2.first;   
        }
    public:
        vector<string> topKFrequent(vector<string>& words, int k) {
            vector<string> res;
            if(words.size() == 0)
                return res;
            
            vector<pair<string,int>> W;
            unordered_map<string,int> freq;
            for(int i = 0;i < words.size();++i)
                ++freq[words[i]];
            
            unordered_map<string,int>::iterator it = freq.begin();
            while(it != freq.end())
            {
                pair<string,int> p(it->first,it->second);
                W.push_back(p);
                ++it;
            }
            sort(W.begin(),W.end(),campare);
            for(int i=0;i<k;i++)
                res.push_back(W[i].first);
            
            return res;
        }
    };