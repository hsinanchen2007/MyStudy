# 解法一 队列
1. 将$Iterator$所指向的所有元素放到一个队列$LinkedList$中；
2. 然后$LinkedList$的$peek$方法就是题目要求的$peek，poll$方法就是题目要求的$next，hasNext$可以通过$!queue.isEmpty()$判断队列即可。

```java
 class PeekingIterator implements Iterator<Integer> {

        private LinkedList<Integer> queue;

        public PeekingIterator(Iterator<Integer> iterator) {
            queue = new LinkedList<>();
            while (iterator.hasNext()) {
                queue.add(iterator.next());
            }
        }

        public Integer peek() {
            return queue.peek();
        }

        @Override
        public Integer next() {
            return queue.poll();
        }

        @Override
        public boolean hasNext() {
            return !queue.isEmpty();
        }
    }
```
**复杂度**
时间复杂度：$O(n)$
空间复杂度：$O(n)$。因为多开辟了一个$n$大小的队列。

# 解法二 peek预取
详见代码
```java
class PeekingIterator implements Iterator<Integer> {

        private Integer cur;
        private Iterator<Integer> iterator;

        public PeekingIterator(Iterator<Integer> iterator) {
            this.iterator = iterator;
            cur = null;
        }

        public Integer peek() {
            if (cur != null) {
                return cur;
            }

            cur = iterator.next();
            return cur;
        }

        @Override
        public Integer next() {
            if (cur != null) {
                int res = cur;
                cur = null;
                return res;
            }

            return iterator.next();
        }

        @Override
        public boolean hasNext() {
            return cur != null || iterator.hasNext();
        }
    }
```
**复杂度**
时间复杂度：$O(n)$
空间复杂度：$O(1)$

**两种解法对比**
1. 解法一通过$java$自带的$LinkedList$来实现，比较简单；但是解法一需要另外耗费n（元素个数）大小的空间
2. 解法二无需耗费额外空间，但是相对第一种解法代码更加啰嗦了一点。不过我还是推荐这种解法。