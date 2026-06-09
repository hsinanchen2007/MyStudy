### 解题思路
使用string庫裏面的find_last_not_of（）和erase函數來消除末尾空格，之後數出最後幾個單詞的數目就可以了
### 代码

```cpp
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int count=0;
        s.erase(s.find_last_not_of(" ")+1);//消除之後所有空格
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]==' ') break;
            count++;
        }
        return count;
    }
};
//去除首位空格的方法
/*string& trim(string &s) 
{
    if (s.empty()) 
    {
        return s;
    }
    s.erase(0,s.find_first_not_of(" "));
    s.erase(s.find_last_not_of(" ") + 1);
    return s;
}*/
```