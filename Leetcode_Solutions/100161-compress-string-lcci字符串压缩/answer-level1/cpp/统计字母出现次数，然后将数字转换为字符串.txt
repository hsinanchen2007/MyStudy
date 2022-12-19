### 解题思路
change函数是为了将数字转换为字符串，并返回

在主函数中，通过两层遍历来获取字符出现的次数，然后在该字符后加上数字
最后比较一下得到的字符串和原先字符串的长度，返回较短的字符串

### 代码

```cpp
class Solution {
public:
    string change(int x){
        int t;
        string ans = "",strans = "";
        
        while(x > 0){
            t = x % 10;
            x = x / 10;
            ans += t + '0';
        }

        t = ans.size();

        for(int i = t-1;i >=0;--i){
            strans += ans[i];
        }

        return strans;
    }

    string compressString(string s) {
        string res = "";
        char ch;
        int i,j,t,len = s.size();
        
        for(i = 0;i<len;i = j){
            t = 1;
            ch = s[i];
            res += ch;

            for(j = i+1;s[j] == ch;j++){
                    t++;
            }

            res += change(t);
        }

        if(res.size() < len)
            return res;
        else
            return s;
    }
};
```