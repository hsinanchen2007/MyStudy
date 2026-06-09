C++解法
每次根据pre（前一个字符串）生成result（当前字符串）
```
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for(int i = 2; i <= n; i++)
        {
            string pre = result;
            result = "";
            for(int j = 0; j < pre.size(); j++)
            {
                int count = 1;
                while(pre[j] == pre[j+1])
                {
                    j++;
                    count++;
                }
                result += to_string(count);
                result += pre[j];
            }     
        }
        return result;
    }
};
```
