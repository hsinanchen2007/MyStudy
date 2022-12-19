class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ret;
        vector<int> bucks = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
        for(int i = 0; i < words.size(); i++){
            int tmp = bucks[tolower(words[i][0]) - 'a'];
            int j = 1;
            for(; j < words[i].size(); j++)
                if(bucks[tolower(words[i][j]) - 'a'] != tmp)
                    break;
            if(j == words[i].size())
                ret.push_back(words[i]);
        }
        return ret;
    }
};