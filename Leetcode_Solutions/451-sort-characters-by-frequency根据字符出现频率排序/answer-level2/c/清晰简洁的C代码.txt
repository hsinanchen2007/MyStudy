**内存消耗在所有 C 提交中击败了 100.00% 的用户**
### 解题思路
1. 如果字符串长度是 2 以内，无需任何操作，直接返回就行；
1. 对各字符出现次数进行计数(ascii 字符串最大为 128)；
1. 使用快速排序 qsort 对 s 排序：
 - 按字符出现次数从大到小排列，但如果次数相等，则按字符本身从小到大排列；
 - 为了代码简洁，特意把 cmp 子函数嵌套在函数内部。

### 代码

```c
char * frequencySort(char * s){
    int len = strlen(s);
    if (len <= 2)
        return s;
    int count[128] = {0}; //ascii字符串最大为128
    for (int i = 0; i < len; i++) {
        count[s[i]]++;
    }
    int cmp(const void *p1, const void *p2) {
        char c1 = *(char*)p1;
        char c2 = *(char*)p2;
        //按字符出现次数从大到小排列，但如果次数相等，则按字符本身的从小到大排列
        return count[c1] == count[c2] ?  c1 > c2 : count[c1] < count[c2]; 
    }
    qsort(s, len, sizeof(char), cmp);
    return s;
}
```