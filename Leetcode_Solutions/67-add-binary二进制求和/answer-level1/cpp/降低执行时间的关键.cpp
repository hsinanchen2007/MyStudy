无论你的算法是用逻辑与，按位与，还是异或
无论你的进位是除2，还是右移
无论你的算法是简单地if else，还是三目运算

都要：
1. 提前分配好最终字符串的内存大小
2. 直接push到string中
3. 最后用reverse函数逆转结果

代码中表现如下：
    string addBinary(string a, string b) {
        string s = "";
        s.reserve(a.size() + b.size());
        ……
        while (……)
        {
            ……
            s.push_back(……);
            ……
        }
        reverse(s.begin(), s.end());
        return s;
    }


原因：
字符串的+运算，每次都会重新分配内存，大量消耗内存