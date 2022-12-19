
先对原文进行处理，用标准库函数isalnum筛选出字母与数字，再用isupper筛选出大写的，用tolower转为小写
然后再一前一后两个索引对元素两两遍历，得出结果
时间复杂度为O(n)，空间复杂度，由于多了一个str拷贝，应该是O(n)


```
class Solution {
public:
    bool isPalindrome(string s) {
        string str = processStr(s);
        //一前一后双索引遍历
        for (int i = 0,r = str.size() - 1; i < r; i++, r--)
	        if (str[i] != str[r]) return false;
        return true;
    }
private:
    //工具函数，将字符串的标点空格去掉，大写变小写
    string processStr(string s){
        string str;
        for (char c : s) 
            if (isalnum(c)) {
                if (isupper(c)) c = tolower(c);
                str.push_back(c);
            }
        return str;
    }
};
```
