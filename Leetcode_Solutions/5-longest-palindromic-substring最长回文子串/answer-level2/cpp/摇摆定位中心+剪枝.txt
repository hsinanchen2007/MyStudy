![image.png](https://pic.leetcode-cn.com/ff2a77e648f0f4d13ea1378b26b57ad5fa178b85f19e720fc90138f655c6bf1c-image.png)
**给get_LPS参数加上了引用的优化效果立竿见影：**
![image.png](https://pic.leetcode-cn.com/12d6c491d033ae424124aa7433992dfcf343e4fe0169715751d46b62a41a2b96-image.png)

### 解题思路
摇摆方式定位可能的中心。
剪枝：一旦不可能获得比现在更长的序列就退出循环

### 代码

```cpp
class Solution {
string get_LPS(const string & s, int idx)
{
    size_t len = s.size();
    int cnt = 1;
    while(idx + cnt < len && idx - cnt >=0)
    {    
        if(s[idx+cnt]!=s[idx-cnt])
            break;
        ++cnt;
    }
    string LPS1 = s.substr(idx-cnt+1, 2*cnt-1);
    cnt = 0;//和向左的一位构成中心
    while(idx + cnt < len && idx - 1 - cnt >=0)
    {
        if(s[idx+cnt]!=s[idx-1-cnt])
            break;
        ++cnt;
    }
    if(cnt == 0) return LPS1;
    string LPS2 = s.substr(idx-cnt, 2*cnt);
    if(LPS1.size() > LPS2.size()) return LPS1;
    else return LPS2;
}
public:
    string longestPalindrome(string s) {
        size_t len = s.size(), idx = len / 2;
        int add = -1;
        string LPS, temp;
        while(idx >= 0 && idx < len)
        {
            if(2*idx+1 - LPS.size()<0) 
                break;
            temp = get_LPS(s, idx);
            if(temp.size() > LPS.size())
                LPS = temp;
            idx += add;
            add = (abs(add) + 1) * (add > 0? -1:1);
        }
        return LPS;
    }
};
```