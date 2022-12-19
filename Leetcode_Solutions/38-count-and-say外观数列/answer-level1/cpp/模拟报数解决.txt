### 模拟报数解决

```c
 string countAndSay(int n) {
    string ret = "1";
    string tmp;
    int cnt = 0;
    if (n == 1) return ret;

    
    for (int i = 1; i < n; ++i) {
        tmp.clear();
        char ch = ret[0];
        cnt = 1;
        for (int j = 1; j < ret.size(); ++j) {
            if (ret[j] == ch) {
                // 统计相同数字数量
                cnt++;
            }
            else {
                // 记录个数和数字
                tmp.append(to_string(cnt));
                tmp.append(&ch, 1);
                // 初始化状态,重新统计
                ch = ret[j];
                cnt = 1;
            }
        }
        // 记录最后一个统计
        tmp.append(to_string(cnt));
        tmp.append(&ch, 1);
        ret = tmp;
    }
    return ret;
}
```