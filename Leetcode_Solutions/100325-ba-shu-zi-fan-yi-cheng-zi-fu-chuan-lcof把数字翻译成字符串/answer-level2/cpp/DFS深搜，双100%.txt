### 解题思路


### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        len = s.length();
        if(len == 0)
            return ans;
        DFS(s, 0, 0);
        return ans;
    }
    void DFS(string s, int index, int n)
    {
        if(n == len)
        {
            ans++;
            return ;
        }
        DFS(s, index + 1, n + 1);
        int temp = (s[index] - '0') * 10 + s[index + 1] - '0';
        if(index < len - 1 && temp < 26 && temp >= 10)
            DFS(s, index + 2, n + 2);
    }
private:
    int ans = 0;
    int len = 0;
};
```