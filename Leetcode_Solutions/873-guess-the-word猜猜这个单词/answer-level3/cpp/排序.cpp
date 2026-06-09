
![图片.png](https://pic.leetcode-cn.com/9481ac14f74ff3ba68c701e0c267550de6b8d54382913c084b21b27009af17bc-%E5%9B%BE%E7%89%87.png)



unordered_map<string, int> urm;
void InitWordRank(vector<string> &wordlist) {
    urm.clear();
    for (auto s : wordlist) {
        bitset<26> bs;
        for(auto c : s) {
            int idx = c- 'a';
            bs[idx] = 1;            
        }
        urm[s] = bs.count();
    }
}
int RankMatch(string & wd1, string & wd2) {
    bitset<6> bs;
    for(int i = 0 ; i < wd1.size(); i++) {
        bs[i] = (wd1[i] == wd2[i]);
    }
    return bs.count();
}
struct RankLessCmp {
    bool operator()(const string & wd1, const string & wd2) const {
        return urm[wd1] >= urm[wd2];
    }
};

class Solution {
public:
    set<string, RankLessCmp> ss;
    void findSecretWord(vector<string>& wordlist, Master& master) 
    {
        int guessCnt = 0;
        InitWordRank(wordlist);
        for(auto s : wordlist) {
            ss.insert(s);
        }
        while(!ss.empty() && guessCnt <= 10) {
            string sTest = *(ss.begin());
            int tmp = master.guess(sTest);
            guessCnt++;
            ss.erase(ss.begin());
            for(auto it = ss.begin(); it != ss.end();it++) {
                string sCheck = *it;
                int diff = RankMatch(sCheck, sTest);
                if (diff != tmp) {
                    ss.erase(it);                    
                }                 
            }
        }
    }
};