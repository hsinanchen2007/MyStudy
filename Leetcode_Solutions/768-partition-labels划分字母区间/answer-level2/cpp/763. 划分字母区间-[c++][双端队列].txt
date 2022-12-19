```c++
vector<int> partitionLabels(string s) {
    std::deque<int> dq;
    int index[26];
    memset(index, -1, 26*sizeof(int));
    for (int i = 0; i < s.length(); ++i) {
        while (index[s[i]-'a'] != -1 && !dq.empty() && dq.back() >= index[s[i]-'a']) {
            dq.pop_back();
        }
        dq.push_back(i);
        index[s[i]-'a'] = i;          
    }
    vector<int> res;
    int last = 0;
    for (auto idx : dq) {
        res.push_back(idx - last + 1);
        last = idx + 1;
    }
    return res;
}
```
