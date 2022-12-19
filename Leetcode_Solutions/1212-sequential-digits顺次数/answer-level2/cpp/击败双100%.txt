### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        h = high;
        l = low;
        l_length = to_string(low).length();
        h_length = to_string(high).length();
        string init = "12";
        DFS(init);
        return ans;
    }
    void DFS(string s)
    {
        if(s.length() >= 10)
            return ;
        int num = stoi(s);
        if((num >= l && num <= h) || (s.length() >= l_length && s.length() <= h_length))
        {
            if(num >= l && num <= h)
                ans.push_back(num);
            string ss = s;
            int backNum = ss.back() - '0';
            backNum++;
            for(; backNum < 10 ; backNum++)
            {
                ss = ss.substr(1) + to_string(backNum);
                int tempNum = stoi(ss);
                if(tempNum > h)
                    break;
                if(tempNum >= l && tempNum <= h)
                    ans.push_back(tempNum);
            }
        }
        if(num > h)
        {
            return ;
        }
        int backNum = s.back() - '0';
        backNum++;
        string temp = s + to_string(backNum);
        DFS(temp);
    }
private:
    vector<int> ans;
    int h, l;
    int l_length = 0;
    int h_length = 0;
};
```