```
class Value{
    int key;
    int val;
    int frequency;
    Value(int key,int val){
        this.key = key;
        this.val = val;
    }
    Value pre;
    Value next;
}
class DLHead{
    int frequency;
    Value head;
    Value tail;
    int length;
    DLHead(int frequency){
        this.frequency = frequency;
        head = new Value(-1,-1);
        tail = new Value(-1,-1);
        head.next = tail;
        tail.pre = head;
    }
    DLHead pre;
    DLHead next;
}
class LFUCache {
    Map<Integer, Value> cache;
    Map<Integer, DLHead> freq;
    int length;
    DLHead head;
    DLHead tail;
    public LFUCache(int capacity) {
        cache = new HashMap<>(capacity);
        freq = new HashMap<>();
        length = capacity;
        head = new DLHead(-1);
        tail = new DLHead(-1);
        head.next = tail;
        tail.pre = head;
    }
    public int get(int key) {
        if(cache.containsKey(key)){
            // 增加频次
            updateFreq(key);
            return cache.get(key).val;
        }
        return -1;
    }
    public void put(int key, int value) {
        if(length == 0) return;
        if(cache.containsKey(key)){
            // key 已存在，则更新val，更新频次
            cache.get(key).val = value;
            updateFreq(key);
        }else{
            // key 不在，判定是否满了
            if(cache.size() == length){
                // 删除频率最低，且最久没有访问的结点
                DLHead dlHead = head.next;
                Value delValue = dlHead.head.next;
                dlHead.head.next = delValue.next;
                dlHead.head.next.pre = dlHead.head;
                cache.remove(delValue.key);
                dlHead.length--;
                if(dlHead.length == 0){
                    // 删掉这个dlHead
                    dlHead.pre.next = dlHead.next;
                    dlHead.next.pre = dlHead.pre;
                    freq.remove(dlHead.frequency);
                }
            }
            // 新插入节点
            Value insertValue = new Value(key,value);
            cache.put(key,insertValue);
            if(!freq.containsKey(insertValue.frequency)){
                // 没有这个频率的, 即需要在头后面插入
                DLHead newHead = new DLHead(insertValue.frequency);
                newHead.next = head.next;
                newHead.next.pre = newHead;
                head.next = newHead;
                newHead.pre = head;
                freq.put(insertValue.frequency,newHead);
            }
            DLHead newHead = freq.get(insertValue.frequency);
            newHead.tail.pre.next = insertValue;
            insertValue.pre = newHead.tail.pre;
            insertValue.next = newHead.tail;
            newHead.tail.pre = insertValue;
            newHead.length++;
        }
    }
    private void updateFreq(int key){
        // 找到结点
        Value tmpValue = cache.get(key);
        DLHead tmpHead = freq.get(tmpValue.frequency);
        // 更新结点的频度
        tmpValue.frequency++;
        // 将结点与竖链断链
        tmpValue.next.pre = tmpValue.pre;
        tmpValue.pre.next = tmpValue.next;
        // 更新tmpHead的长度
        tmpHead.length--;
        int newFreqVal = tmpValue.frequency;
        if(!freq.containsKey(newFreqVal)){
            // 没有这个频率，需要增加dlhead.
            DLHead newDLHead = new DLHead(tmpValue.frequency);
            newDLHead.next = tmpHead.next;
            newDLHead.pre = tmpHead;
            tmpHead.next = newDLHead;
            newDLHead.next.pre = newDLHead;
            freq.put(tmpValue.frequency,newDLHead);
        }
        if(tmpHead.length == 0){
            // 删掉tmpHead
            tmpHead.pre.next = tmpHead.next;
            tmpHead.next.pre = tmpHead.pre;
            freq.remove(tmpHead.frequency);
        }
        tmpHead = freq.get(tmpValue.frequency);
        tmpValue.pre = tmpHead.tail.pre;
        tmpValue.next = tmpHead.tail;
        tmpValue.pre.next = tmpValue;
        tmpHead.tail.pre = tmpValue;
        tmpHead.length++;
    }
}

```
