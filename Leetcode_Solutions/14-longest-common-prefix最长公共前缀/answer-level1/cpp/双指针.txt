

### 代码

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //解题思路 双指针
        //m为字符串数组中最短的字符串中字符的个数；i是字符串数组中字符串的个数
        int n = strs.size();
        string ans = "";
        //n == 0和n == 1两种特殊情况
        while(n == 0)
        return ans;
        while(n == 1){
            ans = strs[n - 1];
            return ans;
        }
        sort(strs.begin(), strs.end());
        string temp = strs[0], left, right;
        int m = temp.size();
        while(m){
        for(int i = 0; i < n - 1; i++)
        {
            left = strs[i];
            right = strs[i + 1];
            int j = temp.size() - m;
            if(left[j] == right[j]){
                while(i == n - 2){
                    ans += left[j];
                    break;
                }
                continue;
            }else{
                m = 1;
                break;
            }
        }
        m--;
        }
        return ans;
    }
};
```