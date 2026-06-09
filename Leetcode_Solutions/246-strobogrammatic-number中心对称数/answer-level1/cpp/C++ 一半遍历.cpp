思路简单，见代码即可：
```
class Solution {
public:
    unordered_map<char, char> M = {
        {'1', '1'}, {'0', '0'}, {'8', '8'}, 
        {'6', '9'}, {'9', '6'}};
    bool isStrobogrammatic(string num) {
        int N = num.size();
        for (int i = 0; i <= N / 2; ++i) {
            if (M.count(num[i]) == 0 || M[num[i]] != num[N - 1 - i]) return false;
        }
        return true;
    }
};
```
![image.png](https://pic.leetcode-cn.com/22978b7769aaa88acc5daefb80f50a678abd64de7e80a4a0b7b5e90ca6724b36-image.png)

