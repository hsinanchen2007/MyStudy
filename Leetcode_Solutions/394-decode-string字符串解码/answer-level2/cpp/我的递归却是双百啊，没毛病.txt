### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string decodeString(string& s) {
        int k = s.find('[');//查找第一个'['
        if (k < 0) return s;

        string temp("[");
        int start=0; int end=0;
        for (int i=k; i<s.size(); i++)
        {
            if (s[i] == '[') {temp.clear(); k=i;}
            temp += s[i];
            if (s[i] == ']') {end=i; temp += s[i]; break;}
        }
        for (int j=k-1; j>=0; j--) 
            if (s[j] >= '0' && s[j] <= '9') temp = s[j] + temp;
            else {start=j+1; break;}
        int num = atoi(temp.substr(0,temp.find('[')).c_str());
        string temp1("");
        for(int i=0; i<num; i++) 
            temp1 += temp.substr(temp.find('[')+1,temp.size()-temp.find('[')-3);

        s = s.substr(0,start) + temp1 + s.substr(end+1);
        decodeString(s);
        return s;
    }
};
```