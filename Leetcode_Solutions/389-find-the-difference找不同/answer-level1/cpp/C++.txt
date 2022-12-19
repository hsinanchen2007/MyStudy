![360截图20200402164141065.jpg](https://pic.leetcode-cn.com/2fd4832c9d71e24f0facbba4ddfb6c6aab24c21ab0fe3d2212e262b4f9c02188-360%E6%88%AA%E5%9B%BE20200402164141065.jpg)

class Solution {
public:
    char findTheDifference(string s, string t) {
        int s1 = s.size();
        int t1 = t.size();
        if((s1 +1) != t1) return NULL;
        vector<int> temp(26,0);
        for(int i = 0;i<s1;i++) {temp[s[i]-'a']++;}
        for(int i = 0;i<t1;i++) {temp[t[i]-'a']--;}
        for(int i = 0;i<26;i++) 
        {if(temp[i] != 0) return i+'a';
        }
        return NULL;

    }
};