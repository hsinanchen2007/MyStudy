### 解题思路
堆栈记录压入数据顺序
字典记录每个数字出现频率
大heap对数字根据频率排序，记录每个数字在heap中的位置

从堆栈尾部遍历，找到第一个出现频率和heap顶频率相同的数据，移除
修正三个数据结构


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

public class FreqStack {
    private List<int> stack = new List<int> ();
    private Dictionary<int, int> freq = new Dictionary<int, int> ();
    private IndexHeap<int> heap;
    public FreqStack () {
        //频率越大越优先
        heap = new IndexHeap<int> ((a, b) => {
            return freq[b] - freq[a];
        });
    }

    public void Push (int x) {
        stack.Add (x);
        freq.TryAdd (x, 0);
        freq[x]++;
        //重新排序
        heap.RemoveIndex (x);
        heap.Insert (x);
        //Console.WriteLine("Stack:" + JsonSerializer.Serialize(stack));
        //Console.WriteLine("Stack:" + JsonSerializer.Serialize(heap.list));
        //Console.WriteLine("Heap:" + ObjectDumper.Dump(heap.objIndex));
        //Console.WriteLine("Stack:" + ObjectDumper.Dump(freq));
    }

    public int Pop () {
        var fir = heap.First();
        var retVal = 0;
        for (var i = stack.Count - 1; i >= 0; i--){
            // if(allSameFreqNum.ContainsKey(stack[i])){//删除这个元素
            if(freq[stack[i]] == freq[fir]){
                var val = stack[i];
                retVal = val;
                stack.RemoveAt(i);
                heap.RemoveIndex(val);
                freq[val]--;
                if(freq[val] == 0){
                    freq.Remove(val);
                }else {
                    heap.Insert(val); //重新排序到heap中
                }
                break;
            }
        }
        //Console.WriteLine("Pop:" + JsonSerializer.Serialize(stack));
        //Console.WriteLine("Stack:" + JsonSerializer.Serialize(heap.list));
        //Console.WriteLine("PopHeap:" + ObjectDumper.Dump(heap.objIndex));
        //Console.WriteLine("Stack:" + ObjectDumper.Dump(freq));
        return retVal;
    }

    // static void Main(string[] arg)
    // {
    //     var l = File.ReadAllLines("testOp.json");
    //     var ops = JsonSerializer.Deserialize<string[]>(l[0]);
    //     var d = JsonSerializer.Deserialize<int[][]>(l[1]);
        
    //     var fs = new FreqStack();
    //     for (var i = 1; i < ops.Length; i++){
    //         if(ops[i] == "push"){
    //             fs.Push(d[i][0]);
    //         }else {
    //             var v = fs.Pop();
    //             Console.WriteLine("P:" + v);
    //         }
    //     }
    //     // fs.Push()
    // }
}
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.Push(x);
 * int param_2 = obj.Pop();
 */
```