### 解题思路
1.维护小顶堆，但是没有使用java的工具类，而是用一个长度为k+1的数组维护的堆结构。
2.主要有两个方法，insert和percolateDown。
3.其中insert是使用的上滤，原理是先把数据放在末尾，然后和其父节点比较，如果比父节点小那么把父节点的值放到当前位置。就像冒泡一样往上走。
4.而percolateDown则是下滤，因为顶端就是第k大的元素，如果新加入的比顶小那么不用加入什么也不做，如果比顶大那么顶点会被替换掉，然后调整整个堆使其重新满足堆结构即可。
关于上滤和下滤，借用《数据结构与算法分析》书中的图，一看就懂。

上滤:
![WX20200104-154847.png](https://pic.leetcode-cn.com/a8437657dfa452d206d3afaec47fca5fd51e85db3a94c35218284fd06369cb6f-WX20200104-154847.png)

下滤:
![WX20200104-154944.png](https://pic.leetcode-cn.com/507362e12d15f938c525a80207fd80f5ba043008212becd3491e25c8c4dd7309-WX20200104-154944.png)

### 代码

```java
class KthLargest {
    int[] queue;
        int curSize;
        int ck;

        public KthLargest(int k, int[] nums) {
            ck = k;
            queue = new int[k + 1];
            curSize = 0;
            for (int num : nums) {
                if (curSize < k) {
                    insert(num);
                } else {
                    percolateDown(num);
                }
            }
        }

        private void percolateDown(int num) {
            if (num > queue[1]) {
                int child;
                int hole = 1;
                for (; hole * 2 <= curSize; hole = child) {
                    child = hole * 2;
                    if (child != curSize && queue[child + 1] < queue[child]) {
                        child++;
                    }
                    if (queue[child] < num) {
                        queue[hole] = queue[child];
                    } else {
                        break;
                    }
                }
                queue[hole] = num;
            }
        }

        private void insert(int num) {
            int hole = ++curSize;
            for (queue[0] = num; num < queue[hole / 2]; hole /= 2) {
                queue[hole] = queue[hole / 2];
            }
            queue[hole] = num;
        }


        public int add(int val) {
            if (curSize < ck) {
                insert(val);
            } else {
                percolateDown(val);
            }
            return queue[1];
        }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */
```