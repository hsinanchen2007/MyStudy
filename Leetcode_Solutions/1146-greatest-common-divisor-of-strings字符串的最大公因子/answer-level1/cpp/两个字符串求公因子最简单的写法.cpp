### 解题思路
此处撰写解题思路
1.从两个子串中选择出最小的一个
2.按照最小的子串长度进行循环判断，不断记录满足两个子串相同的子串
3.如果两个字符串都能将记录的子串完全除尽，则该子串就是两个子串的公因子
### 代码

```cpp
class Solution {
public:
    string replaceString(string str, const string &subStr)
    {
        int pos = str.find(subStr);
        string strTemp = "";
        while(pos != -1)
        {
            strTemp = str.replace(pos, subStr.length(), "");
            pos = strTemp.find(subStr);
        }
        return strTemp;
    };
    string gcdOfStrings(string str1, string str2) {  
            string minStr, str = ""; 
            if (str1.length() < str2.length())
            {
                minStr = str1;
            }
            else
            {
                minStr = str2;
            }
            string subStr = "";
            int i = 0;
            while(i < minStr.length())
            {
                if (str1[i] == str2[i])
                {
                    subStr.push_back(str1[i]);
                    string temp1 = str1;
                    string temp2 = str2;
                    if (replaceString(str1, subStr) == "" && replaceString(str2, subStr) == "")
                        str = subStr;
                }
                i++;
            }
            return str;
    }
};
```