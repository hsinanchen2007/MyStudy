BFS 遍历，通过set来判断是否访问过url，双端队列按照获取的顺序进行访问

需要注意不相同域名的url无需在去getUrls访问，但是我看题意没看出这个意思，提交报错后才发现这个问题。

```cpp
class Solution {
public:
    string getHostname(string& url) {
        int pos = url.find('/', 7);
        if (pos == string::npos) {
            return url.substr(7);
        }
        return url.substr(7, pos - 7);
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        set<string> visited;
        deque<string> q;
        q.push_back(startUrl);
        vector<string> res;
        string hostname = getHostname(startUrl);

        while (!q.empty()) {
            string url = q.front();
            q.pop_front();
            if (visited.find(url) != visited.end()) {
                continue;
            }
            visited.insert(url);
            if (getHostname(url) != hostname) {
                continue;
            }
            res.push_back(url);
            vector<string> urls = htmlParser.getUrls(url);
            for (string& s : urls) {
                q.push_back(s);
            }
        }
        return res;
    }
};
```
