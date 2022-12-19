```
public class RandomizedCollection
{
    private int _count;

    private int _capacity;

    private readonly Random _rand;

    private CollectionItemEntry[] _items;

    private readonly Dictionary<int, CollectionItemEntry> _map;

    /** Initialize your data structure here. */
    public RandomizedCollection()
    {
        _count = 0;
        _capacity = 8;
        _map = new Dictionary<int, CollectionItemEntry>();
        _items = new CollectionItemEntry[_capacity];
        _rand = new Random(DateTime.Now.Ticks.GetHashCode());
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public bool Insert(int val)
    {
        ExpandIfNeed();

        var item = new CollectionItemEntry()
        {
            Value = val,
            Index = _count
        };

        item.Prev = item;
        item.Next = item;

        if (_map.TryGetValue(val, out var head))
        {
            if (head.Prev == head)
            {
                head.Prev = item;
                head.Next = item;
                item.Prev = head;
                item.Next = head;
            }
            else
            {
                head.Prev.Next = item;
                item.Prev = head.Prev;

                head.Prev = item;
                item.Next = head;
            }

            _items[_count++] = item;
            return false;
        }

        _map[val] = item;
        _items[_count++] = item;
        return true;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    //按添加顺序删
    public bool Remove(int val)
    {
        if (!_map.TryGetValue(val, out var head))
        {
            return false;
        }

        if (head.Index == _count - 1)
        {
            _items[head.Index] = null;
        }
        else
        {
            _items[head.Index] = _items[_count - 1];
            _items[head.Index].Index = head.Index;
        }

        if (head.Prev == head)
        {
            _map.Remove(val);
        }
        else
        {
            head.Prev.Next = head.Next;
            head.Next.Prev = head.Prev;
            _map[val] = head.Next;
        }

        _count--;
        return true;
    }

    /** Get a random element from the collection. */
    public int GetRandom()
    {
        if (_count == 0)
        {
            return -1;
        }

        return _items[_rand.Next(0, _count)].Value;
    }

    //expand
    private void ExpandIfNeed()
    {
        if (_count == _capacity)
        {
            var items = _items;

            _capacity *= 2;

            _items = new CollectionItemEntry[_capacity];

            Array.Copy(items, _items, items.Length);
        }
    }

    private class CollectionItemEntry
    {
        public int Index;

        public int Value;

        public CollectionItemEntry Prev;

        public CollectionItemEntry Next;
    }
}
```
