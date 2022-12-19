

### 代码

```cpp
class Solution {
public:
   
    string frequencySort(string s) {
        string str = "";
        int a[256] = {0};////整个ASCII码
        int maxn = 0;//记录最大
        for(int i = 0;i < s.length();i++)
        {
            a[s[i] - 0]++;
            if(a[s[i] - 0] > maxn)
            maxn = a[s[i] - 0];
        }
        while(maxn)//从最多数开始寻找
        {
            for(int i = 0 ;i < 256;i++)
            {
                if(a[i] == maxn)
                {
                    for(int j = 0;j < a[i];j++)
                    {
                        char c = toascii(i);
                        str += c;
                    }
                }
            }
            maxn--;
        }
        return str;
    }
};
```