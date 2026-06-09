先遍历字符串S记录字符C的所在位置

之后再遍历字符串S，由于已经记录了C的位置因此只要寻找最近位置差值即可

代码：
```
class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.length();
        vector<int> ans(len, -1);
        vector<int> pos;
        for (int i = 0; i < len; i++) {
            if (S[i] == C) {
                ans[i] = 0;
                pos.push_back(i);
            }
        }
        int left = -1, right = 0;
        int num = pos.size();
        for (int i = 0; i < len; i++) {
            if (right == num)
                ans[i] = i - pos[num - 1];
            else {
                if (i == pos[right]) {
                    left++;
                    right++;
                }
                else if (i < pos[right]) {
                    if (left == -1)
                        ans[i] = pos[right] - i;
                    else
                        ans[i] = (2 * i < pos[left] + pos[right]) ? (i - pos[left]) : (pos[right] - i);
                }
            }
        }
        return ans;
    }
};
```
