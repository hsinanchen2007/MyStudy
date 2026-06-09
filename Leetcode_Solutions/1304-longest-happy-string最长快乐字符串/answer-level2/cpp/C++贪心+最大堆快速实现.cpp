### 思路：

采用贪心思想，每次找到当前剩余个数最多（以下简称最大字符）的字母`max{a, b, c}` 进行字符串追加操作，且每次尽可能多地插入字符（这样可以优化插入的速度）。如果连续两轮都是同一个字符，则第二轮选取次大的字符。值得注意的是，应该尽量避免连续两次找到的`max{a, b, c}`都是同一个字符，所以若最大字符选取完`2`个之后，若`max{a, b, c}`仍为当前最大字符，则选取`1`个次大元素追加至字符串当中。循环的终点为无法找到下一个剩余个数大于`0`的字符，那么函数退出。

### 代码实现：
```
class Solution {
    struct Info{
        char c;
        int vol;
    };
    struct cmp{
        bool operator()(Info a, Info b){
            return a.vol < b.vol;
        }
    };
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<Info, vector<Info>, cmp> pq;
        pq.push({'a', a}), pq.push({'b', b}), pq.push({'c', c});
        Info last = {'#', -1};
        string s;
        while(true){
            cout << "here" << endl;
            Info max = pq.top();
            pq.pop();
            cout << s << ' ' << max.vol << endl;
            if(max.vol <= 0) break;
            if(last.c != max.c){
                s += max.c;
                max.vol--;
                if(max.vol > 0){
                    s += max.c;
                    max.vol--;
                }
                last = max;
                pq.push(max);
            }
            else{
                Info max2 = pq.top();
                pq.pop();
                pq.push(max);
                if(max2.vol > 0){
                    s += max2.c;
                    max2.vol--;
                    last = max2;
                    pq.push(max2);
                }
                else break;
            }
        }
        return s;
    }
};
```
### 总结：
基于贪心思想，用堆来实现最大字符和次大字符的选取，时间复杂度O(a+b+c).