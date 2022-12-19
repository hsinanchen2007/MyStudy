### 解题思路
并查集合并水池
每个水池根据边界统一增长高度

### 代码

```csharp

public class Heap<T> {

    public List<T> list;
    public delegate int CompareDelegate (T v1, T v2);
    CompareDelegate compare = Comparer<T>.Default.Compare;

    public Heap (CompareDelegate compare) : this () {
        this.compare = compare;
    }

    public Heap () {
        list = new List<T> ();
    }

    public int Count {
        get { return list.Count; }
    }

    public void Insert (T value) {
        int index = list.Count;
        list.Add (value);
        int parentIndex = ParentIndex (index);
        while (index > 0 && compare (list[index], list[parentIndex]) < 0) {
            Swap (index, parentIndex);
            index = parentIndex;
            parentIndex = ParentIndex (index);
        }
    }

    public T Remove () {
        if (list.Count == 0) throw new ArgumentOutOfRangeException ("Cannot remove Element from empty Heap");
        T value = list[0];
        list[0] = list[list.Count - 1];
        list.RemoveAt (list.Count - 1);
        Heapify (0);
        return value;
    }
    public T First () {
        return list[0];
    }

    public static Heap<T> FromList (List<T> list, CompareDelegate compare) {
        Heap<T> H = new Heap<T> (compare);
        if (list.Count == 0) return H;
        H.list = list;
        for (int i = list.Count / 2 - 1; i >= 0; i--)
            H.Heapify (i);
        return H;
    }

    public static Heap<T> FromList (List<T> list) {
        return FromList (list, Comparer<T>.Default.Compare);
    }

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




enum DropState {
    Wait, 
    Sink,
    InPool,
}
class DropPool {
    public int pointNum = 0;
    public int poolHeight = 0;
    public DropPool parent = null;
    public DropState state = DropState.Wait;
    public HashSet<int> outBound = new HashSet<int>();
    public Heap<int> boundHeap = new Heap<int>((a, b) =>
        {
            return OneDWater.drops[a].curHeight - OneDWater.drops[b].curHeight;
        });
    public DropPool GetTopParent(){
        if (parent == null) return this;
        var p = parent.parent;
        var c = parent;
        while (p != null)
        {
            c = p;
            p = p.parent;
        }
        if (c != this) this.parent = c;
        return c;
    }
    public static void MergePool(DropPool p1, DropPool p2)
    {
        var pp1 = p1.GetTopParent();
        var pp2 = p2.GetTopParent();
        if (pp1 != pp2)
        {
            pp2.parent = pp1;
            var inSink = pp1.state == DropState.Sink || pp2.state == DropState.Sink;
            pp1.state = inSink ? DropState.Sink : pp1.state;
            pp2.state = inSink ? DropState.Sink : pp2.state;
            if (pp1.state == DropState.Sink) return;
            pp1.pointNum += pp2.pointNum;
            foreach (var b in pp2.outBound)
            {
                var r = OneDWater.drops[b];
                if(r.state == DropState.InPool && r.pool.GetTopParent() == pp1){
                }else
                {
                    pp1.outBound.Add(b);
                    pp1.boundHeap.Insert(b);
                }
            }
        }
    }
    public bool TryIncreaseHeight()
    {
        if (state == DropState.Sink) return false;
        var bh = boundHeap.First();
        var lowB = OneDWater.drops[bh];
        if (lowB.state == DropState.Sink)
        {
            state = DropState.Sink;
            return false;
        }
        if(lowB.state == DropState.InPool){
            if(lowB.pool.GetTopParent() == this.GetTopParent()){
                boundHeap.Remove(); 
                return true;
            }
            if(lowB.curHeight <= poolHeight && lowB.pool.GetTopParent().state == DropState.Sink){
                GetTopParent().state = DropState.Sink;
                return false;
            } 
        }
        if (lowB.curHeight < poolHeight) return false;
        if (lowB.curHeight > poolHeight)
        {
            var delta = lowB.curHeight - poolHeight;
            OneDWater.totalAddV += delta * pointNum;
            poolHeight = lowB.curHeight;
            AddMinBound();
            return true;
        }
        AddMinBound();
        return true;
    }
    private void AddMinBound()
    {
        var bh = boundHeap.Remove();
        var lowB = OneDWater.drops[bh];
        if (lowB.state == DropState.Sink)
        {
            state = DropState.Sink;
            return;
        }
        if (lowB.state == DropState.InPool)
        {
            MergePool(this, lowB.pool);
            return;
        }
        if (lowB.curHeight == poolHeight)
        {
            AddOnePoint(lowB); //空闲边界加入到我的池子里面
        }
    }
    public int seedPoint;
    public void AddOnePoint(OneDrop p)
    {
        if (pointNum == 0)
        {
            seedPoint = p.x;
            poolHeight = p.curHeight;
        }
        p.state = DropState.InPool;
        p.pool = this.GetTopParent();
        pointNum++;
        var openQueue = new Queue<OneDrop>();
        openQueue.Enqueue(p);
        while (openQueue.Count > 0)
        {
            var f = openQueue.Dequeue();
            foreach (var n in f.nc)
            {
                if (n.state == DropState.Sink)
                {
                    this.state = DropState.Sink;
                    GetTopParent().state = DropState.Sink;
                }
                else if (n.state == DropState.InPool) //邻居在另外一个池子里面
                { //合并两个Pool 我的Parent = otherParent
                    if (n.pool.GetTopParent() != GetTopParent())
                    {
                        if (n.curHeight == this.poolHeight)
                        { //合并两个Pool
                            MergePool(this, n.pool);
                        }
                        else
                        { //加入到自己的BOund中 如果高度比我低 则我不能增长 如果高度比我高 则 我可以增长 高度相同则扩张
                            outBound.Add(n.GetKey());
                            boundHeap.Insert(n.GetKey());
                        }
                    }
                }
                else
                { //空闲的点
                    if (n.curHeight != poolHeight)
                    {
                        outBound.Add(n.GetKey());
                        boundHeap.Insert(n.GetKey());
                    }
                    else
                    {
                        pointNum++;
                        n.pool = this.GetTopParent();
                        n.state = DropState.InPool;
                        openQueue.Enqueue(n);
                    }
                }
            }
        }
    }
}
class OneDrop{
    public int x;
    public int GetKey(){
        return x;
    }
    public int initHeight = 0;
    public DropState state = DropState.Wait;
    public List<OneDrop> nc;
    public DropPool pool;
    public void Init(){
        var neib = new List<int>()
        {
            x-1,
            x+1,
        };
        nc = new List<OneDrop>();
        foreach(var n in neib){
            if(OneDWater.drops.ContainsKey(n)){
                nc.Add(OneDWater.drops[n]);
            }
        }
    }
    public int curHeight{
        get
        {
            if (state == DropState.Wait || state == DropState.Sink) return initHeight;
            return pool.GetTopParent().poolHeight;
        }
    }
}
class OneDWater {
    public static Dictionary<int, OneDrop> drops;
    public static int totalAddV;
    public int Trap(int[] height) {
        drops = new Dictionary<int, OneDrop>();
        totalAddV = 0;
        if (height.Length == 0) return 0;
        var s1 = new OneDrop()
        {
            x = -1,
            initHeight = 0,
            state = DropState.Sink,
        };
        drops.Add(-1, s1);
        var s2 = new OneDrop()
        {
            x = height.Length,
            initHeight = 0,
            state = DropState.Sink,
        };
        drops.Add(s2.x, s2);

        for (var i = 0; i < height.Length; i++){
            var od = new OneDrop()
            {
                x = i,
                initHeight = height[i],
                state = DropState.Wait,
            };
            drops.Add(od.x, od);
        }
        foreach(var d in drops){
            d.Value.Init();
        }

        var ls = drops.Values.ToList();
        ls.Sort((a, b) =>
        {
            var ah = a.curHeight;
            var bh = b.curHeight;
            if (a.state == DropState.Sink) ah = Int32.MaxValue;
            if (b.state == DropState.Sink) bh = Int32.MaxValue;
            return ah - bh;
        });
        foreach(var p in ls){
            if(p.state == DropState.Wait){
                var newPool = new DropPool();
                newPool.AddOnePoint(p);
                var ret = true;
                while(newPool.GetTopParent().state == DropState.Wait && ret){
                   ret = newPool.GetTopParent ().TryIncreaseHeight (); 
                }
            }
        }
        return totalAddV;
    }
}
public class Solution {
    public int Trap(int[] height) {
        var od = new OneDWater();
        return od.Trap(height);
    }
}
```