![微信图片_20200316191743.png](https://pic.leetcode-cn.com/f2a337e38e35d10cdb3a27a17394169554dcb220aa49b8bbecf809d7496994f2-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200316191743.png)


### 解题思路
原地更改，遇到空格，则逆转单词。
逆转单词：双指针记录，单词起始和终止位置，第一位跟末位调换，第二位跟倒数第二位调换。。。。以此类推。

### 代码

```cpp
class Solution {
public:
    void swap(char& a, char&b){  //用引用更快
        char temp;
        temp=a;
        a=b;
        b=temp;
    }
    string reverseWords(string s) {
        if(s=="")
            return s;
        
        int j=0;
        int z;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                z=i-1;
                while(j<=z)
                    swap(s[j++],s[z--]);
                j=i+1;
            }
        }
        z=s.length()-1;
        while(j<=z)
            swap(s[j++],s[z--]);
                
        return s;

    }
};
```