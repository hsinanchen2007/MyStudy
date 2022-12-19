**利用字符流 sstream 可以方便地解决掉空格问题**
```
string reverseWords(string s) {
    string ans, str;
    stringstream ss(s);
    while (ss >> str) ans.insert(0, str + " ");
    return ans.size() ? string(ans.begin(), ans.end() - 1) : "";
}
```

**不过上述方法耗时会达到50ms+，比较高，主要原因是每次都需要调用insert函数进行“逆序存储“”**
**下面改用“顺序存储逆序输出”，耗时可以降到4~10+ms**
```
string reverseWords(string s) {
    string ans, str;
    vector<string> tmp;
    stringstream ss(s);
    while (ss >> str) tmp.push_back(str);
    for (int i = tmp.size() - 1; i >= 0; i--) ans += tmp[i] + " ";
    return ans.size() ? string(ans.begin(), ans.end() - 1) : "";
}
```

**下面介绍原地算法，额外空间 O(1)**
**大体思路是，先整体反转，再逐单词反转；需要处理首尾、中间的冗余空格**
```
string reverseWords(string s) {
    reverse(s.begin(), s.end());                        //整体反转
    int start = 0, end = s.size() - 1;
    while (start < s.size() && s[start] == ' ') start++;//首空格
    while (end >= 0 && s[end] == ' ') end--;            //尾空格
    if (start > end) return "";                         //特殊情况

    for (int r = start; r <= end;) {                    //逐单词反转
        while (s[r] == ' '&& r <= end) r++;
        int l = r;
        while (s[l] != ' '&&l <= end) l++;
        reverse(s.begin() + r, s.begin() + l);
        r = l;
    }

    int tail = start;                                   //处理中间冗余空格
    for (int i = start; i <= end; i++) {
        if (s[i] == ' '&&s[i - 1] == ' ') continue;
        s[tail++] = s[i];
    }
    return s.substr(start, tail - start);
}
```
