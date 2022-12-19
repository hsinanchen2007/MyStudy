### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
if(k == arr.length)
{
return arr;
}
if(k==0){return new int[0];}
Queue<Integer> heap = new PriorityQueue<>(k, (i1, i2) -> Integer.compare(i2, i1));

for(int i=0;i<arr.length;i++)
{
if(heap.isEmpty() || heap.size()!=k || arr[i]< heap.peek())
{
heap.offer(arr[i]);
}
   if (heap.size() > k) {
            heap.poll(); // 删除堆顶最大元素
        }

}
   // 将堆中的元素存入数组
    int[] res = new int[heap.size()];
    int j = 0;
  while(!heap.isEmpty()) {
        res[j++] = heap.poll();
    }
    return res;
    }

}
```