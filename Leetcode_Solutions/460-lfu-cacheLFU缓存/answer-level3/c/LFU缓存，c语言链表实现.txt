### 解题思路

### 代码

```c

/*
    注意：
    最少最近使用的意思是  频率最低  最久没有使用的  且考虑级别： 频率 > 时间
    
    要实现题目，采取以下措施：
    每次进行put或get操作时，次数都加一，
    且要将被使用的那个节点放置链表的最前面，这里采取的措施是：先删除，然后创建新节点放到头节点后面（链表实现时我使用了头节点）

    put:
    1) 若可以直接插入，则直接插入
    2) 若要替换，则先将被替换的值先删除，然后将替换的数据插入

    get:
    将旧键数据删除，然后将新数据填入。
    其实get操作只是将该数据节点的times加1，还有将其放到了链表头节点之后

*/
struct lfuKey;
typedef struct lfuKey LFUKey;
struct lfuKey {
    int times;
    int key;
    int value;
    LFUKey *next;
};



typedef struct {
    int capacity;
    int size;
    LFUKey *keyHeader;
} LFUCache;


LFUCache* lFUCacheCreate(int capacity) {
    LFUCache *cache = ( LFUCache * ) malloc( sizeof( LFUCache ) );
    cache->capacity = capacity;
    cache->size = 0;
    //使用头指针
    cache->keyHeader = ( LFUKey * ) malloc( sizeof( LFUKey ) );
    cache->keyHeader->next = NULL;
    return cache;
}

LFUKey *findPrevios( LFUCache *cache, int key )
{
    LFUKey *kh = cache->keyHeader;
    while( kh->next != NULL && kh->next->key != key )
        kh = kh->next;
    return kh;
}

void deleteKey( LFUCache *cache, int key )
{
    LFUKey *pre = findPrevios( cache, key );
    LFUKey *tar = pre->next;
    if( tar != NULL )
    {
        pre->next = tar->next;
        free( tar );
    }
}

void insertKey( LFUCache *cache, int key, int value, int times )
{
    LFUKey *kh = cache->keyHeader;
    LFUKey *newCell = ( LFUKey * ) malloc( sizeof( LFUKey ) );
    newCell->times = times;
    newCell->key = key;
    newCell->value = value;
    newCell->next = kh->next;
    kh->next = newCell;
}

int lFUCacheGet(LFUCache* cache, int key) {
    LFUKey *pre = findPrevios( cache, key );
    LFUKey *tar = pre->next;
    if( tar != NULL )
    {
        int v = tar->value;
        tar->times++;
        int t = tar->times;
        deleteKey( cache, key );
        insertKey( cache, key, v, t );
        return v;
    }
    else
        return -1;

}

void lFUCachePut(LFUCache* cache, int key, int value) {
    if( (cache->capacity) > 0 )  //当capacity大于0时，才能插入
    {
        int minTimes = 0, flag = 1,count;
        LFUKey *kh = cache->keyHeader;
        LFUKey *h = kh->next;
        LFUKey *pre = findPrevios( cache, key );
        LFUKey *tar = pre->next;

        if( tar == NULL )  //若之前没有此键，则进行插入
        {
            if( cache->size < cache->capacity )  //若大小小于容量，则直接插入
            {
                insertKey( cache, key, value, 1 );
                cache->size++;
            }
            else
            {
                //查找最小次数
                while( flag == 1 )
                {
                    count = 0;  //count为次数最好的元素个数
                    minTimes++;  //最小次数开始为1
                    h = kh->next;  //从头开始扫描
                    while( h != NULL )
                    {
                        if( minTimes == h->times )  //若相等
                        {
                            count++;  //数量加1
                            flag = 0;  //找到了最小次数，不用继续将minTimes加1循环查找
                        }
                        h = h->next;
                    }
                }

                h = kh->next;  //从头开始
                while( h != NULL )
                {
                    if( h->times == minTimes )
                    {
                        //直到找到最近最少使用的元素，才进行操作
                        //最近最少的意思时是 频率最小  没有使用的时间最长
                        if( count == 1 )
                        {
                            deleteKey( cache, h->key );  //先删除要被替代的key
                            insertKey( cache, key, value, 1 );  //再重新插入新键
                            break;
                        }
                        else
                            count--;
                    }
                    h = h->next;
                }
            }
        }
        else  //若之前有此键，则进行更新
        {
            (tar->times)++;
            int t = tar->times;
            deleteKey( cache, key );
            insertKey( cache, key, value, t );
        }
    }
}

void lFUCacheFree(LFUCache* cache) {
    LFUKey *t;
    LFUKey *kh = cache->keyHeader;
    while( kh->next != NULL )
    {
        t = kh->next;
        kh->next = t->next;
        free( t );
    }
    free( kh );
    free( cache );
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/
```