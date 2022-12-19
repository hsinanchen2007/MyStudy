```cpp
class Solution {
public:
    string deal(string& s)
    {
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'A' || s[0] == 'E' || s[0] == 'I' || s[0] == 'O' || s[0] == 'U'){
            s += "ma";
        }
        else{
            s += s[0];
            s += "ma";
            s.erase(s.begin());
        }
        return s;
    }

    string toGoatLatin(string s) 
    {
        string ret;
        int len = s.size(), i = 0, j = 0, cnt = 0;
        while(j < len){
            i = j;
            cnt++;
            while(s[j+1] != ' ' && s[j+1] != '\0'){
                j++;
            }
            string tmp = s.substr(i, j - i + 1);
            tmp = deal(tmp);
            for(int k = 0; k < cnt; k++){    //末尾添加'a'
                tmp += "a";
            }
            ret += tmp;
            ret += " ";
            if(s[j+1] == '\0')
                break;
            j += 2;
        }
        ret.erase(ret.end() - 1);   //去掉最后的“ ”
        return ret;
    }
};
```