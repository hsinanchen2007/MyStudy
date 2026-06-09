### 执行时间
![图片.png](https://pic.leetcode-cn.com/73aaaa14a9916c4e551bd76befb875a422a6b7cb1da0c0ec1e9785814540e7d1-%E5%9B%BE%E7%89%87.png)

### 思路
1. 因为单词的长度 `len` 是固定的，所以可以将一个单词看成一个单元
2. 对单词使用滑动窗口，单元间的步长就是 `len` 
3. 在 0 - `len` 的范围内，每一个都作为滑动窗口的起点，滑动 `len` 次，即可覆盖所有字符串的各种组合

### 图解
```
输入：s = "foobarxbarfoo", words = ["foo","bar"]
输出：[0,7]
```
![图片.png](https://pic.leetcode-cn.com/5b021b185f307de621ed7d72f638595cdcf692581600336d85d03f20c8aadb83-%E5%9B%BE%E7%89%87.png)

### 答题
```C++ []
vector<int> findSubstring(string s, vector<string>& words) 
{
    if (words.size() == 0) return {};
    unordered_map<string, int> wordcnt;
    for (auto& w : words)
    {
        wordcnt[w]++;
    }
    int len = words[0].size();

    vector<int> ans;
    for (int i = 0; i < len; i++)
    {
        int left = i;
        int right = left;
        int cnt = 0;

        unordered_map<string, int> window;
        while (left + words.size() * len <= s.size())
        {
            string temp = "";
            while (cnt < words.size())
            {
                temp = s.substr(right, len);
                if (wordcnt.find(temp) == wordcnt.end() || window[temp] >= wordcnt[temp]) break;
                window[temp]++;
                cnt++;
                right += len;
            }

            if (window == wordcnt)
            {
                ans.push_back(left);
            }

            if (wordcnt.find(temp) != wordcnt.end())
            {
                window[s.substr(left, len)]--;
                cnt--;
                left += len;
            }
            else
            {
                right += len;
                left = right;
                cnt = 0;
                window.clear();
            }
        }
    }
    return ans;
}
```



### 致谢

感谢您的观看，希望对您有帮助，欢迎热烈的交流！  

[我的leetcode](https://github.com/AhJo53589/leetcode-cn)

