![image.png](https://pic.leetcode-cn.com/aea01356d20db79f9d09b9498b52d42129562625ee4eefa6d29f47e355b9599b-image.png)

思路：先利用哈希表把所有括号对`[]`的位置存起来，就能实现`O(N)`的搜索了

```cpp
class Solution {
public:
    string decodeString(string s) {
        vector<int> left_bracket;
        unordered_map<int, int> brackets;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '[') {
                left_bracket.push_back(i);
            }
            else if (s[i] == ']') {
                brackets[left_bracket.back()] = i;
                left_bracket.pop_back();
            }
        }
        return decode(s, 0, s.size(), brackets);
    }
    string decode(string& s, int left, int right, unordered_map<int, int>& brackets) {
        //如果数字打头
        if (s[left] >= '0' && s[left] <= '9') {
            int sub_left = s.find('[', left);
            int i = stoi(s.substr(left, sub_left-left));
            string sub = decode(s, sub_left+1, brackets[sub_left], brackets);
            string result;
            for (int x = 0; x < i; x++) {
                result += sub;
            }
            return result + decode(s, brackets[sub_left]+1, right, brackets);
        }
        else {
            for (int i = left; i <= right; i++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    return s.substr(left, i-left) + decode(s, i, right, brackets);
                }
            }
            return s.substr(left, right-left);
        }
    }
};
```