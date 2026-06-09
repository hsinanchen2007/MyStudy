用静态计数器来实现吧，可以存2^64个短链
```
class Solution {
public:
    int count = 0;
    map<int, string> mmap;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mmap[count] = longUrl;
        return "http://" + to_string(count++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int key = stol(shortUrl.substr(7, shortUrl.length() - 7));
        return mmap[key];
    }
};
```