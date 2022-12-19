看别人的代码非常复杂，我觉得可以改进一下，就使用双端队列解决了

先用一个vector<int> 按照下标记录字母出现的次数，扫一遍n复杂度

然后建立队列a，如果a为空，放入i，同时也要计数这个字母还剩多少。

具体逻辑看代码好了，应该也有改进的空间。

大致想法是一直读入字母写入队列（不重复），如果这个字母出现次数为0了，那就不能删除了，如果这个字母后续还会出现，就可以删除

 一直对所有读入的字母按照最佳的字典序排序（在不违反读取顺序的前提下），所以只能在队尾进行操作。

其实如果要改成栈我觉得好像也可以。。。但是要有一个数组去存储栈内部是否存在有这个元素。会更多几个步骤

改进方法就是不用在队列里查找，而使用bitset或者vector去存储这个字母是否visited了。

讲个例子也许更形象 比如说abdcd这个串，先扫一遍，a：1个，b：1个，c：1个，d：2个。然后存下来，第二遍从头扫，扫到a，a-1个，a入队列，b-1个，b入队列

d-1个，d入队列，c，c比d小，那贪心点，要c，看看d能不能删，d后面还有1个，就可以删，然后前面b，b比c小（而且b后面也没了），就不能删了，c入队列，变成abc，然后d入队列。

以此类推，一些情况加上限制即可，代码确实不完善，但是改进的话交给大佬了。我觉得优化之后复杂度应该是O(n)左右（n为text的size）。

```
class Solution {
public:
    bool ifIndeque(const deque<char> &a, const char &b) {
        for (char c : a) if (c == b) return 1;
        return 0;
    }
    string smallestSubsequence(string text) {
        vector<int> tmp(26, 0);
        string res;
        deque<char> a;
        for (char i : text) ++tmp[i - 'a'];
        for (char i : text) {
            --tmp[i - 'a'];
            if (a.empty()) a.push_back(i);
            else if (i < a.front()) {
                while (!a.empty() && tmp[a.back() - 'a'] && i < a.back()) a.pop_back();
                if (!ifIndeque(a, i)) a.push_back(i);
            }
            else if (i > a.back() && !ifIndeque(a, i)) a.push_back(i);
            else if (i > a.front() && i < a.back() && !ifIndeque(a, i)) {
                while (i < a.back() && tmp[a.back() - 'a']) a.pop_back();
                a.push_back(i);
            }
        }
        for (char c : a) res += c;
        return res;
    }
};


```