### 解题思路
定义两个HashMap分别是Map<Integer, Node> map用来存放key与value值Map<Integer, LinkedList<Node>> linkedListMap中key是使用频率value:是对应这个使用频率的所有元素的组成的链表,元素头部是最近使用过的,尾部是最远使用过的元素
每一次使用过某个元素,就将对应的元素放到链表头部,这样保证链表头部一直是最近使用的,而尾部是最久远使用的

ps:以下代码,写的有点乱,很多地方是重复的,可以单独写一个方法...
### 代码

```java
class LFUCache {
    //定义Node
    class Node {
        //key
        int key;
        //value
        int value;
        //出现的次数
        int count;

        public Node(Integer key, Integer value, Integer count) {
            this.key = key;
            this.value = value;
            this.count = count;
        }
    }
    //存放key与node节点
    Map<Integer, Node> map = new HashMap<>();
    //key是出现的频率 value:同一频率下的所有node,按照从最近到最远使用排序
    Map<Integer, LinkedList<Node>> linkedListMap = new HashMap<>();
    //最大容量
    int capacity;
    //最小频率的次数,默认是1,每一次get时候或者put时候都需要检查linkedListMap.get(minCount)
    //如果linkedListMap.get(minCount)==null时候说明minCount已经没有对应的节点出现minCount个频率,需要将minCount+1,
    //因为最后一个出现minCount的元素要么被删掉,要么出现频率变成minCount+1,升级到minCount+1对应的链表下面
    //如果是被删掉,那么肯定会放进一个新的元素进来,然后在把minCount重置为1
    int minCount = 1;

    public LFUCache(int capacity) {
        this.capacity = capacity;
    }


    public int get(int key) {
        //如果容量是0直接返回-1
        if (this.capacity == 0) {
            return -1;
        }
        //判断key是否存在
        if (map.containsKey(key)) {
            //key存在,将对应节点取出来
            Node node = map.get(key);
            Integer count = node.count;
            //取出链表
            LinkedList<Node> linkedList = linkedListMap.get(count);
            //删掉对应节点
            linkedList.remove(node);
            //如果链表长度变为0,说明出现count频率的节点不存在了,从linkedListMap中删掉
            if (linkedList.size() == 0) {
                linkedListMap.remove(count);
            }
            //检查最小出现频率的对应的链表是否还存在,如果不存在minCount+1
            if (linkedListMap.get(minCount) == null) {
                minCount++;
            }
            //对应节点的出现的频率加1
            count++;
            node.count = count;
            //判断新的conut对应链表是否存在,如果存在直接添加到链表头部,如果不存在创建一个新的链表放到linkedListMap中
            if (linkedListMap.containsKey(count)) {
                LinkedList<Node> list = linkedListMap.get(count);
                //添加到头部,保证头部永远是最新的
                list.addFirst(node);
                linkedListMap.put(count, list);
            } else {
                LinkedList<Node> list = new LinkedList<>();
                list.addFirst(node);
                linkedListMap.put(count, list);
            }
            return node.value;
        } else {
            //key不存在直接返回-1
            return -1;
        }
    }

    public void put(int key, int value) {
        //如果容量是0直接返回不操作
        if (this.capacity == 0) {
            return;
        } else if (map.containsKey(key)) {
            //map中包含key,一下操作与get类似,可以提出来单独写一个方法
            Node node = map.get(key);
            int count = node.count;
            LinkedList<Node> linkedList = linkedListMap.get(count);
            linkedList.remove(node);
            if (linkedList.size() == 0) {
                linkedListMap.remove(count);
            }
            if (linkedListMap.get(minCount) == null) {
                minCount++;
            }
            count++;
            node.count = count;
            node.value = value;
            if (linkedListMap.containsKey(count)) {
                LinkedList<Node> list = linkedListMap.get(count);
                list.addFirst(node);
                linkedListMap.put(count, list);
            } else {
                LinkedList<Node> list = new LinkedList<>();
                list.addFirst(node);
                linkedListMap.put(count, list);
            }
            //更新map对应的节点
            map.put(key, node);
        } else {
            //如果map不存在对应key,需要put新的元素进去,如果map.size() < capacity直接向map中添加元素,
            //并且在linkedListMap.containsKey(1)对应的链表中添加节点到头部,与get类似操作
            if (map.size() < capacity) {
                Node node = new Node(key, value, 1);
                map.put(key, node);
                minCount = 1;
                if (linkedListMap.containsKey(node.count)) {
                    LinkedList<Node> list = linkedListMap.get(node.count);
                    //向头部添加节点
                    list.addFirst(node);
                    linkedListMap.put(node.count, list);
                } else {
                    LinkedList<Node> list = new LinkedList<>();
                    list.addFirst(node);
                    linkedListMap.put(node.count, list);
                }
            } else {
                //如果map.size() >= capacity,需要删除map中的某个节点
                //取出linkedListMap.get(minCount)对应的链表,删掉末尾元素,因为末尾元素是最久远使用的
                LinkedList<Node> list = linkedListMap.get(minCount);
                Node removeLast = list.removeLast();
                map.remove(removeLast.key);
                //如果删掉之后链表size变为0,就将链表从linkedListMap删掉
                if (list.size() == 0) {
                    linkedListMap.remove(minCount);
                }
                //创建新的节点
                Node node = new Node(key, value, 1);
                //重新赋值最小出现频率,重置为1,因为新的节点出现频率从1开始
                minCount = 1;
                map.put(key, node);
                if (linkedListMap.containsKey(node.count)) {
                    LinkedList<Node> linkedList = linkedListMap.get(node.count);
                    linkedList.addFirst(node);
                    linkedListMap.put(node.count, linkedList);
                } else {
                    LinkedList<Node> linkedList = new LinkedList<>();
                    linkedList.addFirst(node);
                    linkedListMap.put(node.count, linkedList);
                }
            }
        }
    }
}

```