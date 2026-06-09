### 解题思路
总体上，使用`C#5.0`（还是6.0）起的`async/await`语法编写，由于原始方法并不带`async`头（内部应该是用`Thread`阻塞的）所以可以在这里用一些很诡异的方法达成`async `，可以避免写一大堆让人头疼的`Task.Add`之类的语句。
另外通过大数据集debug发现接口里面肯定用的是`Thread.Sleep()`进行阻塞（而不是用`while(true)`之类的耗时方法，证据可以在`request`中查看当前执行的`ThreadId`不难看到每次都是一个ID，也就是接口内通过`Thread.Sleep()`阻塞后该线程可以去执行别的异步块。
关于线程安全，对于`Collections`类，使用线程安全的`Concurrent`系的子类，`HashTable`使用线程安全的同步`HashTable`，避免自己写各种锁去实现线程安全。

然后是关于业务逻辑，首先将`HtmlParser`保存到类内供全局调用，然后建立静态（编译）正则表达式匹配器`Regex`，先对`startUrl`做一次正则获取`host`的信息，然后将`host`保存到类内供全局调用。
主函数通过`running == 0 && queue.IsEmpty`判断是否已经执行完毕，即正在运行的`request()`数量为`0`且队列为空。当`running > 0`但队列为空时，使用`Thread.Sleep(1)`来阻塞线程，防止频繁在`while`内消耗处理器资源。
然后是代码的核心`request()`方法，使用`await Task.Delay(1)`来欺骗编译器达到真正`async`的运行（否则内部没有`await`的话会被编译器编译为同步方法，也就是每次运行都会被阻塞了），然后就是请求地址，并且检查`hashtable`内是否存在这个值，如果不存在则推入队列并加入返回值。

### 代码

```csharp
// 引入一堆要用到的而判题机没有自动引入的命名空间
using System.Threading;
using System.Collections.Concurrent;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
class Solution {
    Hashtable htSyn = Hashtable.Synchronized(new Hashtable());            // 线程安全的Hashtable
    ConcurrentBag<string> list = new ConcurrentBag<string>();             // 线程安全的List
    ConcurrentQueue<string> requestQueue = new ConcurrentQueue<string>(); // 线程安全的Queue
    HtmlParser html; // 全局接口
    int running = 0; // 正在运行的数量，按道理这个也要改为线程安全，但是记得好像int是原子操作，不需要加锁，望大家解答
    string hostUrl;  // 全局缓存的url
    Regex r;         // 全局的编译过的正则表达式
    string getHost(string url) { // 方法： 返回host地址
        return r.Match(url).Groups[2].Value;
    }

    bool parse(string url) { // 判断地址的host是否和全局储存的一致
        return getHost(url) == hostUrl;
    }

    async void request(string url) { // 核心方法
        running++;                   // 函数入点，先对running自增
        await Task.Delay(1);         // 欺骗编译器这是一个async方法
        var urls = html.GetUrls(url);// 请求url
        foreach (string u in urls) {
            if (htSyn[u] != null) {
                continue;            // 已经存在 放弃该url抓取
            }
            htSyn[u] = true;         // 否则加入hashtable
            if (parse(u)) {          // 然后判断是否和host一致，一致的话推入List和Queue
                list.Add(u);
                requestQueue.Enqueue(u);
            }
        }
        running--;                   // 出点，running自减
    }

    public IList<string> Crawl(string startUrl, HtmlParser htmlParser) {
        html = htmlParser; // 全局缓存
        string Pattern = @"^(http|https|ftp)\://([a-zA-Z0-9\-\.]+\.[a-zA-Z]{2,3})(:[a-zA-Z0-9]*)?/?(.*?)$"; // 对url的正则表达式匹配
        r = new Regex(Pattern);      // 编译正则表达式
        hostUrl = getHost(startUrl); // 全局缓存host

        list.Add(startUrl);    // 将startUrl推入答案
        htSyn[startUrl] = true;// 加入hashtable
        request(startUrl);     // 执行第一次请求
        while (running > 0 || !requestQueue.IsEmpty) { // 主循环
            if (requestQueue.IsEmpty) {
                Thread.Sleep(1); // 如果为空，阻塞休眠1ms，防止占用资源
                continue;
            }
            string front;
            if (requestQueue.TryDequeue(out front)) { // 尝试提取，线程安全的Queue只有TryDequeue
                request(front);  // 请求网址
            }
        }
        return list.ToList();    // 将线程安全的List转回普通的List
    }
}
```