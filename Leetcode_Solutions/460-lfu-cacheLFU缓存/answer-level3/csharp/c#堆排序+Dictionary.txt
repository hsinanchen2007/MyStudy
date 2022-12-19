### 解题思路

### 代码

```csharp
class Heap<T>
{
    List<T> list = new List<T>();
    int listCount = 0;

    System.Func<T, T, bool> f;
    System.Action<T, int> setIndexCallback;

    public Heap(System.Func<T, T, bool> _f, System.Action<T, int> _setIndexCallback)
    {
        f = _f;
        setIndexCallback = _setIndexCallback;
    }

    public void Add(T t)
    {
        if (listCount < list.Count)
        {
            list[listCount] = t;
        }
        else
        {
            list.Add(t);    
        }
        
        listCount++;
        
        if(setIndexCallback != null)
        {
            setIndexCallback(t, listCount - 1);
        }

        ShiftUp(listCount - 1);
    }

    public int Count()
    {
        return listCount;
    }

    public T Top()
    {
        if (listCount > 0)
        {
            return list[0];
        }

        return default(T);
    }

    public T Pop()
    {
        if (listCount > 0)
        {
            T t = list[0];
            list[0] = list[listCount - 1];
            listCount--;

            if(setIndexCallback != null)
            {
                setIndexCallback(list[0], 0);
            }

            ShiftDown(0);
            return t;
        }

        return default(T);
    }

    public void ShiftUp(int childIndex)
    {
        if (childIndex == 0)
        {
            return;
        }

        int parentIndex = (childIndex - 1) / 2;
        if (!f(list[parentIndex], list[childIndex]))
        {
            T t = list[parentIndex];
            list[parentIndex] = list[childIndex];
            list[childIndex] = t;

            if(setIndexCallback != null)
            {
                setIndexCallback(list[parentIndex], parentIndex);
                setIndexCallback(list[childIndex], childIndex);
            }

            ShiftUp(parentIndex);
        }
    }

    public void ShiftDown(int parentIndex)
    {
        int childIndex1 = parentIndex * 2 + 1;
        int childIndex2 = parentIndex * 2 + 2;

        int tempIndex = 0;
        if (childIndex1 < listCount)
        {
            if (childIndex2 < listCount)
            {
                if (f(list[childIndex1], list[childIndex2]))
                {
                    tempIndex = childIndex1;
                }
                else
                {
                    tempIndex = childIndex2;
                }
            }
            else
            {
                tempIndex = childIndex1;
            }
        }
        else if (childIndex2 < listCount)
        {
            tempIndex = childIndex2;
        }
        else
        {
            return;
        }

        if (!f(list[parentIndex], list[tempIndex]))
        {
            T t = list[parentIndex];
            list[parentIndex] = list[tempIndex];
            list[tempIndex] = t;

            if(setIndexCallback != null)
            {
                setIndexCallback(list[parentIndex], parentIndex);
                setIndexCallback(list[tempIndex], tempIndex);
            }

            ShiftDown(tempIndex);
        }
    }
}

public class ValueInfo
{
    public int heapIndex;
    public int key;
    public int value;
    public int usedCount;
    public int lastUsedTime;
}

public class LFUCache {
    int capacity;
    int lastUsedTime = 1;
    Dictionary<int, ValueInfo> map = new Dictionary<int, ValueInfo>();
    Heap<ValueInfo> heap;

    void SetHeapIndex(ValueInfo info, int index)
    {
        info.heapIndex = index;
    }

    bool small(ValueInfo a, ValueInfo b)
    {
        if(a.usedCount < b.usedCount)
        {
            return true;
        } 

        if(a.usedCount == b.usedCount)
        {
            return a.lastUsedTime < b.lastUsedTime;
        }

        return false;
    }

    public LFUCache(int capacity) {
        heap = new Heap<ValueInfo>(small, SetHeapIndex);
        this.capacity = capacity;
    }
    
    public int Get(int key) {
        ValueInfo info = null;
        if(map.TryGetValue(key, out info))
        {
            info.usedCount++;
            info.lastUsedTime = lastUsedTime++;
            heap.ShiftDown(info.heapIndex);

            return info.value;
        }
        else
        {
            return -1;
        }
    }
    
    public void Put(int key, int value) {
        ValueInfo oldInfo = null;
        if(this.map.TryGetValue(key, out oldInfo))
        {
            oldInfo.value = value;
            oldInfo.usedCount++;
            oldInfo.lastUsedTime = lastUsedTime++;
            
            heap.ShiftDown(oldInfo.heapIndex);

            return;
        }

        if(this.map.Count >= capacity)
        {
            if(capacity <= 0)
            {
                return;
            }
            
            ValueInfo popInfo = heap.Pop();
            map.Remove(popInfo.key);
        }

        ValueInfo info = new ValueInfo();
        info.key = key;
        info.value = value;
        info.lastUsedTime = lastUsedTime++;

        map.Add(key, info);
        heap.Add(info);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
```