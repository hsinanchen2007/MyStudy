class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        string temp;
        for(int i=0; i<s2.size(); i++)
        {
            temp="";
            temp+=s2[i];
            int pos = s1.find(temp);
            if(pos==-1) return false;
            s1.erase(pos,1);
        }
        return true;
    }
};