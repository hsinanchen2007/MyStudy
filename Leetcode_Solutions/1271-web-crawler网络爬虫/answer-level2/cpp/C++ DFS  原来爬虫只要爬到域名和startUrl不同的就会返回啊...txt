花了好长时间排错,其实是自己对题目理解有误,只需要爬取到和startUrl不同域名的链接就会返回,不管这个链接里面是否有和startURL相同的链接.

```
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> ret;
        set<string> visit;
        ret.push_back(startUrl);
        visit.insert(startUrl);
        string host=startUrl.substr(0,startUrl.find('/',7));
        DFS(ret,visit,startUrl,htmlParser,host);
        return ret;
    }
    void DFS(vector<string> &ret,set<string> &visit,string startUrl,HtmlParser htmlParser,string host)
    {
        vector<string> url=htmlParser.getUrls(startUrl);
        for(int i=0;i<url.size();i++)
        {
            if(url[i].substr(0,host.size())!=host)  //这一句的位置挺重要的
                continue;
            if(visit.count(url[i]))
                continue;
            cout<<url[i].substr(0,host.size())<<endl;
            
            ret.push_back(url[i]);
            visit.insert(url[i]);
            DFS(ret, visit, url[i], htmlParser,host);
        }
    }
};
```
