没找到标准库中提供的优先级队列，只好自己实现一个，如果有人知道请分享一下，感激不尽！
```
public class MedianFinder {

  class Heap<T> {
    private List<T> list;
    private Func<T, T, int> comparer;
    internal Heap(Func<T, T, int> comparer) {
      this.list = new List<T>();
      this.comparer = comparer;
    }
    internal int Count { get => this.list.Count; }

    private bool PriorThan(int i, int j) {
      return this.comparer(this.list[i], this.list[j]) < 0;
    }
    private void SwapByIndex(int i, int j) {
      var temp = this.list[i];
      this.list[i] = this.list[j];
      this.list[j] = temp;
    }

    internal void En(T v) {
      // 添加到末尾
      this.list.Add(v);
      // 调整堆结构
      int curI = this.list.Count - 1;
      int parentI = this.list.Count / 2 - 1;
      while (curI > 0) {
        if (this.PriorThan(curI, parentI)) {
          this.SwapByIndex(curI, parentI);
          curI = parentI;
          parentI = (curI + 1) / 2 - 1;
        } else {
          break;
        }
      }
    }
    internal T De() {
      // 取堆顶
      T result = this.list[0];
      // 调整堆结构
      this.list[0] = this.list[this.list.Count - 1];
      this.list.RemoveAt(this.list.Count - 1);
      int curI = 0;
      while (curI < this.list.Count) {
        int leftChildI = curI * 2 + 1;
        int rightChildI = leftChildI + 1;
        int nextI = curI;
        if (leftChildI < this.list.Count) nextI = this.PriorThan(leftChildI, curI) ? leftChildI : curI;
        if (rightChildI < this.list.Count) nextI = this.PriorThan(rightChildI, nextI) ? rightChildI : nextI;
        if (nextI == curI) break;
        else {
          this.SwapByIndex(curI, nextI);
          curI = nextI;
        }
      }
      // 返回堆顶
      return result;
    }
    internal T Peek() {
      return this.list[0];
    }
  }

  Heap<int> minHeap = null;
  Heap<int> maxHeap = null; // 保持大堆元素数等小堆，或者比小堆多一
  bool isOdd = false;

  /** initialize your data structure here. */
  public MedianFinder() {
    this.minHeap = new Heap<int>((a, b) => (a - b));
    this.maxHeap = new Heap<int>((a, b) => (b - a));
  }

  public void AddNum(int num) {
    if (this.isOdd) {
      this.maxHeap.En(num);
      this.minHeap.En(this.maxHeap.De());
    } else {
      this.minHeap.En(num);
      this.maxHeap.En(this.minHeap.De());
    }
    this.isOdd = !this.isOdd;
  }

  public double FindMedian() {
    return this.isOdd ? this.maxHeap.Peek() : ((double) (this.maxHeap.Peek() + this.minHeap.Peek())) / 2;
  }
}
```
