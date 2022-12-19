![image.png](https://pic.leetcode-cn.com/a47ff146a52d40c20953de256ba4a6f6e09eab6dabf2b4dbed7f01161461918e-image.png)


```
from typing import List
class Solution:

    def solve(self, cur_url, parser, domian, all_url, ans):
        if cur_url.find(domian) != -1:
            ans.add(cur_url)
        all_url.add(cur_url)

        next = parser.getUrls(cur_url)
        for new_url in next:
            if new_url in all_url:
                continue

            if new_url.find(domian) == -1:
                continue

            self.solve(new_url, parser, domian ,all_url, ans)

    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        idx = startUrl.find('/', 7)
        domain = startUrl if idx == -1 else startUrl[:idx]

        all_url = set()
        ans = set()
        self.solve(startUrl, htmlParser, domain, all_url, ans)
        return sorted(list(ans))
```
