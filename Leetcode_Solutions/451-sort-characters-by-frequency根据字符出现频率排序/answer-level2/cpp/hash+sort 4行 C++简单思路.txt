思路一句话：统计出现频次入Hash，根据频次和字母序Sort，效率一般，胜在直白
![image.png](https://pic.leetcode-cn.com/c1c0eee94223eca1103d9f9fc2d23d3f8e62184d176a962abad099115a115227-image.png)

```
string frequencySort(string s) {
    unordered_map<char, int> charMap;
    for (const auto ch : s) { charMap[ch]++; }
    sort(s.begin(), s.end(), [&](const char ch1, const char ch2){ return charMap[ch1] == charMap[ch2] ?  ch1 > ch2 : charMap[ch1] > charMap[ch2]; });
    return s;
}
```
