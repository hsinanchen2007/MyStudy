### 解题思路
给c#的小伙伴分享

### 代码

```csharp
public class LRUCache {

        private Dictionary<int, LinkedNode> dic;
        private int capacity;
        private LinkedNode head;
        private LinkedNode tail;
        private int count;

        public class LinkedNode
        {
            public LinkedNode pre;
            public LinkedNode next;
            public int key;
            public int value;
        }

        public LRUCache(int capacity)
        {
            dic = new Dictionary<int, LinkedNode>();
            this.capacity = capacity;

            head = new LinkedNode();
            tail = new LinkedNode();
            head.next = tail;
            tail.pre = head;
            this.count = 0;
        }

        private void AddToHead(LinkedNode node)
        {
            node.pre = head;
            node.next = head.next;

            head.next.pre = node;
            head.next = node;
        }

        private void DelectNode(LinkedNode node)
        {
            node.pre.next = node.next;
            node.next.pre = node.pre;
        }

        private LinkedNode DelectFromTail()
        {
            var node = tail.pre;
            DelectNode(node);
            return node;
        }
        

        public int Get(int key)
        {
            if (dic.ContainsKey(key))
            {
                var node = dic[key];
                DelectNode(node);
                AddToHead(node);
                return node.value;
            }
            else
                return -1;
        }

        public void Put(int key, int value)
        {         
            if (dic.ContainsKey(key))
            {
                var node = dic[key];
                node.value = value;

                DelectNode(node);
                AddToHead(node);
            }
            else
            {
                var node = new LinkedNode();
                node.value = value;
                node.key = key;
                dic.Add(key, node);

                if (count < capacity)
                {
                    AddToHead(node);
                    count++;
                }
                else
                {
                    var delectNode = DelectFromTail();
                    dic.Remove(delectNode.key);
                    AddToHead(node);
                }

            }
                
        }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
```