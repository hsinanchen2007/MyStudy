## 1. 定义数据结构：

为了更快的查询和插入数据。整个跳表才用双向链表。 并且跳表会有一个coin flip的过程，所以还需up down 来指向冗余数据。

（用空间换时间的代表）。

```java
//SkipListEntry as a Set Entry  
    class SkipListEntry{
        Integer value;

        SkipListEntry up;
        SkipListEntry down;
        SkipListEntry left;
        SkipListEntry right;

        // constructor
        public SkipListEntry(Integer value) {
            this.value = value;
        }

        //Getter
        public Integer getValue(){
            return this.value;
        }

    }
```


## 2. 准备辅助类与辅助函数。

生成随机数的类。

```java
static class RandomGenerator{

        private static Random random = new Random();

        public static boolean getRandomBoolean(float probability){
            return random.nextFloat() < probability;
        }
    }
```

建立entry之间的横向链接和纵向链接。

```java
private static void insertEntryAfterHorizontally(SkipListEntry source, SkipListEntry target){
    target.left = source;
    target.right = source.right;
    source.right.left = target;
    source.right = target;
}
private static void insertEntryAfterVertically(SkipListEntry source, SkipListEntry target){
    source.down = target; 
    target.up = source;
}
```
**说明： 为了让双链表的insert方法对于所有节点都实用。需要一个header和tail。他们的value为空。**


## 3.设计关键函数。

无论是`bool search(int target)`， 还是`bool erase(int num)` 与 `bool erase(int num)`。都需要一个关键的先置函数，即根据target值，找到相应的值在跳表中的对象，或者小于target中最大的值的对象。

寻找起始点，从最高层的header 头节点来寻找。如果在本层没有找到某个entry使得下个entry的值比target来得大或者找到尾部了，则递归继续寻找下一层。直至找到最后一层。（这里如果找到某个entry，那么其实是找到最底层的entry的值和这一层的元素值相等）。


```java
private SkipListEntry findEntry(Integer value, SkipListEntry startEntry){

        // iterate through the linkedlist of current Level .
        SkipListEntry cur= startEntry;
        while(cur.right.getValue() != null && cur.right.getValue() <= value){
            cur = cur.right;
        }


        // if lower layer exists, find the entry at lower layer 
        if(cur.down != null){
            return findEntry(value, cur.down);
        }


        return cur;
    }
```


## 4.完成任务函数。

- search 函数 


如果找到entry是header或者比target来的小， 则没有该节点。

```java

 public boolean search(int target) {

    SkipListEntry searchingResult = findEntry(target, this.head);
    
    if(searchingResult.getValue() == null || searchingResult.getValue() != target){
        return false;
    }

    return true;   
}

```



- 添加函数

找到要添加的位置，（最底层）。 **在最底层开始添加** entry。 并根据概率向上产生冗余数据。如果到了最高层，则新建一层。
建立上下层的关系以及本层的关系。 由于冗余数据的随机性，有一些数据是在上层是没有数据的。 所以。需要找到前一个有上层的元素，作为索引，找到上层的相同值的元素，并添加新的entry在其后面。

Note that duplicates may exist in the Skiplist, your code needs to handle this situation.

针对这一点， 并不需要判断是否这个结果已经存在了。无脑往里面加就行了， 即把相同value的可以有多个entry。



```java

public void add(int num) {

        SkipListEntry searchingResult = findEntry(num, this.head);

        SkipListEntry newEntry = new SkipListEntry(num);

        insertEntryAfterHorizontally(searchingResult, newEntry);

        int curLevel = 1;
        // add redundent values by flipping coins
        while(RandomGenerator.getRandomBoolean(0.5f)){

            // if the curLevel exceeds the range, create a new level
            if(curLevel > this.levels){
                createEmptyLevel();
            }

            // find the entry that has the same value at the upper layer
            while(searchingResult.up == null){          
                searchingResult = searchingResult.left; //error 
            }

            // find the insertion position at previous layer
            searchingResult = searchingResult.up; 

            // insert duplicates
            SkipListEntry newEntryDuplicate = new SkipListEntry(num);

            // connections with the current layer
            insertEntryAfterHorizontally(searchingResult, newEntryDuplicate);
            // connections with previous result 
            insertEntryAfterVertically(newEntryDuplicate,newEntry);

            newEntry = newEntryDuplicate; 

            curLevel +=1; 
        }
    }

```

- 删除函数



同样是找到最底层的entry。将其删除，如果上层有等值的冗余函数， 则向上循环/递归 删除。 

