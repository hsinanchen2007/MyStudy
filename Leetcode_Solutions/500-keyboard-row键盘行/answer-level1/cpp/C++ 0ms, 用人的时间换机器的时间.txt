![07e0421bc2f01ffd8ea9bf32ab49c0e.png](https://pic.leetcode-cn.com/0025d821a64d7e97f4a647c849c4d16a89f518cbe4ee8684ab3dfad5b1a3f605-07e0421bc2f01ffd8ea9bf32ab49c0e.png)

class Solution {
private:
    map<char, int> mp;
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        if(words.empty()) return ans;
        mp['q'] = mp['w'] = mp['e'] = mp['r'] = mp['t'] = mp['y'] = mp['u'] = mp['i'] = mp['o'] = mp['p'] = mp['Q'] = mp['W'] = mp['E'] = mp['R'] = mp['T'] = mp['Y'] = mp['U'] = mp['I'] = mp['O'] = mp['P'] = 1;
    mp['a'] = mp['s'] = mp['d'] = mp['f'] = mp['g'] = mp['h'] = mp['j'] = mp['k'] = mp['l'] = mp['A'] = mp['S'] = mp['D'] = mp['F'] = mp['G'] = mp['H'] = mp['J'] = mp['K'] = mp['L'] = 2;
    mp['z'] = mp['x'] = mp['c'] = mp['v'] = mp['b'] = mp['n'] = mp['m'] = mp['Z'] = mp['X'] = mp['C'] = mp['V'] = mp['B'] = mp['N'] = mp['M'] = 3;
        for(int i = 0; i < words.size(); i++){
            int line = mp[words[i][0]];
            int flag = 1;
            for(auto s: words[i]){
                if(mp[s] != line){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};