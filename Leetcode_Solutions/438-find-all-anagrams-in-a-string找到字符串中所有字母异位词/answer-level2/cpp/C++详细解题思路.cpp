### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size()<p.size()) return {};
        vector<int>res;
        int l=0,r=0;
        int s_count[26]={0};
        int p_count[26]={0};
        for(int i=0;i<p.size();i++){//先把p中的字母存入数组
            p_count[p[i]-'a']++;
        }

        while(l<=s.size()-p.size()){
            if(r-l+1<p.size()){    //长度不够时右边界继续右移
                s_count[s[r++]-'a']++;
                continue;
            }
            if(r-l+1==p.size())    //长度相等时，记录下右边界的字母，并进行判断
                s_count[s[r++]-'a']++;//此处r若不++，后续计数会把r处字母又加一遍
            int i;
            for(i=0;i<26;i++){
                if(s_count[i]!=p_count[i]) break;//判断是否是字母异位词
            }
            if(i==26)//字母全部包含时将下标存入
                res.push_back(l);
            s_count[s[l++]-'a']--;//窗口右移(不论是否存入了，只要到了这里都右移)
        }
        return res;
    }
};
```