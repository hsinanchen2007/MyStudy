```
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
        from collections import deque
        
        hostname = startUrl.split('//')[1]
        hostname = hostname.split('/')[0]
        
        have_crawled = set()
        need_crawl = deque([startUrl])
        
        while need_crawl:
            cur_url = need_crawl.popleft()
            urls_inpage = htmlParser.getUrls(cur_url)
            have_crawled.add(cur_url)
            
            for url in urls_inpage:
                if hostname in url and url not in have_crawled:
                    need_crawl.append(url)
                    
        return list(have_crawled)
```
