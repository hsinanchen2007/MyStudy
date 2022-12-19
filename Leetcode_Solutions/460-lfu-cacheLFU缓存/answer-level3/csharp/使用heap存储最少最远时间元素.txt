### 解题思路
使用heap排序


### 代码

```csharp
public class IndexHeap<T> {

    public List<T> list;
    public delegate int CompareDelegate (T v1, T v2);
    CompareDelegate compare = Comparer<T>.Default.Compare;
    public Dictionary<T, int> objIndex = new Dictionary<T, int> ();

    public IndexHeap (CompareDelegate compare) : this () {
        this.compare = compare;
    }

    public IndexHeap () {
        list = new List<T> ();
    }

    public int Count {
        get { return list.Count; }
    }

    public void Insert (T value) {
        int index = list.Count;
        list.Add (value);
        //保证唯一
        objIndex.Add(value, list.Count-1);
        int parentIndex = ParentIndex (index);
        while (index > 0 && compare (list[index], list[parentIndex]) < 0) {
            var pv = list[parentIndex];
            var cv = list[index];
            objIndex[pv] = index;
            objIndex[cv] = parentIndex;
            Swap (index, parentIndex);
            index = parentIndex;
            parentIndex = ParentIndex (index);
        }
    }

    public T Remove () {
        if (list.Count == 0) throw new ArgumentOutOfRangeException ("Cannot remove Element from empty Heap");
        T value = list[0];
        objIndex.Remove(value);
        list[0] = list[list.Count - 1];
        list.RemoveAt (list.Count - 1);
        if(list.Count > 0){
            objIndex[list[0]] = 0;
        }
        Heapify (0);
        return value;
    }
    public T RemoveIndex (T obj) {
        if (!objIndex.ContainsKey (obj)) return default (T);
        var ind = objIndex[obj];
        T value = list[ind];
        //Console.WriteLine("RemoveIndex:" + ind+":"+value+":"+obj);
        objIndex.Remove(value);

        list[ind] = list[list.Count - 1];
        list.RemoveAt(list.Count - 1);
        //最后一个元素移除
        if(list.Count > ind){
            objIndex[list[ind]] = ind;
        }else {
            return value;
        }
        //没有比较元素了
        if(list.Count <= 1) return value;
        //有父亲元素
        if (ind > 0)
        {
            var parNode = ParentIndex(ind);
            var pv = list[parNode];
            var newV = list[ind];
            var isS = compare(newV, pv);
            if(isS < 0) {//向上移动
                var parentIndex = ParentIndex(ind);
                while (ind > 0 && compare (list[ind], list[parentIndex]) < 0) {
                    var pVV = list[parentIndex];
                    var cv = list[ind];
                    objIndex[pVV] = ind;
                    objIndex[cv] = parentIndex;
                    Swap (ind, parentIndex);
                    ind = parentIndex;
                    parentIndex = ParentIndex (ind);
                }
            }else{
                Heapify(ind);//比父亲> 向下移动
            }
        }else
        {
            Heapify(ind);//可能向上 也可能向下
        }
        return value;
    }
    public T First () {
        return list[0];
    }

    // public static IndexHeap<T> FromList (List<T> list, CompareDelegate compare) {
    //     Heap<T> H = new Heap<T> (compare);
    //     if (list.Count == 0) return H;
    //     H.list = list;
    //     for (int i = list.Count / 2 - 1; i >= 0; i--)
    //         H.Heapify (i);
    //     return H;
    // }

    // public static Heap<T> FromList (List<T> list) {
    //     return FromList (list, Comparer<T>.Default.Compare);
    // }

    private void Heapify (int index) {
        while (index < list.Count) {

            int leftChildIndex = LeftChildIndex (index);
            if (leftChildIndex >= list.Count) break;

            int childIndex = leftChildIndex;
            int rightChildIndex = RightChildIndex (index);
            if (rightChildIndex < list.Count && compare (list[rightChildIndex], list[leftChildIndex]) < 0) {
                childIndex = rightChildIndex;
            }
            if (compare (list[index], list[childIndex]) < 0) break;
            var cv = list[childIndex];
            var pv = list[index];
            objIndex[cv] = index;
            objIndex[pv] = childIndex;
            Swap (index, childIndex);
            index = childIndex;
        }
    }

    public static int ParentIndex (int index) { return (index - 1) / 2; }
    public static int LeftChildIndex (int index) { return index * 2 + 1; }
    public static int RightChildIndex (int index) { return index * 2 + 2; }

    private void Swap (int i1, int i2) {
        T temp = list[i1];
        list[i1] = list[i2];
        list[i2] = temp;
    }
}

public class LFUCache {
    private Dictionary<int, int> usedNums = new Dictionary<int, int>();
    private Dictionary<int, int> lastUsedTime = new Dictionary<int, int>();
    private Dictionary<int, int> valueDic = new Dictionary<int, int>();
    private IndexHeap<int> heap;//最少 最远
    private int usedTime = 0;
    private int cap;
    public LFUCache(int capacity) {
        cap = capacity;
        heap = new IndexHeap<int>((a, b) =>
        {
            var ua = usedNums[a];
            var ub = usedNums[b];
            //次数相等 返回 最古老的
            if(ua == ub) return lastUsedTime[a] - lastUsedTime[b];
            return ua - ub;
        });
    }
    
    public int Get(int key) {
        usedTime++;
        if(!valueDic.ContainsKey(key)) {
            return -1;
        }
        heap.RemoveIndex(key);
        usedNums[key]++;
        lastUsedTime[key] = usedTime;
        heap.Insert(key);
        return valueDic[key];
    }
    
    public void Put(int key, int value) {
        usedTime++;
        if(cap == 0) return;
        //删除掉最少 tie 最久之前使用 新增key
        if(valueDic.Count >= cap && !valueDic.ContainsKey(key)){
            var fir = heap.Remove();//移除掉第一个
            usedNums.Remove(fir);
            lastUsedTime.Remove(fir);
            valueDic.Remove(fir);
        }
        heap.RemoveIndex(key);
        usedNums.TryAdd(key, 0);
        usedNums[key]++;
        lastUsedTime[key] = usedTime;
        valueDic[key] = value;
        heap.Insert(key);
    }
    // static void Main(string[] arg)
    // {
    //     var lfu = new LFUCache(0);
    //     var ir = 0;
    //     // lfu.Put(1, 1);
    //     // lfu.Put(2, 2);
    //     // ir = lfu.Get(1);
    //     // Console.WriteLine(ir);
    //     // lfu.Put(3, 3);
    //     // ir = lfu.Get(2);
    //     // Console.WriteLine(ir);
    //     lfu.Put(0, 0);
    //     ir = lfu.Get(0);
    //     Console.WriteLine(ir);
    // }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.Get(key);
 * obj.Put(key,value);
 */
```