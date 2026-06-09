### 解题思路
此处撰写解题思路

### 代码

```java
// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {

        Queue<Integer> queue;
        Iterator<Integer> iterator;

        public PeekingIterator(Iterator<Integer> iterator) {
            // initialize any member here.
            this.iterator = iterator;
            queue = new LinkedList<>();
        }

        // Returns the next element in the iteration without advancing the iterator.
        public Integer peek() {
            if (queue.isEmpty()) {
                queue.add(iterator.next());
            }
            return queue.peek();
        }

        // hasNext() and next() should behave the same as in the Iterator interface.
        // Override them if needed.
        @Override
        public Integer next() {
            if (queue.isEmpty())
                return iterator.next();
            else 
                return queue.poll();
        }

        @Override
        public boolean hasNext() {
            return (!queue.isEmpty()) || iterator.hasNext();
        }
    }
```