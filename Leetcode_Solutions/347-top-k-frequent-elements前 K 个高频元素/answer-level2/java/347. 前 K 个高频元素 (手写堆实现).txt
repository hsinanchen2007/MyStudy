top K 问题第一反应就是最小堆，这里直接给出代码吧（手写的堆，后面才发现JDK里面有个优先队列。。）

1、堆化（heapify）分两种，由上而下，由下而上;
2、实际比较的依据是Map中的value，即整数出现的频率;
3、插入操作引起一次由下而上的堆化, 删除堆顶元素引起一次由上而下的堆化;
4、堆是一个完全二叉树，使用数组存储最省空间（不用存储下标，如本解中从1开始存储, `i`的子节点为`2i`与`2i + 1`, `i`的父节点为`i / 2`）;
5、另外还有两种原地建堆的方式，也是用到了堆化。

时间复杂度：
    n个元素需要入堆，入堆操作的时间都耗费堆化上，可以看到堆化与堆高度成正比，树高不就是logN吗，这里就是logK了，所以总时间复杂度为O(NlogK)
空间复杂度：
    堆中元素最多为K个，即为O(K)

```
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        // map
        Map<Integer, Integer> map = new HashMap<>();
        for (int a : nums) {
            int cnt = map.getOrDefault(a, 0);
            map.put(a, ++cnt);
        }

        // init heap
        Heap heap = new Heap(k, map);
        for (int key : map.keySet()) {
            heap.insert(key);
        }

        // print return
        int[] arr = heap.arr;
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i < arr.length; i ++) list.add(arr[i]);
        return list;
    }

    static class Heap{
        // current number
        int count;
        // max number
        int capacity;
        // obj data
        int[] arr;
        // data map
        Map<Integer, Integer> map;

        Heap(int cnt, Map<Integer, Integer> map) {
            this.arr = new int[cnt + 1];
            this.count = 0;
            this.capacity = cnt;
            this.map = map;
        }

        // up to down
        void heapify(int x, int y) {
            int minPos, sL, sR;
            while(true) {
                minPos = x;
                if ((sL = x << 1) < y && map.get(arr[sL]) < map.get(arr[x])) minPos = sL;
                if ((sR = (x << 1) + 1) < y && map.get(arr[sR]) < map.get(arr[minPos])) minPos = sR;
                if (minPos == x) break;
                swap (x, minPos);
                x = minPos;
            }
        }

        // down to up
        void downHeapIfy (int x, int y) {
            int n;
            while ((n = y / 2) >= x) {
                if (map.get(arr[n]) > map.get(arr[y])) {
                    swap(n, y);
                    y = n;
                } else {
                    break;
                }
            }
        }

        // insert and make sure it top K (min)
        void insert (int newInt) {
            if ( count == capacity ) {
                if (map.get(arr[1]) < map.get(newInt)) {
                    deleteTop();
                } else {
                    return;
                }
            }
            arr[++count] = newInt;
            downHeapIfy(1, count);
        }
        
        // delete top 1
        void deleteTop() {
            arr[1] = arr[count];
            arr[count] = 0;
            heapify(1, count);
            count--;
        }

        void swap(int x, int y) {
            int tmp = arr[x];
            arr[x] = arr[y];
            arr[y] = tmp;
        }
    }
}
```

第一次写题解...