```java
 public boolean erase(int num) {

        SkipListEntry searchingResult = findEntry(num,this.head); 
        SkipListEntry higherEntry = null;

        if(searchingResult.getValue() == null || searchingResult.getValue() != num){
            return false;
        }

        while(searchingResult != null){
            higherEntry = searchingResult.up;
            // remove the result at current layer
            searchingResult.left.right = searchingResult.right;
            searchingResult.right.left = searchingResult.left;
            // move to higher level Entry.
            searchingResult = higherEntry;
        }
        return true; 
}
```


## 5.整合在一起。


```java
class Skiplist {

    private SkipListEntry head;  // First Entry of the top level
    private SkipListEntry tail;
    private Integer levels;

    static class RandomGenerator{

        private static Random random = new Random();

        public static boolean getRandomBoolean(float probability){
            return random.nextFloat() < probability;
        }
    }

    //SkipListEntry as a Set Entry  
    class SkipListEntry{
        Integer value;

        SkipListEntry up;
        SkipListEntry down;
        SkipListEntry left;
        SkipListEntry right;

        // constructor
        public SkipListEntry(Integer value) {
            this.value = value;
        }

        //Getter
        public Integer getValue(){
            return this.value;
        }

    }

    private static void insertEntryAfterHorizontally(SkipListEntry source, SkipListEntry target){
            target.left = source;
            target.right = source.right;
            source.right.left = target;
            source.right = target;
        }
    private static void insertEntryAfterVertically(SkipListEntry source, SkipListEntry target){
            source.down = target; 
            target.up = source;
        }


    // constructor
    public Skiplist() {

        head = new SkipListEntry(null);
        tail = new SkipListEntry(null);

        head.right = tail;
        tail.left = head;

        levels = 0;
    }

    private SkipListEntry findEntry(Integer value, SkipListEntry startEntry){

        // iterate through the linkedlist of current Level .
        SkipListEntry cur= startEntry;
        while(cur.right.getValue() != null && cur.right.getValue() <= value){
            cur = cur.right;
        }


        // if lower layer exists, find the entry at lower layer 
        if(cur.down != null){
            return findEntry(value, cur.down);
        }


        return cur;
    }

    private void createEmptyLevel() {

        SkipListEntry newHeader = new SkipListEntry(null);
        SkipListEntry newTail = new SkipListEntry(null);

        newHeader.right = newTail;
        newTail.left = newHeader;

        //Create connections 
        insertEntryAfterVertically(newHeader,this.head);
        insertEntryAfterVertically(newTail,this.tail);


        //Update head and tail 
        this.head = newHeader;
        this.tail = newTail;

        this.levels += 1; 

    }
    
    public boolean search(int target) {

        SkipListEntry searchingResult = findEntry(target, this.head);
    
        if(searchingResult.getValue() == null || searchingResult.getValue() != target){
            return false;
        }

        return true;   
    }
    
    public void add(int num) {

        SkipListEntry searchingResult = findEntry(num, this.head);

        SkipListEntry newEntry = new SkipListEntry(num);

        insertEntryAfterHorizontally(searchingResult, newEntry);

        int curLevel = 1;
        // add redundent values by flipping coins
        while(RandomGenerator.getRandomBoolean(0.5f)){

            // if the curLevel exceeds the range, create a new level
            if(curLevel > this.levels){
                createEmptyLevel();
            }

            // find the entry that has the same value at the upper layer
            while(searchingResult.up == null){          
                searchingResult = searchingResult.left; //error 
            }

            // find the insertion position at previous layer
            searchingResult = searchingResult.up; 

            // insert duplicates
            SkipListEntry newEntryDuplicate = new SkipListEntry(num);

            // connections with the current layer
            insertEntryAfterHorizontally(searchingResult, newEntryDuplicate);
            // connections with previous result 
            insertEntryAfterVertically(newEntryDuplicate,newEntry);

            newEntry = newEntryDuplicate; 

            curLevel +=1; 
        }
    }
    
    public boolean erase(int num) {

        SkipListEntry searchingResult = findEntry(num,this.head); 
        SkipListEntry higherEntry = null;

        if(searchingResult.getValue() == null || searchingResult.getValue() != num){
            return false;
        }

        while(searchingResult != null){
            higherEntry = searchingResult.up;
            // remove the result at current layer
            searchingResult.left.right = searchingResult.right;
            searchingResult.right.left = searchingResult.left;
            // move to higher level Entry.
            searchingResult = higherEntry;
        }
        return true; 
    }
}

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist obj = new Skiplist();
 * boolean param_1 = obj.search(target);
 * obj.add(num);
 * boolean param_3 = obj.erase(num);
 */
```


















