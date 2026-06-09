### 解题思路
当确定一个 最低Effect时， 最大performance 是 k-1个最大Speed 
可以用heap 压入k-1个
每次下一个数字时，剔除掉当前小于  最小Effect的元素

### 代码

```csharp
using VT = System.ValueTuple<int, System.Int64, System.Int64, int>;

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



class SE{
    public Int64 s, e;
    public int sortIndex = -1;
}
class MaxAll2
{
    private Int64 MODV = 1000000000 + 7;
    List<SE> ls;
    List<SE> ls2;
    private Dictionary<VT, Int64> cache = new Dictionary<VT, Int64>();
    public int total = 0;
    private Int64 MaxP(int start, Int64 curSum, Int64 curMin, int leftK){
        total++;
        if(start >= ls.Count || leftK == 0){
            return (curSum * curMin) % MODV;
        }
        var key = (start, curSum, curMin, leftK);
        if(cache.ContainsKey(key)) return cache[key];
        var v = ls[start];
        var m1 = MaxP(start + 1, (curSum + v.s)%MODV, Math.Min(curMin, v.e), leftK-1);
        var m2 = MaxP(start + 1, curSum, curMin, leftK);
        var mv = Math.Max(m1, m2);
        cache.Add(key, mv);
        return mv;
    }

    private Int64 MaxPGreed(int k){
        Int64 curMax = 0;
        if(k == 1){
            foreach(var s in ls){
                var v = s.e * s.s;
                curMax = Math.Max(curMax, v);
            }
            return curMax % MODV;
        }

        //尽量sortIndex 前的更新 effect 小的剔除
        var heap = new Heap<SE>((a, b)=>{
            if (a.e != b.e)
            {
                return Math.Sign(a.e - b.e);
            }else {
                return a.sortIndex - b.sortIndex;
            }
        });
        //初始后面K个肯定 e都大于 
        var lastJ = -1;
        Int64 heapSum = 0;
        for (var i = 0; i < ls.Count; i++)
        {
            var curMin = ls[i];
            var n = 1+heap.Count;
            Int64 curSum = curMin.s+heapSum;
            while(heap.Count > 0){
                var fir = heap.First();
                if(fir.e < curMin.e){
                    heap.Remove();
                    curSum -= fir.s;
                    heapSum -= fir.s;
                    n--;
                }else if(fir.e == curMin.e && fir == curMin) {
                    heap.Remove();
                    curSum -= fir.s;
                    heapSum -= fir.s;
                    n--;
                }else break;
            }

            //  % MODV;
            for (var j = lastJ+1; j < ls2.Count && n < k; j++)
            {
                lastJ = j;
                // if(ls2[j].sortIndex > curMin.sortIndex){
                if (ls2[j].e >= curMin.e && ls2[j] != curMin)
                {
                    curSum += ls2[j].s;
                    heapSum += ls2[j].s;
                    // curSum %= MODV;
                    heap.Insert(ls2[j]);
                    n++;
                }
                if (n == k) break;
            }
            // //Console.WriteLine("CurMin:"+ObjectDumper.Dump(curMin)+":"+curSum);
            curSum *= curMin.e;
            // curSum %= MODV;
            // //Console.WriteLine("Ret:" + curMax + ":"+curSum);
            curMax = Math.Max(curMax, curSum);
        }
        return curMax % MODV;
    }
    public int MaxPerformance(int n, int[] speed, int[] efficiency, int k)
    {
        ls = new List<SE>();
        ls2 = new List<SE>();
        for (var i = 0; i < n; i++)
        {
            var se = new SE()
            {
                s = (Int64)speed[i],
                e = (Int64)efficiency[i],
            };
            ls.Add(se);
        }
        ls.Sort((a, b) =>
        {
            // var s = Math.Sign((b.s * b.e) - (a.s * a.e));
            // return s;
            //尽量选择剔除自己的？
            return Math.Sign(a.e - b.e);//最低效率 和最大
        });
        for (var i = 0; i < ls.Count; i++){
            ls[i].sortIndex = i;
        }
        ls2.AddRange(ls);
        ls2.Sort((a, b) =>
        {
            return Math.Sign(b.s - a.s);//速度大的优先
        });
        //Console.WriteLine(ObjectDumper.Dump(ls));
        //Console.WriteLine("#############");
        //Console.WriteLine(ObjectDumper.Dump(ls2));
        // return (int)MaxP(0, 0, Int32.MaxValue, k);
        return (int)MaxPGreed(k);
    }
}

public class Solution {
    public int MaxPerformance(int n, int[] speed, int[] efficiency, int k) {
        var ma = new MaxAll2();
        return ma.MaxPerformance(n, speed, efficiency, k);
    }
}
```