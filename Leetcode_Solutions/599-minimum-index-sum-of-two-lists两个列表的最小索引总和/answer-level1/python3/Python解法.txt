#### 思路
1. 先求交集，得到备选项
2. 如果交集只有一个元素，那就是它了，别无选择；
3. 利用字典生成式构造一个哈希表，`keys`为选择项、`values`为索引之和；
4. 因为要求索引之和最小，故以`value`值排序；
5. 如果`value`最小值唯一，即输出第一个`key`值，如果不唯一，则输出所有`value`值等于第一个`value`值的`keys`值（列表形式）。
#### 代码
```python
def findRestaurant(list1, list2):
    opt=list(set(list1)&set(list2))
    if len(opt)==1:
        return opt
    hmap={opt[i]:list1.index(opt[i])+list2.index(opt[i]) for i in range(len(opt))}
    # 按索引之和排序
    dic=sorted(hmap.items(),key=lambda x:x[1])
    i=1
    re=[dic[0][0]]
    while i<len(dic):
        if dic[i][1]==dic[i-1][1]:
            re.append(dic[i][0])
        i=i+1
    return re
```
参考评论区大佬，上述判断交集长度为1实际是多于的，并且在哈希表中找到最小索引和时也可直接利用列表生成式。可将代码写得更简洁，代码如下：
```python
def findRestaurant(list1, list2):
    opt=list(set(list1)&set(list2))
    hmap={opt[i]:list1.index(opt[i])+list2.index(opt[i]) for i in range(len(opt))}
    re=[r for r in opt if hmap[r]==min(hmap.values())]
    return re
```
#### 结果
优化前：
执行用时： 224 ms, 在所有 python3 提交中击败了57.36%的用户
内存消耗：13.1 MB, 在所有 python3 提交中击败了98.62%的用户

优化后：
执行用时：308 ms, 在所有 python3 提交中击败了31.98%的用户
内存消耗： 13 MB, 在所有 python3 提交中击败了100.00%的用户
![QQ截图20191231153044.png](https://pic.leetcode-cn.com/d8e21bb3edeef643fd7dbf10854cb00db7c5f6a82e1ab37c4b25e9e92290bb46-QQ%E6%88%AA%E5%9B%BE20191231153044.png)
