bfs题，HtmlParser可获取url点的邻接点，用set保存访问过的点，bfs时只访问域名和起点相同的点

```
class Solution {
     public List<String> crawl(String startUrl, HtmlParser htmlParser) {

        List<String> res=new ArrayList<>();
    bfs(startUrl,htmlParser,res,getHost(startUrl));
    return  res;

    }
    String  getHost(String url) //解析获取url的域名
    {
        int cnt=3,
            i = 0;
        for (; i <url.length()&&cnt>0 ; i++) {
            if (url.charAt(i)=='/')cnt--;
        }

         if (i==url.length())return url;
        return  url.substring(0,i-1);
    }

    void bfs(String startUrl,HtmlParser htmlParser,List<String> res,String host)
    {
        
        Queue<String> queue=new LinkedList<>();
        HashSet<String> set=new HashSet<>();
        set.add(startUrl);
        queue.offer(startUrl);
        while (!queue.isEmpty())
        {
            String temp=queue.poll();
           
            res.add(temp); 
            List<String> urlList=htmlParser.getUrls(temp);//获取temp邻接点
            for (String url:urlList)
            {   
                if (set.contains(url))continue;//该点访问过了
                set.add(url);
                String tempHost=getHost(url); 
                if (tempHost.equals(host)){

                    queue.offer(url);
                }
            }
        }



    }

}
```
