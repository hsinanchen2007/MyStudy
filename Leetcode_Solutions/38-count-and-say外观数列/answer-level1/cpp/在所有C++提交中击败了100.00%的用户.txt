### 解题思路
![image.png](https://pic.leetcode-cn.com/bfa8a96b43eada0a62f8cfe98a7d24e2fb937b296105e34806263a45257b8ef0-image.png)

### 代码

```cpp
class Solution {
    string ans;
    void count(int n, string str)
    {
        char len = '1';
        string str1 = "";
        if(n == 1)
        {
        ans = str;
        return;
        }
        for(int i = 0; i < str.size(); i++)
        {
           // if(i + 1 < str.size())
          //  {
                 
            while(str[i] == str[i + 1])
            {
                ++len;
                i++;
            }
                str1 += len;
                len = '1';
                str1 += str[i];
          //  }
        }
        count(n - 1, str1);
    }
public:
    string countAndSay(int n) {   
        if(n == 1)
        return "1";
        count(n, "1");
        return ans;
    }
};
```