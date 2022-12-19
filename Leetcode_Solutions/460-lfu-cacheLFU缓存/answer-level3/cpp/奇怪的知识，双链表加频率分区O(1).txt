### 解题思路
如果用真实的链表结构，根本不用map！

双链表：每次一个键只从当前频率加一，所以，设置频率分区，分区有头尾指针（逻辑上），对一个键，如果频率加1，在双链表中删除这个键，插入到当前分区下一分区的尾指针前，这时候存在空分区的问题，所以我们需要找到最小的不空区，，每次get之后，判断当前分区是否为空（头尾指针是否相连），如果为空，指向下一分区，下一分区一定不为空，如果put进来新的键，那么最小不空区为频率为1的分区，不需要遍历链表，每次操作跟进一步即可，需要的就是若干个指针，头指尾，头指下一分区头，头指链表头，每个key指向当前分区头，操作为O(1);

### 代码

```cpp
class LFUCache {
public:
int cap;
int tmp=0;
int a[5000];
int v[5000];
int init;
map<int ,int>left;
map<int,int>right;
    LFUCache(int capacity) {
        cap=capacity;
        init=cap;
         left[-1]=0;
    right[0]=-1;
    for(int i=0; i<5000;i++)
    a[i]=0;
    }
    int maxn=1;

    int get(int key) {
        if(init==0)
        return -1;
        
        if(a[key]==0)
            return -1;
        a[key]++;
        if(a[key]>maxn){
            maxn=a[key];
            left[-maxn]=-maxn+1;
            right[-maxn+1]=-maxn;
        }

        int l=-a[key];
        right[left[key]]=right[key];
        left[right[key]]=left[key];
        right[left[l]]=key;
            left[key]=left[l];
            left[l]=key;
            right[key]=l;
        if(right[tmp]==tmp-1)
            tmp--;

return v[key];

    }
    
    void put(int key, int value) {
    if(init==0)
    return;
        if(a[key]!=0)
            {
                v[key]=value;
                a[key]++;
        if(a[key]>maxn){
            maxn=a[key];
            left[-maxn]=-maxn+1;
            right[-maxn+1]=-maxn;
        }

        int l=-a[key];
        right[left[key]]=right[key];
        left[right[key]]=left[key];
        right[left[l]]=key;
            left[key]=left[l];
            left[l]=key;
            right[key]=l;
        if(right[tmp]==tmp-1)
            tmp--;
                return;
            }
        a[key]=1;
        v[key]=value;
        if(cap==0){
            cap++;
            int t=right[tmp];
            //if(t>0)
            a[t]=0;
            right[tmp]=right[t];
            left[right[t]]=tmp;
            tmp=0;

        }
        if(cap>0){
            right[left[-1]]=key;
            left[key]=left[-1];
            left[-1]=key;
            right[key]=-1;
            cap--;
            tmp=0;
        }

    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```