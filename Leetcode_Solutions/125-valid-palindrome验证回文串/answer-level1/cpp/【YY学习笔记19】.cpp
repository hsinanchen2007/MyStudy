### 解题思路
定义了一个vector容器，用来储存处理过后的字符。（将非字符，数字删除，并将大写字母换成小写），然后比较。
### 代码

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        //回文字符串：正读和反读一样。
        //关键：对于非字母，数字符号的处理。
        if(s==" ") return true;
        vector<char> a;
        //剔除
        for(int i=0;i<s.length();i++){
            if((s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='z')){
                a.push_back(s[i]);
            }
            if(s[i]>='A'&&s[i]<='Z'){
                a.push_back(s[i]-'A'+'a');
            }
        }
        //比较
        for(int i=0;i<a.size()/2;i++){
            if(a[i]!=a[a.size()-1-i]){
                return false;
            }
        }
        return true;
    }
};
```