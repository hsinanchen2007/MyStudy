看运行时间4ms大佬代码得到的思路，判断存储当前窗口中和p中元素的个数是否相等，省去了每次滑动窗口时对比表的时间
`class Solution {
public:
    int lib[26];
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        if (s.size() < p.size()) return ret; 
        vector<int> lib(26, 0);
        vector<int> libTemp(26, 0);
        int satify = 0, n = p.size();
        for (auto c : p) {
            lib[c - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (i >= n) {
                if (libTemp[s[i-n] - 'a'] <= lib[s[i-n] - 'a']) satify--;
                else satify++;
                libTemp[s[i-n] - 'a']--;
            }
            if (libTemp[s[i] - 'a'] >= lib[s[i] - 'a']) satify--;
            else satify++;
            libTemp[s[i] - 'a']++;
            if (satify == p.size()) ret.push_back(i - n + 1);
        }
        return ret;
    }
};`