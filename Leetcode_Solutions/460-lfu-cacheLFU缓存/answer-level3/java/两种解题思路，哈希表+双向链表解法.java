当缓存的容量已满的时候，继续添加缓存要删除一条最近最少访问的记录。如何找到这条记录呢？这不是一个简单的排序问题，要用合适的数据结构去存储添加的缓存记录。一种方法是用堆去存储，也就是JDK里面的PriorityQueue，保证每次最近最少访问的元素总是在最上面，但每次添加和删除元素之后都要重新排序，性能上面会打折扣。后来想到用双向链表来实现，在JDK有个LinkedList可以实现，不足的地方是虽然LinkedList内部是用双向链表去实现存储的，每次访问一个元素依然要遍历这个链表才可以找到对象在链表中的位置，这是一个O(n)时间复杂度的操作。从其他大神的题解中获得启发，自定义双链表可以解决这个问题，改进后的方法执行时间比原来缩短了十倍。具体的步骤如下：
1、每次添加缓存时这个缓存的访问频率默认是0；
2、将元素添加到链表的头部，具体的位置有两种可能：
    - 链表中还存在访问频率为0的节点，则添加到最后一个频率为0的节点的最后面；
    - 链表中所有的元素最少已经被访问一次，则直接将新元素添加到队列头；
3、每次访问一个元素将这个元素添加到合适的位置，将节点从原来的位置删除，从链表后面开始查找，插入到第一个访问频率小于或等于当前访问频率的元素后面；

下面附上代码，第一次写题解，解析有错误的地方请各位批评指正



    class LFUCache {

        Map<Integer, Item> keyValue;
        AtomicInteger atomicInteger ;
        LinkedList<Item> linkedList;
        Item head;
        Item end;
        int capacity;

        public LFUCache(int capacity) {
            this.keyValue = new HashMap<>(capacity);
            this.capacity = capacity;
            atomicInteger = new AtomicInteger(capacity);
            head = new Item();
            end = new Item();
        }

        public int get(int key) {
            if (keyValue.containsKey(key)){
                Item item = keyValue.get(key);
                item.frequent = ++ item.frequent;
                moveToNewPosition(item);
                return keyValue.get(key).value;
            }
            return -1;
        }

        public void put(int key, int value) {
            if (capacity == 0)
                return;

            if (keyValue.containsKey(key)) {
                // 已经存在key， 之间替换
                Item item = keyValue.get(key);
                item.value = value;
                item.frequent = ++item.frequent;
                keyValue.put(key, item);
                moveToNewPosition(item);

            }else{
                if (atomicInteger.get() == 0){
                    // 容量已满，将最近最少使用的元素移除
                    keyValue.remove(pollFirst());
                }
                // 添加元素到哈希表和指针队列
                Item item = new Item(key, value);
                keyValue.put(key, item);
                //将元素添加到列头
                addFromTop(item);
                // 总容量减一
                if (atomicInteger.get() > 0)
                    atomicInteger.decrementAndGet();
            }
        }

        public int pollFirst(){
            Item temp = head.next;
            if (temp.next == end){
                head.next = null;
                end.pre = null;
                return temp.key;
            }else{
                head.next = temp.next;
                temp.next.pre = head;
            }
            temp.next =null;
            temp.pre = null;
            return temp.key;
        }

        public void addFromTop(Item item){
            if (head.next == null){
                head.next = item;
                end.pre = item;
                item.pre = head;
                item.next = end;
            }else{
                Item index = head.next;

                // 直接插入在index前面
                if (index.frequent > 0){
                    head.next = item;
                    item.next = index;
                    item.pre = head;
                    index.pre = item;
                    return;
                }

                // 寻找第一个访问次数不等于0的节点
                while(index.frequent == 0 && index.next != end){
                    index = index.next;
                }

                if (index.frequent > 0){
                    index.pre.next = item;
                    item.pre =index.pre;
                    index.pre = item;
                    item.next = index;
                }else{
                    // 已到达队尾
                    index.next = item;
                    item.pre = index;
                    item.next = end;
                    end.pre = item;
                }

            }
        }

        public void moveToNewPosition(Item item){
            if (item == end.pre){
                return;
            }
            Item last = end.pre;

            //从队尾开始寻找第一个引用次数小于或者等于item引用次数的的节点
            while(item.frequent < last.frequent){
                last = last.pre;
            }

            // 如果item是尾结点，不用更改节点顺序
            if (item != last){
                // 将item从原位置删除
                item.pre.next = item.next;
                item.next.pre = item.pre;
                //将item插入到last后面
                item.next = last.next;
                last.next.pre = item;
                last.next = item;
                item.pre = last;
            }

        }
    }

    class Item{
        int key;
        int value;
        int frequent;
        Item pre;
        Item next;

        Item(){

        }
        Item(int key, int value){
            this.key = key;
            this.value = value;
            this.frequent = 0;
        }
    }
