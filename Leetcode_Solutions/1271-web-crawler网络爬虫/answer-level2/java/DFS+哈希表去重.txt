```java
class Solution {
    private List<String> res = new ArrayList<>();
    private Set<String> set = new HashSet<>();
    public List<String> crawl(String startUrl, HtmlParser htmlParser) {
        String domain = startUrl.split("/")[2];
        dfs(domain, htmlParser, startUrl);
        return res;
    }
    private void dfs(String domain, HtmlParser htmlParser, String url) {
        set.add(url);
        res.add(url);
        for(String s : htmlParser.getUrls(url)){
            if(domain.equals(s.split("/")[2]) && !set.contains(s))
                dfs(domain, htmlParser, s);
        }
    }
}
```