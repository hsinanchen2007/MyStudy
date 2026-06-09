如题，先预处理每个字符的最后出现位置，则在上个字符到最前的最后出现位置之间可以直接贪心
```
string smallestSubsequence(string text) {
    int post[26];
    string ans;
    memset(post, -1, sizeof post);
    for (int i = 0; i < text.size(); i++) {
        post[text[i]-'a'] = i; // 记录每个字符最后一次出现的位置
    }
    for (int st = 0, mi; ;) {
        mi = text.size();
        for (int i = 0; i < 26; i++) {
            if (~post[i]) mi = min(mi, post[i]); // 计算还未出现字符的最小下标
        }
        if (mi == text.size()) break;
        char tmp = 'z';
        for (int i = st; i <= mi; i++) { // 寻找上一个字符之后，字典序最小的字符
            if (~post[text[i]-'a'] && text[i] < tmp) {
                tmp = text[i];
                st = i+1;
            }
        }
        ans += tmp;
        post[tmp-'a'] = -1;
    }
    return ans;
}
```
再优化的话可以尝试使用一些数据结构代替取未出现字符下标最小值的这一步