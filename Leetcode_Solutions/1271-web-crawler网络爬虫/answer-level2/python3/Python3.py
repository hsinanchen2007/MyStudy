![be08f9c861ed4b3a4df5bfeaff2957b.png](https://pic.leetcode-cn.com/e15c6ded365d96344754223e942522017b4cc68ad2ef182165cb1e8bc56efbda-be08f9c861ed4b3a4df5bfeaff2957b.png)
```python []
# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        rec_set = {startUrl}
        rec_list = [startUrl]
        host_name = 'http://' + startUrl.split('/')[2]
        
        for url in rec_list:
            a = htmlParser.getUrls(url)
            for i in a:
                if i.startswith(host_name) and i not in rec_list:
                    rec_set.add(i)
                    rec_list.append(i)
        return rec_list
```
