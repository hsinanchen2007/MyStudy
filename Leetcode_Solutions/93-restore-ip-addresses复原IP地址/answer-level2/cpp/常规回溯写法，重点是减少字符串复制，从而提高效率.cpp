class Solution {
public:
    vector<string> restoreIpAddresses(string s) {

        string curr;
        vector<string> ans;
        doRestore(0, s, 0, curr, ans);

        return ans;
    }

    void doRestore(int k, const std::string & s, size_t idx, string & tmp, vector<string> & ans)
    {
        if(k == 4 || idx == s.size())  // 剪枝
        {
            if(k == 4 && idx == s.size())
            {
                ans.push_back(tmp);
            }
            return;
        }

        for(size_t i = idx; i < s.size(); ++i)
        {
            if(i != idx && s[idx] == '0')  // 剪枝
            {
                break;
            }

            size_t len = i - idx + 1;
            size_t appLen = len;
            if(getVal(s, idx, len) <= 255) 
            {
                if(!tmp.empty())
                {
                    tmp.push_back('.');
                    appLen += 1;
                }
                tmp.append(s.data() + idx, len);   // 先追加可能的分段
                doRestore(k + 1, s, i + 1, tmp, ans);
                tmp.erase(tmp.size() - appLen);   // 再删除可能的分段，达到回溯的效果
            }
        }
    }

    int getVal(const std::string & s, size_t idx, size_t len)
    {
        int ans = 0;
        for(size_t i = 0; i < len && ans < 256; ++i)
        {
            ans *= 10;
            ans += s[idx + i] - '0';
        }

        return ans;
    }
};