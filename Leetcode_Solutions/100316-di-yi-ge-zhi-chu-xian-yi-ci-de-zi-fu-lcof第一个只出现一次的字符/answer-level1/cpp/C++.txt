![360截图20200406135752985.jpg](https://pic.leetcode-cn.com/353c30994537107960c3a0b095b31710e16c72a1893d263bdc8331f28ee95e40-360%E6%88%AA%E5%9B%BE20200406135752985.jpg)



class Solution {
public:
    char firstUniqChar(string s) {
        int n = s.length();
        char res = ' ';
        int a[26]={0};
        for(int i = 0;i<n;i++) a[s[i]-'a']++;
        for(int i = 0;i<n;i++) {
            if(a[s[i]-'a'] == 1)  {
                res = s[i];
                break;
            }
        }
        return res;

    }
};