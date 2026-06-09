### 解题思路
这题当然首先想到的还是qsort，但是qsort怎么根据哈希值排序呢？

可以创建一个全局数组，qsort的时候，传入的是字符串s的每一个元素，但是排序的依据是由这个哈希数组的值确定的。

这题最关键的地方:如果哈希值相等，直接按哈希值排序的话，qsort可能不会移动相等的位置。
所以这里添加个：
    if (g_hashMap[(int)aa] == g_hashMap[(int)bb]) {
        return aa - bb;
    }

    return g_hashMap[(int)bb] - g_hashMap[(int)aa];

如果相等，但是字母不相同的话，我们按字符的大小直接排序
最后，我们要返回从大到小排序，所以b在前面
### 代码

```c
#define MAX 200
int g_hashMap[MAX];

int Compare(const void *a, const void *b) {
    char aa = *(char *)a;
    char bb = *(char *)b;

    if (g_hashMap[(int)aa] == g_hashMap[(int)bb]) {
        return aa - bb;
    }

    return g_hashMap[(int)bb] - g_hashMap[(int)aa];
}

char * frequencySort(char * s){
    if (s == NULL) {
        return NULL;
    }

    int size = strlen(s);
    int index = 0;
    memset(g_hashMap, 0, MAX * sizeof(int));

    while(index < size) {
        g_hashMap[(int)s[index]]++;
        index++;
    }

    qsort(s, size, sizeof(char), Compare);
    return s;

}
```