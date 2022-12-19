
unordered_map<char, int> static charMap;
class Solution {
public:
     //unordered_map<char, int> static charMap;
    void InitRelation(string& S)
    {
        charMap.clear();
        for (int i = 0; i < S.size(); ++i) {
            charMap[S[i]] = i;
        }
    }
    bool static Cmp(char a, char b)
    {
        if (charMap.count(a) > 0 && charMap.count(b)) {
            return charMap[a] < charMap[b];
        }
        else if (charMap.count(a) > 0){
            return true;
        }
        else if (charMap.count(b) > 0)
        {
            return false;
        }
        else {
            return a < b;
        }
    }
    string customSortString(string S, string T) {
        
        InitRelation(S);
        sort(T.begin(), T.end(),Cmp);

        return T;
    }
};