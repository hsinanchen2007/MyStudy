### 解题思路
思路很好想，先建立一个提取url域名的方法，然后建立一个list,如果url一样的话，就加到list中，然后用递归实现。

### 代码

```java
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface HtmlParser {
 *     public List<String> getUrls(String url) {}
 * }
 */
class Solution {
    public List<String> crawl(String startUrl, HtmlParser htmlParser) {

        ArrayList<String> ans = new ArrayList<>();
        helper(startUrl, htmlParser, ans);
        return ans;
    }

    public void helper(String startUrl, HtmlParser htmlParser, List<String> ans){
        if(!ans.contains(startUrl)){
            ans.add(startUrl);

            List<String> urlList=htmlParser.getUrls(startUrl);//获取temp邻接点
            String host_name = getHost(startUrl);
            
            for( String element: urlList){
                if(getHost(element).equals(host_name)){
                    helper(element, htmlParser, ans);
                }
            }
        }
    }

    String getHost(String url){ //解析获取url的域名 
        int cnt=3, i = 0;
        for (; i <url.length()&&cnt>0 ; i++) {
            if (url.charAt(i)=='/')cnt--;
        }

        if (i==url.length())return url;
        return  url.substring(0,i-1);
    }
}
```