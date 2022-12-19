### 解题思路
按数组下标简化

### 代码

```cpp
class Solution {
private:
    vector<string> data;
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        data.push_back(longUrl);
        return "http://tinyurl.com/"+to_string(data.size()-1);
    }
    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl=shortUrl.replace(0,18,"");
        return data[atoi(shortUrl.c_str())];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```