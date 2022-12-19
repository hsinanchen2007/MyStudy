![image.png](https://pic.leetcode-cn.com/9af86b9d6bb1baaf4e506b59dfad5dd71fb58664fbf53ac775af98f6b8fcf842-image.png)

### 解题思路
用栈实现DFS

### 代码

```cpp
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
    string gethostname(string url)
    {
        size_t len = url.size(), idx = 7;
        while(idx < len && url[idx] != '/')
            ++idx;
        return url.substr(0, idx);
    }
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        set<string> rslt;        
        rslt.insert(startUrl);
        stack<string> urls;
        urls.push(startUrl);
        vector<string> temp;
        string hostname = gethostname(startUrl);
        while(!urls.empty())
        {
            temp = htmlParser.getUrls(urls.top());
            urls.pop();
            for(string url : temp)
            {
                if(rslt.find(url) == rslt.end() && hostname == gethostname(url))
                {
                    urls.push(url);
                    rslt.insert(url);
                }
                
            }
        }
        vector<string> fina_rslt;
        for(string url : rslt)
            fina_rslt.push_back(url);
        return fina_rslt;
    }
};
```