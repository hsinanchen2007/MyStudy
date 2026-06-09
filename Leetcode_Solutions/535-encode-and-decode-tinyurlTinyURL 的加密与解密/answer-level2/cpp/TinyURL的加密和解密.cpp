### 解题思路
运用hash表存储长URL码对应key——count，并将其加网址开头作为短URL输出，读取短URL时，将网址开头删去作为key输入哈希表寻找长URL。注意题目中的给出的短码形式并不是唯一的，只要有自己能给出的短码可以输出并读取即可。

### 代码

```cpp
class Solution {
public:
    int count=0;
    map<int,string> mmap;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        mmap[count]=longUrl;
        return ("http://"+to_string(count++));
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        int key=stoi(shortUrl.substr(7,shortUrl.length()-7));
        return mmap[key];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```