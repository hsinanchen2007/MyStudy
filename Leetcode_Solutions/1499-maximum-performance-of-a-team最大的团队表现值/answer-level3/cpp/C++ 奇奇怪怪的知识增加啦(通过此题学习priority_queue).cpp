### priority_queue基础介绍部分
#### 调用方式和参数介绍
&emsp;*template<
&emsp;&emsp; &emsp;class T,
&emsp;&emsp; &emsp;class Container = std::vector<T>
&emsp;&emsp; &emsp;class Compare = std::less<typename Container::value_type>
&emsp;\> class priority_queue;*
&emsp; 其中
- $T \rightarrow$ 代表的是存储数据的类型.
- $Container \rightarrow$ 指的是用于存储数据的容器（注意，该容器必须提供$push\_back()$, $pop\_back()$和$front()$操作，实际上也就是$std::vactor$和$std::deque$）
- $Compare \rightarrow$ 指比较类型，默认是std::less <>(优先级队列中的元素从大到小).

&emsp;**优先级队列是一个以对数级插入和取出为代价提供常数级最大最小值的查询的容器适配器。**
#### 解题思路：
- ①：将效率从大到小进行排序(之所以从大到小是因为，这样能保证在我们不断进行选取**基准**效率时，我们不需要对之前选择的效率做处理（因为都大于当前的效率基准）)
- ②：对于每个工程师👨‍🎓的效率值，我们计算在以他作为最小效率值情况下，最大的团队表现值
- ③：假如优先级队列里面的元素多余$k$，我们就弹出队首位置(因为更具我们设置的小根堆优先级队列，队首位置总$speed$是最小的，因此我们弹出它)
- ④：比较，注意，因为这里是需要比较我们不能在过程中取模，这会导致错误
$eg:$
&emsp;这里是排序的示意图，我们排序之后，我们**从左往右**选每个工程师的效率值作为基准(因为左边工程师的效率值都是大于他的)，维护一个优先级队列，计算这种情况下团队表现值。
![image.png](https://pic.leetcode-cn.com/9de4eb27367bd3525b8377668b4a7136f3f7203acad6794b2eea69d6da290860-image.png)

### 代码

```
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL MOD = 1e9 + 7;
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        LL ans(0), sum(0);
        vector<PLL> pr;
        priority_queue< int, vector<int>, greater<int> > pq;
        for (int i = 0; i < n; ++ i){
            pr.emplace_back(speed[i], efficiency[i]);
        }
        sort(pr.begin(), pr.end(), [](const PLL& p1, const PLL& p2) -> bool{
            return p1.second > p2.second; // 思路①排序
        });

        for (int i = 0; i < n; ++ i){ // 思路②③
            pq.push(pr[i].first);
            sum += pr[i].first;
            if (pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }
            ans = std::max(ans, sum * pr[i].second); // 思路④
        }

        return ans % MOD;
    }
};
```
水平有限，如有错误感谢指正！