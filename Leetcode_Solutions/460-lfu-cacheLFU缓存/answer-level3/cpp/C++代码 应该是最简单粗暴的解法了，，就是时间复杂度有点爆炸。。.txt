### 解题思路
打卡完毕，我去看大佬们的题解了

### 代码

```cpp
class LFUCache {

    struct Cache{
        int value;  //值
        int key;    //键
        int times;  //使用次数
        Cache(int key,int value):key(key),value(value),times(1){};
    };
    vector<Cache> cache;
    int length_MAX;     //缓存允许的最大元素大小

public:
    LFUCache(int capacity) {
        length_MAX = capacity;
    }
    
    int get(int key) {
        for(int i=0;i<cache.size();i++)
        {
            if(cache[i].key==key)
            {   //如果找到了要把这个元素放在vector最后面，最近使用
                Cache temp=cache[i];
                temp.times++;   //使用次数增加
                cache.erase(cache.begin()+i); //删除该位置的元素
                cache.push_back(temp);   //添加到 vector 最后
                return temp.value;   //返回值
            }
        }
        return -1;      //没找到返回-1
    }
    
    void put(int key, int value) {
        if(length_MAX==0) return;   //如果最大长度为0不进行任何操作
        int min=0;      //记录当前缓存中使用次数最少的元素的位置（最近的）
        for(int i=0;i<cache.size();i++)
        {
            min=cache[min].times<=cache[i].times?min:i; //更新使用次数最少的元素位置

            if(cache[i].key==key)   //如果找到了键
            {
                Cache temp=cache[i];
                temp.times++;       //使用次数增加
                temp.value=value;   //修改值
                cache.erase(cache.begin()+i);   //删除原元素
                cache.push_back(temp);          //添加到最后表明是最近使用
                return ;
            }
        }

        if(cache.size()==length_MAX) //如果元素数量达到上限
        {
            cache.erase(cache.begin()+min); //删除其中使用次数最少，最近未使用的元素
        }
        cache.push_back(Cache(key,value)); //添加到最后表明是最近使用
    }
};
```