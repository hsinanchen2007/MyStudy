### 解题思路
此处撰写解题思路
1.定义哈希映射key_table存储真正的键值，定义min保存最少访问的键，定义cap为容量
2.定义频率哈希映射freq_table，保存每个键访问的次数，value使用双链表
3.get操作
    3.1 检查key_table是否存在Key,不存在返回-1
    3.2 Key存在，更新访问频率,删除上一次的频率，新增fred+1
    3.3 更新key_table的访问频率
4.put操作
    4.1 检查Key_table是否存在Key，存在直接替换,同时更新freq_table
    4.2 不存在，检查容量，根据淘汰策略进行淘汰，这里使用min作为最少访问的键，根据min淘汰双链表尾部的数据
    4.3 新增节点,更新访问频率
### 代码

```csharp
public class LFUCache {
    private Dictionary<int, Node> key_table;
    private Dictionary<int, LinkedList<Node>> freq_table;
    private int min, cap;
    public LFUCache(int capacity) {
        key_table = new Dictionary<int, Node>(capacity);
        freq_table = new Dictionary<int, LinkedList<Node>>();
        min = 0;
        cap = capacity;
    }
    
    public int Get(int key) {
        //1.判断Key是否存在，不存在返回-1
        if (!key_table.ContainsKey(key))
        {
            return -1;
        }
        var cur = key_table[key];
        int val = cur.val, freq = cur.freq;
         //2.更新频率
        if (freq_table.ContainsKey(freq))
        {
            //上一次频率中删除当前键
            freq_table[freq].Remove(cur);
            //如果链表为空，删除键
            if (freq_table[freq].Count == 0)
            {
                freq_table.Remove(freq);
                if (min == freq) min++;
            }
          
            var newnode = new Node() { val = val, freq = freq + 1, key = cur.key };
            if (!freq_table.ContainsKey(freq + 1))
            {
                freq_table[freq + 1] = new LinkedList<Node>();
            }
            freq_table[freq + 1].AddFirst(newnode);
             key_table[key] = newnode;
        }
        return val;
    }
    
    public void Put(int key, int value) {
        if (cap == 0) return;
        //当前键不存在，判断缓存是否已满，满了淘汰最少使用的键
        if (!key_table.ContainsKey(key))
        {
            //缓存已满
            if (key_table.Count == cap)
            {
                 //需要淘汰的数据
                var last = freq_table[min].Last;
                //缓存淘汰
                key_table.Remove(last.Value.key);
                //频率淘汰
                freq_table[min].RemoveLast();
                
                if (freq_table[min].Count == 0)
                {
                    freq_table.Remove(min);
                }
              
            }
            var newnode = new Node() { val = value, key = key, freq = 1 };
            if (!freq_table.ContainsKey(1))
            {
                freq_table[1] = new LinkedList<Node>();
            }
            freq_table[1].AddFirst(newnode);
            key_table[key] = newnode;
            min = 1;
        }
        else
        {
            //键存在，更新缓存，更新频率
            var cur = key_table[key];
            int freq = cur.freq;
            var newnode = new Node() { val = value, key = key, freq = freq + 1 };
            if (freq_table.ContainsKey(freq))
            {
                 //上一次频率中删除当前键
                 freq_table[freq].Remove(cur);
                //如果链表为空，删除键
                if (freq_table[freq].Count == 0)
                {
                    freq_table.Remove(freq);
                    if (min == freq) min++;
                }
            }
            if (!freq_table.ContainsKey(freq + 1))
            {
                freq_table[freq + 1] = new LinkedList<Node>();
            }
            freq_table[freq + 1].AddFirst(newnode);
            key_table[key] = newnode;
        }
    }
}
    public class Node
    {
        public int val { get; set; }
        public int key { get; set; }
        public int freq { get; set; }
    }
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
```