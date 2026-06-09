这道题用c++写需要注意的几个坑：

1.线程函数的参数一定要传引用，即使像htmlParser、host_name也要传引用，(这里我始终没明白为什么host_name传值不行？！)
2.线程不能死循环，因为线程在detach分离后，如果进程不退出，线程就不会退出被运行库回收资源，最后随着测试用例的增多内存溢出，导致测试用例通不过；但是python除外（可能解释器会自动回收）。
3.并不是创建的生产者线程越多越好，线程的调度也需要资源和时间。
4.应该先过滤掉和startUrl主机不相等的url，然后再爬虫，而不能先把所有的网页都爬到，再过滤掉主机不相等的，因为测试用例里有主机不相等的网页指向主机相等的网页。

下面两种解法：1.类成员函数作为线程；2.匿名函数作为线程。

方法1.类成员函数作为线程函数
```
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
private:
    std::mutex mu;
    std::condition_variable cv_req,cv_res;
    int requestCounter=0;
    int exited_flag=0;
public:
    void threadFunc(HtmlParser& htmlParser,string& host_name,queue<string>& requestQueue,queue<string>& resultQueue) {
        while(true){
            unique_lock<mutex> lk(mu);
            while(requestQueue.empty()&&exited_flag==0) 
                cv_req.wait(lk);
            if(exited_flag) return ;
            string url=requestQueue.front();
            requestQueue.pop();
            lk.unlock();
            vector<string> urls=htmlParser.getUrls(url);
            for(auto gurl:urls){
                int pos=gurl.find('/',7);
                string host=gurl.substr(7,pos-7);
                if(host_name==host){
                    lk.lock();
                    resultQueue.push(gurl);
                    lk.unlock();
                }
            }
            lk.lock();
            this->requestCounter--;
            lk.unlock();
            cv_res.notify_one();
        }
    }
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        queue<string> requestQueue;
        requestQueue.push(startUrl);
        queue<string> resultQueue;
        set<string> urlset;
        urlset.insert(startUrl);
        auto pos=startUrl.find('/',7);
        string hostname=startUrl.substr(7,pos-7);
        this->requestCounter=1;
        for(int i=1;i<=3;i++){
            std::thread th(&Solution::threadFunc,this,std::ref(htmlParser),std::ref(hostname),std::ref(requestQueue),std::ref(resultQueue));
            th.detach();
        }
        while(true){
            unique_lock<mutex> lk(mu);
            while(resultQueue.empty()&&this->requestCounter!=0){
                cv_res.wait(lk);
            }
            while(!resultQueue.empty()){
                string url=resultQueue.front();
                resultQueue.pop();
                if(urlset.find(url)!=urlset.end()) continue;
                requestQueue.push(url);
                urlset.insert(url);
                requestCounter++;
            }
            cv_req.notify_all();
            if(requestCounter==0) {
                exited_flag=1;
                break;
            } 
        }
        vector<string> res;
        for(auto resurl:urlset){
            res.push_back(resurl);
        }
        return res;
    }
};
```
方法2.匿名函数作为线程函数
```
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        std::mutex mu;
        std::condition_variable cv_req,cv_res;
        int requestCounter=0;
        int exited_flag=0;
        queue<string> requestQueue;
        requestQueue.push(startUrl);
        queue<string> resultQueue;
        set<string> urlset;
        urlset.insert(startUrl);
        auto pos=startUrl.find('/',7);
        string hostname=startUrl.substr(7,pos-7);
        requestCounter=1;
        for(int i=1;i<=5;i++){
            std::thread th([&]{
                 while(true){
                    unique_lock<mutex> lk(mu);
                    while(requestQueue.empty()&&exited_flag==0) 
                        cv_req.wait(lk);
                    if(exited_flag) return ;
                    string url=requestQueue.front();
                    requestQueue.pop();
                    lk.unlock();
                    vector<string> urls=htmlParser.getUrls(url);
                    for(auto gurl:urls){
                        int pos=gurl.find('/',7);
                        string host=gurl.substr(7,pos-7);
                        if(hostname==host){
                            lk.lock();
                            resultQueue.push(gurl);
                            lk.unlock();
                        }
                    }
                lk.lock();
                requestCounter--;
                lk.unlock();
                cv_res.notify_one();
                }
            });
            th.detach();
        }
        while(true){
            unique_lock<mutex> lk(mu);
            while(resultQueue.empty()&&requestCounter!=0){
                cv_res.wait(lk);
            }
            while(!resultQueue.empty()){
                string url=resultQueue.front();
                resultQueue.pop();
                if(urlset.find(url)!=urlset.end()) continue;
                requestQueue.push(url);
                urlset.insert(url);
                requestCounter++;
            }
            cv_req.notify_all();
            if(requestCounter==0) {
                exited_flag=1;
                break;
            } 
        }
        vector<string> res;
        for(auto resurl:urlset){
            res.push_back(resurl);
        }
        return res;
    }
};
```

