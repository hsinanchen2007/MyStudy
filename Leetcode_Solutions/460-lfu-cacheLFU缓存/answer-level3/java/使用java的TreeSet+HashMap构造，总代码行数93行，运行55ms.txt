使用java的TreeSet+HashMap构造双向链表，总代码行数93行，运行55ms
思路大佬们都讲的很清楚了，这里提供一种使用TreeSet和HashMap的方式来构建数据结构，存储频率队列
代码中的TreeSet<Long> freqSet;用于快速找到频率最小的频率队列
class FreqQueue 中的TreeSet<Long> index;用于快速查找当前频率相同的时间队列中，时间戳最小的节点。
代码量较少+运行时间还说得过去，提供一种思路。
写一个类似官方题解中的结构体也可以
```
class FreqQueue{
        TreeSet<Long> index;
        Map<Integer,Long> nameToId;
        Map<Long,Integer> idToName;
        long id;
        FreqQueue(){
            id=0;
            index=new TreeSet<>();
            nameToId=new HashMap<>();
            idToName=new HashMap<>();
        }
        void add(Integer item){
            id++;
            index.add(id);
            nameToId.put(item,id);
            idToName.put(id,item);
        }
        void remove(Integer item){
            Long curId=nameToId.get(item);
            index.remove(curId);
            idToName.remove(curId);
            nameToId.remove(item);
        }
        int getLast(){
            return idToName.get(index.first());
        }
        void removeLast(){
            long res=index.first();
            remove(idToName.get(res));
        }
        boolean empty(){
            return index.isEmpty();
        }
    }
    class LFUCache {
        TreeSet<Long> freqSet;
        int cap;
        int n;
        Map<Integer,Integer> cache;
        Map<Integer,Long> cacheFreq;
        Map<Long,FreqQueue> mylist;
        public LFUCache(int capacity) {
            freqSet=new TreeSet<>();
            cache=new HashMap<>();
            cap=capacity;
            n=cap;
            cacheFreq=new HashMap<>();
            mylist=new HashMap<>();
        }
        public int get(int key) {
            if(!cache.containsKey(key)) return -1;
            Long cnt=cacheFreq.get(key);//获取当前key的频率
            mylist.get(cnt).remove(key);//在旧的频率列表中移除
            if(mylist.get(cnt).empty()) {//移除
                freqSet.remove(cnt);
                mylist.remove(cnt);
            }
            cnt++;
            if(!freqSet.contains(cnt)) freqSet.add(cnt);
            cacheFreq.put(key,cnt);//更新频率
            if(!mylist.containsKey(cnt)) mylist.put(cnt,new FreqQueue());
            mylist.get(cnt).add(key);
            return cache.get(key);//获取到value值
        }
        public void put(int key, int value) {
            if(n==0) return ;
            if(cache.containsKey(key)) {  
                cache.put(key,value);
                get(key);
                return ;
            }
            else if(cap==0){//不够用的,移除频率最小的最后一个
                cap++;
                Long minFreq=freqSet.first();
                int minItem=mylist.get(minFreq).getLast();
                mylist.get(minFreq).removeLast();
                if(mylist.get(minFreq).empty()){
                    mylist.remove(minFreq);
                    freqSet.remove(minFreq);
                }
                cacheFreq.remove(minItem);
                cache.remove(minItem);
            }       
            cache.put(key,value);   
            if(!freqSet.contains((long)1)) {    
                mylist.put((long)1,new FreqQueue());
            } 
            freqSet.add((long)1);
            mylist.get((long)1).add(key);
            cacheFreq.put(key,(long)1);
            cap--;
        }
    }
```
