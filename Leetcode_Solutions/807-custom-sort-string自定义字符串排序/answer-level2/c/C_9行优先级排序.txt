### 解题思路
本题就是优先级排序问题，可以用hash表互射。

### 代码一、排序
根据给定字符串`S`从头往后得到优先级，比如下面`maxPriority=26`逐渐递减，因为题目说**最大26且不重复。**
最后快排返回，这里用字符串`T`应该不对的。。。
```c []
char * customSortString(char * S, char * T){
    short Priority[26] = {0}, maxPriority = 26;
    while (*S) Priority[(*S++)-97] = maxPriority--;
    int cmp(const void *a, const void *b) {
        return (Priority[*(char*)b-97] - Priority[*(char*)a-97]);
    }
    qsort(T, strlen(T), sizeof(T[0]), cmp);
    return T;
}
```
```python3 []
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        return ''.join(sorted(list(T), key=lambda x:S.find(x)))  # find没找到就是-1
```
### 代码二、两个hash存键值，键值互射
1. 读取`S`字符串，将**字符**放在`char char_s[26]`中，同时用`short cnt_s[26]`记录此字符**出现为1**，否者`0`代表T中字符不在。
2. 上述T中字符不在S中，直接把它搬到`T`最前面，等待所有`T`检测完，最后填入`S`中的字符。否者`cnt_s[T[i]]++`记录这个出现多少次。
3. 而关键就是如何直到顺序，因此上面设计的`char char_s[26]`根据0,1,2索引就得到S中优先级的字符了。
4. 最后就是把T中含有多个`S`中的优先级字符拿出来填入`T`即可。

可能有点绕，关键点就是：1.S中先后顺序。2.T中多个字符在S中该如何排序。
```c []
char * customSortString(char * S, char * T){
    short cnt_s[26] = {0}, char_s[26] = {0};
    // 1.处理S字符优先级与字符
    short i, j, idx, priority;
    for (i = 0; S[i] != '\0'; i++) {
        cnt_s[S[i]-97] = 1;  // 字符出现为1
        char_s[i] = S[i];  // 优先级字符
    }
    // 2.处理S中的字符，先把不存在填入T前面(z作为索引填充T)
    for (idx = 0, j = 0; T[j] != '\0'; j++) {
        if (cnt_s[T[j]-97] > 0) {  // T[j]在S中
            cnt_s[T[j]-97]++;  // 重复个数+1(注意初始就是1，多了1)
        } else T[idx++] = T[j];  // T[j]不在S中随意填到前面
    }
    // 3.将S中优先字符从bucketSChar中取出填入
    for (i = 0; char_s[i] != 0; i++) {  // (1)从优先级找到对应字符
        while (cnt_s[char_s[i]-97] > 1) {  // (2)条件是出现次数>1
            T[idx++] = char_s[i];
            cnt_s[char_s[i]-97]--;  // 假设a最高，但是T中有n个a
        }
    }
    return T;
}
```

### 代码三、python字典插入有序
参考[这里](https://leetcode-cn.com/problems/custom-sort-string/solution/pythoncounterji-shu-qi-sao-cao-zuo-by-luanz/),因为在python3中，字典插入有序，那么插入`S`中字符串就保持先后顺序，本题就这样解决了。

`(cs + ct - cs)`先后关系很关键，因为`cs`在前表示它顺序最先，然后`+`操作相当合并字典，因此数量增加，但是增加了`cs`词频，因此再减去。它们顺序不可改变！
```python3
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        cs = collections.Counter(S)
        ct = collections.Counter(T)
        return ''.join((cs + ct - cs).elements())
```

