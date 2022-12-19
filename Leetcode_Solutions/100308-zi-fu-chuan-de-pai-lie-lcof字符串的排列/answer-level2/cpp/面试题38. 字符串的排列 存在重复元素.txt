```cpp
class Solution {
private:
    vector<string> res;
    vector<bool> used;

    void findPermutation(const string & s, int index, const string & str) {
        if (s.size() == str.size()) {
            res.push_back(str);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
 
            if (used[i] == true) //当前值已被使用，跳过
                continue;
            if( i-1 >= 0 && s[i] == s[i-1] && used[i-1] == false)//当前值未被使用，但和前一个值相等，如果前一个值未被使用，跳过
                continue;

            used[i] = true;
            findPermutation(s, index+1, str+s[i]);
            used[i] = false;
                
        }
    }

public:
    vector<string> permutation(string s) {
        if (s.size() == 0)
            return res;
        
        sort(s.begin(), s.end());
        used = vector<bool>(s.size(), false);

        findPermutation(s, 0, "");
        return res;
    }
};
```