先定义函数f()，此函数实现对单个字符串实现输出最小字母个数的功能。

根据题干理解，所比较的对象全部是字符串经过f函数处理后得到的数字列表。因此先把queries和words列表中的元素进行f函数处理。

此时得到两个数字列表num_queries和num_words。对于num_queries中的某个元素，统计 num_words中比此元素大的元素个数。处理完num_queries中的所有元素后，便可以得到题干要求的最终列表。


```python3 []
class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        num_words = []
        num_answer = []
        for i in words:
            num_words.append(f(i))
        #print(num_words)
#这里把queries中的元素i添加进num_words中，排序去重，得到的比i大的元素数量，
#比较麻烦，不如先求出num_queries再遍历两次。
        for i in queries:
            cur = []
            cur.extend(num_words)
            cur.append(f(i))
            cur = sorted(cur)
            num_answer.append(len(cur)-1-cur.index(f(i))-cur.count(f(i))+1)
        return num_answer

def f(s):
    list_s = []
    for i in s:
        list_s.append(i)
    list_s.sort()#sort函数可以按照字典序从小到大自动排序
    num = list_s.count(list_s[0])#第一位肯定是最小的，统计第一位出现的次数。
    return num

#时间 2120ms， 6.66%，内存 14.2Mb， 100%。
```


```python3 []
class Solution:
    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        num_words = []
        num_queries = []
        num_answer = []
        for i in words:
            num_words.append(f(i))
        for i in queries:
            num_queries.append(f(i))
        #print(num_words)
        for i in num_queries:
            count = 0
            for j in num_words:
                if j > i:
                    count += 1
            num_answer.append(count)
        return num_answer
    
def f(s):
    list_s = []
    for i in s:
        list_s.append(i)
    list_s.sort()
    num = list_s.count(list_s[0])
    return num
#时间 564ms， 46.67%，内存 14.3, 100%。
```
