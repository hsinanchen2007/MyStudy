思路是双指针，直到两个指针都找到元音字母，互换。还要注意特例情况的判断
```
class Solution {
public:
    string reverseVowels(string s) {
        if (s.size() == 0)//特判1：字符串为空
            return "";       
        if (s.size() == 1) //特判2：字符串为一个字符，无论是否g为元音字母均直接返回
            return s;
        //长字符串
        string a = "aoeiuAOEIU"; //创建元音字符串
        int l = 0,r = s.size()-1; //双指针
        while(l < r)
        {
            if(a.find(s[l]) == -1)
            {
                l++;
                continue;
            }           
            if(a.find(s[r]) == -1)
            {
                r--;
                continue;
            }
             swap(s[l++],s[r--]);  
        }
        return s;
    }
};
```
![33333.png](https://pic.leetcode-cn.com/afc9c40aa3d382a21f18a6e303c8540c872ae8eceb85c0321c3bcdd3af21a0c4-33333.png)
新手上路，多多指教。加入特例的判断是会让运行时间缩短对吧？


