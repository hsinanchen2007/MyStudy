class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        int wordsLen = words.size();
        int posa = -1,posb = -1,minLen = wordsLen;
        for(int i = 0;i<wordsLen;++i)
        {
            if(words[i] == word1)
            {
                posa = i;
            }
            if(words[i] == word2)
            {
                posb = i;
            }
            if(posa>=0 && posb>=0)
            {
                minLen = min(minLen,abs(posa-posb));
            }
        }
        return minLen;
    }
};