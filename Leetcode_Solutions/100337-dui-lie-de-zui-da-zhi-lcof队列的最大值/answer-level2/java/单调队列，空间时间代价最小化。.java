### 解题思路
这道题其实重在分析，分析清楚情况就可以了。

主要的思想是这样，对于队列来说，始终是先进先出的，那么假设当前第i个进来的元素x是当前最大值。那么很显然在i之间进来的元素必定会比x先出队，并且由于当前最大值是x，那么前面的都不可能成为最大值，所以不用保存直接抛弃即可。对于在i之后进来的元素，如果比x大的话，那么就应该抛弃x然后更新最大值。如果比x小的话，那么由于x在他们前面，会先出队，那么x出队之后的最大值就在他们中，所以需要保持。所以我们需要保持一个这样的结构：

1. 首先这个结构必须是单调递增的（以便我们可以始终通过O(1)的代价来获得最大元素）
2. 这个结构中的元素的入队顺序必须是从前到后的，即最后一个元素是最先入队的，同时也是最先出这个结构的。

所以我们需要维持一个单调队列的结构，假设这个单调队列为linkedlist具体步骤如下：
1. 入队时，如果linkedlist为空，直接把当前元素x加入linkedlist即可。否则与linkedlist最后一个元素last比较，如果比x >= last，前面所有的（比x小并且比x先入队的）都可以抛弃了，不可能成为最大值。如果 x < last，那么在last出队之后x可能成为最大值，所以加在last的前面。
2. 出队时，把出队的元素比linkedlist中的最后一个元素（最大值元素）作比较，如果相同就说明最大元素出队了，在linkedlist弹出它即可。
3. 获取最大值时，直接获取linkedlist的最后一个元素即是最大值。

### 结果
![Snipaste_2020-03-07_12-38-41.png](https://pic.leetcode-cn.com/5e1483febb84f38f885abaeac2c848cab8a04956deb743f55d12ff173a6c9151-Snipaste_2020-03-07_12-38-41.png)


### 代码

```java
class MaxQueue {

        private Queue<Integer> queue;
        private LinkedList<Integer> linkedList;

        public MaxQueue() {
            queue = new LinkedList<>();
            linkedList = new LinkedList<>();
        }

        public int max_value() {
            if (linkedList.isEmpty())
                return -1;
            return linkedList.peekLast();
        }

        public void push_back(int value) {
            queue.add(value);
            if (linkedList.isEmpty()){
                linkedList.push(value);
            }else if (value >= linkedList.peekLast()){
                linkedList.clear();
                linkedList.add(value);
            }else if (value < linkedList.peekLast()) {
                while (!linkedList.isEmpty() && value >= linkedList.peekFirst()){
                    linkedList.pollFirst();
                }
                linkedList.addFirst(value);
            }
        }

        public int pop_front() {
            if (queue.isEmpty()){
                return -1;
            }
            if (queue.peek().equals(linkedList.peekLast()))
                linkedList.pollLast();
            return queue.poll();
        }
    }
```