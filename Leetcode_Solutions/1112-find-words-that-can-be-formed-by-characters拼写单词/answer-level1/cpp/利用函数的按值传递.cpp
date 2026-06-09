class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> a(256,0);
        int ans = 0;
        for(auto x : chars) a[x]++;
        for(auto x : words)
        {

            if(IsEnable(a,x)) ans += x.size();
        }
        return ans;
    }

    bool IsEnable(vector<int> a,string word)
    {
        for(auto x : word)
        {
            if(!a[x]) return false;
            else a[x]--;
        }
        return true;
    }
};