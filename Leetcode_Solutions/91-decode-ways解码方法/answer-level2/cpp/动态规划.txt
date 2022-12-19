```
class Solution {
public:
    int numDecodings(string s) {
       if(s.empty() || s[0] == '0') return 0;
        
        int len = s.size();
        vector<int> count(len+1,0);
        count[0] = 1;  //虚拟位置
        count[1] = 1;
        
        for(int i = 2;i < len+1;++i){  //从第二个字符开始
            if(s[i-1] == '0')
            {
                if(s[i-2] == '0') return 0;
                
                if(s[i-2] == '1' || s[i-2] == '2')
                {
                    count[i] = count[i-2];
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6'))
                {
                    count[i] = count[i-2];
                    count[i] += count[i-1];
                }
                else
                {
                    count[i] = count[i-1];
                }
            }
        }
        
        return count[len];
    }
};
![解码方法.png](https://pic.leetcode-cn.com/087be89b7cbe83aa905d89f6ae62be1693d7f5d3851e5058a70dd8836e627d42-%E8%A7%A3%E7%A0%81%E6%96%B9%E6%B3%95.png)
```
