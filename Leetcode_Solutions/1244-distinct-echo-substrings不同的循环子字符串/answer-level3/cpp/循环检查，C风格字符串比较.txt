改了几稿将将满足时间要求：

执行结果：通过
显示详情 执行用时 :2292 ms, 在所有 C++ 提交中击败了7.33%的用户
内存消耗 :474.2 MB, 在所有 C++ 提交中击败了100.00%的用户

class Solution {
private:
    
    const char* textStr; //原串指针，准备自己写c风格程序比较，这样快一些

    int start;      //当前子串起点
    int strLen;     //当前子串长度

    bool StrEqual()
    {
        for (int i = start; i < (start + strLen); i++) {
            if (textStr[i] != textStr[i + strLen]) {
                return false;
            }
        }
        return true;
    }

public:
    int distinctEchoSubstrings(string text)
    {
        unordered_map<string, int> strMap;  //key是子串，value是找到子串的次数
        int textLen = text.size();
        textStr = text.c_str();
        start = 0;

        while (start < (textLen - 1)) {
            strLen = 1;
            while ((start + strLen + strLen) <= textLen) {
                if (StrEqual()) {
                    string str = text.substr(start, strLen);
                    strMap[str]++;
                }
                strLen++;
            }
            start++;
        }
        return strMap.size();
    }
};