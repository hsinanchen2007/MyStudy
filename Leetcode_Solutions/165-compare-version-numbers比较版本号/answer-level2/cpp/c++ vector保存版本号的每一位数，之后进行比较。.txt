### 解题思路
对版本号处理，用vector保存版本号的每一位数，之后对两个vector进行比较。
虽然写的比较繁琐，但是速度还挺快= =
![image.png](https://pic.leetcode-cn.com/d281efba245b0494c47ccc0be08cdca19bb20d863dcb38952dc5e9a9665d67d2-image.png)

另外我还有一种思路，直接把版本的每一位相减，特殊处理前缀0，一会我试试


### 代码

```cpp
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> ver1;
        vector<int> ver2;
        get_vec(version1,ver1);
        get_vec(version2,ver2);
        auto it1=ver1.begin();
        auto it2=ver2.begin();
        while(it1!=ver1.end()&&it2!=ver2.end())
        {
            if(*it1>*it2)
                return 1;
            else if(*it1<*it2)
                return -1;
            else
            {
                ++it1;
                ++it2;
            }
        }
        while(it1!=ver1.end())
        {
            if(*it1>0)
                return 1;
            ++it1;
        }
        while(it2!=ver2.end())
        {
            if(*it2>0)
                return -1;
            ++it2;
        }
        return 0;
    }
    void get_vec(string version, vector<int>& res){
        size_t p=0;
        size_t pre=0;
        while(p<version.size())
        {
            while(p<version.size()&&version[p]!='.')
                ++p;
            res.push_back(atoi(version.substr(pre,p-pre).c_str()));
            pre=p+1;
            ++p;
        }
    }
};
```