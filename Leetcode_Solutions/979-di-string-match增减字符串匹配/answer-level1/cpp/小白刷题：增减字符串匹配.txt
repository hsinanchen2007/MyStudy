双指针，一0一n，遇到I或者D对应赋值，同时移动指针

代码：
```
class Solution {
public:
    vector<int> diStringMatch(string S) {
        int len = S.length();
        vector<int> ans(len + 1);
        int i = 0,j = len;
        for(int k = 0 ; k < len ; k++) {
            if(S[k] == 'I') {
                ans[k] = i;
                i++;
            }
            else {
                ans[k] = j;
                j--;
            }
        }
        ans[len] = i;
        return ans;
    }
};
```
