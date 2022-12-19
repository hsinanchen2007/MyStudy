## 自己很菜第一想法
```csharp
public class LRUCache
{
    private List<int> Keys;
    private Dictionary<int, int> a;


    public LRUCache(int capacity)
    {
        Keys = new List<int>(capacity);
        a = new Dictionary<int, int>(capacity);
    }

    public int Get(int key)
    {
        int resValue;
        if (a.TryGetValue(key, out resValue))
        {
            Keys.RemoveAt(Keys.IndexOf(key));
            Keys.Add(key);
            return resValue;
        }
        else
            return -1;
    }

    public void Put(int key, int value)
    {
        int Value = 0;
        a.TryGetValue(key,out Value);
        if (Value != 0)
        {
            a[key] = value;
            Keys.RemoveAt(Keys.IndexOf(key));
            Keys.Add(key);
        }
        else if (Keys.Count != Keys.Capacity)
        {
            Keys.Add(key);
            a.Add(key, value);
        }
        else
        {
            a.Remove(Keys[0]);
            Keys.RemoveAt(0);
            Keys.Add(key);
            a.Add(key, value);
        }
    }
}
```

## 小的总结

本题的要求让我想到了之前做过的辅助栈与数据栈，我想的是一个列表储存键的排序，另一个字典储存键值对。之后看了官方的双向链表加哈希的方法，是满足进阶的要求。发现题解没有C#的，于是移植到C#上稍加改进，然后顺手发了一个C#的题解，如下。

## 官方题解
```csharp
public class LRUCache
{
    class DLinkedNode
    {
        public int key;
        public int value;
        public DLinkedNode prev;
        public DLinkedNode next;
    }

    private void addNode(DLinkedNode node)
    {
        //将新的node加入在头部的后面
        node.prev = head;
        node.next = head.next;

        head.next.prev = node;
        head.next = node;
    }

    private void removeNode(DLinkedNode node)
    {
        //从链表中移除一个node
        DLinkedNode prev = node.prev;
        DLinkedNode next = node.next;

        prev.next = next;
        next.prev = prev;
    }

    private void moveToHead(DLinkedNode node)
    {
        //将一个node移到队头
        removeNode(node);
        addNode(node);
    }

    private DLinkedNode popTail()
    {
        //移除当前队尾的元素
        DLinkedNode res = tail.prev;
        removeNode(res);
        return res;
    }

    private Hashtable cache = new Hashtable();
    private int size;
    private int capacity;
    private DLinkedNode head, tail;

    public LRUCache(int capacity)
    {
        this.size = 0;
        this.capacity = capacity;

        head = new DLinkedNode();
        // head.prev = null;

        tail = new DLinkedNode();
        // tail.next = null;

        head.next = tail;
        tail.prev = head;
    }

    public int Get(int key)
    {
        DLinkedNode node = (DLinkedNode)cache[key];
        if (node == null) return -1;

        // 将已存在的node移到队头
        moveToHead(node);

        return node.value;
    }

    public void Put(int key, int value)
    {
        DLinkedNode node = (DLinkedNode)cache[key];

        if (node == null)
        {
            DLinkedNode newNode = new DLinkedNode();
            newNode.key = key;
            newNode.value = value;

            cache.Add(key, newNode);
            addNode(newNode);

            ++size;

            if (size > capacity)
            {
                //移除队尾元素
                DLinkedNode tail = popTail();
                cache.Remove(tail.key);
                --size;
            }
        }
        else
        {
            // 更新node的值并移到队头
            node.value = value;
            moveToHead(node);
        }
    }
}
```
![image.png](https://pic.leetcode-cn.com/2fc6ee49b726b12eb5c4f3bf6d31ccb0f73603164a76cb1a60c007df36ac0e1f-image.png)
