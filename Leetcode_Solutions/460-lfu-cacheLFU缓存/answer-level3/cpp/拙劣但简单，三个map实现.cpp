class LFUCache {
private: int cap;
         int capNow;//容量
         unordered_map<int,int> map;//记录数据
         unordered_map<int,int> count;//记录操作次数
         unordered_map<int,int> time;//记录操作时间
         int recent;//当前时间
public:
    LFUCache(int capacity) {
        cap=capacity;
        capNow=0;
        recent=0;
    }
    
    int get(int key) {
        auto iter = map.find(key);
        if(iter != map.end()) 
        {
            count[key]++;
            time[key]=++recent;
            return iter->second;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if(cap==0) return ;
        if(map.find(key)!=map.end())
        {
            //将新数据装入
            map[key]=value;
            count[key]++;
            time[key]=++recent;
            return;
        }
        else if(capNow==cap)
        {
            int least = count.begin()->second;
            int deleteKey=count.begin()->first;
            //查找使用次数最少的那个
            for(auto iter=++count.begin();iter!=count.end();iter++)
            {
                if(iter->second<least) 
                {
                    least = iter->second;
                    deleteKey = iter->first;
                }
                //相等的则查找它们最近谁先被访问
                if(iter->second==least)
                {
                   if(time[iter->first]<time[deleteKey])
                   {
                       deleteKey = iter->first;
                       least = iter->second;
                   }
                }
            }
            //删掉
            map.erase(map.find(deleteKey));
            count.erase(count.find(deleteKey));
            time.erase(time.find(deleteKey));
            capNow--;
        }
        //将新数据装入
        map[key]=value;
        count[key]=0;
        capNow++;
        time[key]=++recent;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
