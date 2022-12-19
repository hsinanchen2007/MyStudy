
这道题目是test case 有问题还是写的代码有问题。 为啥不给一下开启的线程数量。 MAX_ALIVE_THREAD_NUM 这个量定小了就会超时，多了就会超出内存限制。


我给的做法是用 CountDownLatch。 起某一数量的线程，把耗时的操作htmlParser.getUrls() 放到一个独立的线程中去进行操作。


这里需要维护一个 线程安全的 queue （也可以去限制queue的大小，e.g boundedblockingqueue） 来去保存需要 CrawlWorker 去 crawl 的request url .

因为这里queue和set 都会有多个线程同时读写。所以 要用线程安全的  queue 和set。ConcurrentLinkedQueue 已经保证了多个线程同时读/写访问的安全性了。 


每个阶段开的线程数量取决于queue的size和 MAX_ALIVE_THREAD_NUM 中的最小值。 

这道题目的本质就是找到独立互不影响的操作， 开启一个线程去执行。对于这道题目就是对每一个url 爬虫都是一个独立request。 然后从爬出的url选出同一个host以及没出现在结果集的作为新的request放到 queue中。 

还有一个比较好的练习可以写一下， Merge k sorted list Multithreaded ，关键也是找到线程独立的操作。 




```java
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface HtmlParser {
 *     public List<String> getUrls(String url) {}
 * }
 */
class Solution {


    class CrawlWorker implements Runnable {

        private String startUrl;

        private CountDownLatch countDownLatch;

        private HtmlParser htmlParser;

        CrawlWorker(String startUrl, CountDownLatch countDownLatch,HtmlParser htmlParser){
            this.startUrl = startUrl;
            this.countDownLatch = countDownLatch;
            this.htmlParser = htmlParser;
        }

        @Override
        public void run() {
            parse();
        }
        
        private void parse(){
            urlSet.add(startUrl);
            List<String> urlList = htmlParser.getUrls(startUrl);
            for(String url : urlList){
                if(urlSet.contains(url) || !getHost(url).equals(hostName)) continue;
                queue.offer(url);
            }
            
            this.countDownLatch.countDown();
        }
    }

    private final Set<String> urlSet = ConcurrentHashMap.newKeySet();
    private final Queue<String> queue = new ConcurrentLinkedQueue<>();

    private String hostName;
    private static final Integer MAX_ALIVE_THREAD_NUM = 128;



    public List<String> crawl(String startUrl, HtmlParser htmlParser) {

        hostName = getHost(startUrl);

        queue.offer(startUrl);
        while(!queue.isEmpty()){
            
            int curThreadNum = Math.min(MAX_ALIVE_THREAD_NUM, queue.size());

            CountDownLatch countDownLatch = new CountDownLatch(curThreadNum); 

            for(int idx = 0; idx < curThreadNum ;idx++){
                String curUrl = queue.poll();
                CrawlWorker crawlWorker  = new CrawlWorker(curUrl,countDownLatch, htmlParser);
                Thread thread = new Thread(crawlWorker);
                thread.start();
            }

            try {
                countDownLatch.await();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        return new ArrayList<>(urlSet);
    }


    private static String getHost(String url){
        String host = url.substring(7); // all urls use http protocol
        int idx = host.indexOf('/'); 
        if(idx == -1) return host;
        return host.substring(0,idx);
    }
}
```
