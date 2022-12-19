### 解题思路
就是有点慢

### 代码

```cpp
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        DFS(0, 0, 0, num, 0, 0);
        return ans;
    }
    void DFS(int n, int h, int m, int num, int hi, int mi)
    {
        if(n >= num)
        {
            if(h > 11)
            return ;
            if(m > 59)
            return ;
            string temp = "";
            temp += to_string(h) + ":";
            if(m < 10)
            temp += "0" + to_string(m);
            else
            temp += to_string(m);
            if(find(ans.begin(), ans.end(), temp) == ans.end())
                 ans.push_back(temp);
            return ;
        }
        for(int i = hi ; i < 4 ; ++i)
        {
            DFS(n + 1, h + a[i], m, num, i + 1, mi);
        }
        for(int i = mi ; i < 6 ; ++i)
        {
            DFS(n + 1, h, m + b[i], num, hi, i + 1);
        }
    }
private:
    int a[5] = {1, 2, 4, 8};
    int b[7] = {1, 2, 4, 8, 16, 32};
    vector<string> ans;
};
```