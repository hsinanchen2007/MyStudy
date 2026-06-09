### 解题思路
给出两个一维的向量，请你实现一个迭代器，交替返回它们中间的元素。

示例:

输入:
v1 = [1,2]
v2 = [3,4,5,6] 

输出: [1,3,2,4,5,6]

解析: 通过连续调用 next 函数直到 hasNext 函数返回 false，
     next 函数返回值的次序应依次为: [1,3,2,4,5,6]。



题目意思弄明白就好做了

### 代码

```c
struct ZigzagIterator {
  int pos;
  int len;
  int *buf;
};

struct ZigzagIterator *zigzagIteratorCreate(int* v1, int v1Size, int* v2, int v2Size) {
    int i=0,j=0,size;
    struct ZigzagIterator *zig = (struct ZigzagIterator *)malloc(sizeof(struct ZigzagIterator));
    if(zig == NULL)
        return NULL;
    zig->buf = (int *)malloc((v1Size+v2Size)*sizeof(int));
    if(zig->buf == NULL){
        free(zig);
        return NULL;
    }
    zig->pos = 0;
    zig->len = v1Size + v2Size;
    size = v1Size > v2Size ? v1Size : v2Size;
    for(i=0;i<size;i++){
        if(i < v1Size){
            zig->buf[j++] = v1[i];
        }
        if(i<v2Size){
            zig->buf[j++] = v2[i];
        }
    }
    return zig;
}

bool zigzagIteratorHasNext(struct ZigzagIterator *iter) {
    if(iter->pos < iter->len)
        return true;
    else
        return false;
}

int zigzagIteratorNext(struct ZigzagIterator *iter) {
    return iter->buf[iter->pos++];
}

/** Deallocates memory previously allocated for the iterator */
void zigzagIteratorFree(struct ZigzagIterator *iter) {
    if(iter->buf)
        free(iter->buf);

    if(iter)
        free(iter);
}

/**
 * Your ZigzagIterator will be called like this:
 * struct ZigzagIterator *i = zigzagIteratorCreate(v1, v1Size, v2, v2Size);
 * while (zigzagIteratorHasNext(i)) printf("%d\n", zigzagIteratorNext(i));
 * zigzagIteratorFree(i);
 */
```