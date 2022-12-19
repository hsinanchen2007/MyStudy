这个算法很经典，但每个人的实现就有差异了，我的大致思路是：
（1）在插入前两个元素时，需要进行相关判断，插入结束后，此时两个堆均非空；
（2）两堆均非空，依据待插元素与两个堆顶元素的大小关系，分三种情况：
     1）  如果待插元素大于最小堆（大元素）堆顶元素，则插入此堆；
     2）  如果待插元素小于最大堆（小元素）堆顶元素，则插入此堆；
     3）  如果待插元素介于大小堆堆顶元素之间，则插入size较小的那个（相等时随便喽）；
（3）最后进行平衡：
     1）当最大堆size比最小堆大2，则从最大堆弹出一个插入最小堆；
     2）当最小堆size比最大堆大2，则从最小堆弹出一个插入最大堆；
性能分析：
    时间复杂度:采用这种算法的复杂度基本上都是O(logn)的，但常数因子可能有几倍的差别。以上步骤中（1）步骤为 3,(2)步骤最坏的情况——例如num小于最大堆堆顶元素，同时最大堆size本就比最小堆大1，此时num插入到最大堆中，在平衡阶段要调整一步，所以一共有两次插入，一次弹出，所以是最坏3*log(n/2)；而平均复杂度为大概为1.7*log(n/2).总的来看，常数因子还算是比较小的。
    空间复杂度：采用这种算法的一搬都是线性级的

代码实现：选择结构比较多，因该还有优化的余地，希望大家交流共进！
```
    void addNum(int num) {
        if(max_heap.empty()&&min_heap.empty()){
            min_heap.push(num);
            return;
        }
        if(!min_heap.empty()&&max_heap.empty()){
            if(num>min_heap.top()){
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(num);
                return;
            }
            else{
                max_heap.push(num);
                return;
            }
        }

        if(num>min_heap.top()){
            min_heap.push(num);
        }
        else if(num<max_heap.top()){
            max_heap.push(num);
        }
        else{
            if(min_heap.size()>max_heap.size()){
                max_heap.push(num);
            }
            else{
                min_heap.push(num);
            }
        }
        if(min_heap.size()-max_heap.size()==2){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        if(max_heap.size()-min_heap.size()==2){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        return;
    }
```
某次提交的结果运行结果：时间和空间复杂度排名都在50%-70%之间。官方版代码十分简洁，构思比较巧妙，但似乎比较慢，一次提交测试中似乎排名在15%左右。


