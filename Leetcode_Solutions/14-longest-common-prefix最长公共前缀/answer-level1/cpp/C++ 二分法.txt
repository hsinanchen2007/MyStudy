```
class Solution {
public:
    bool isCommonPrefix(vector<string>& strs, int mid) {
        for (int i = 1; i < strs.size(); i++)
            if (strs[i].compare(0, mid + 1, strs[0].substr(0,mid+1)) != 0)
                return false;
        return true;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];

        int minLen = INT_MAX;
        for (string str : strs)
            minLen = minLen < str.size() ? minLen : str.size();

        int left = 0;
        int right = minLen;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isCommonPrefix(strs, mid))
                left = mid + 1;
            else
                right = mid ;
        }
        return strs[0].substr(0, right);
    }
};
```
