```
/**
 * 146. LRU缓存机制
 * (Least recently) used: 最近一段时间, 最少使用的元素，最近是修饰最少的.
 * 注意点：
 * 0. 利用dummyHead与dummyTail减小判空的复杂度
 * 1. 更新mSize
 * 2. 记得更新map&&双向链表
 * 3. 在容量满时可以复用待移出队列的元素，减少对象创建
 */
public class P146 {
    public static class LRUCache {

        private class DLinkedNode {
            int key;
            int value;
            DLinkedNode pre;
            DLinkedNode next;
        }

        private Map<Integer, DLinkedNode> mCache;
        private final int CAPACITY;
        private int mSize = 0;
        private DLinkedNode mHead;
        private DLinkedNode mTail;

        public LRUCache(int capacity) {
            CAPACITY = capacity;
            mCache = new HashMap<>(capacity);
            mHead = new DLinkedNode();
            mTail = new DLinkedNode();
            mHead.next = mTail;
            mTail.pre = mHead;
        }

        public int get(int key) {
            DLinkedNode node = mCache.get(key);
            if (node == null) return -1;
            moveToFirst(node);
            return node.value;
        }

        public void put(int key, int value) {
            DLinkedNode node = mCache.get(key);
            if (node == null) {
                if (mSize >= CAPACITY) {
                    node = removeNode(mTail.pre);
                } else {
                    node = new DLinkedNode();
                    mSize++;
                }
            }
            node.key = key;
            node.value = value;
            moveToFirst(node);
        }

        /**
         * 1. remove
         * 2. insert
         * 注意更新mCache
         * @param node
         */
        private void moveToFirst(DLinkedNode node) {
            node = removeNode(node);
            mHead.next.pre = node;
            node.next = mHead.next;
            mHead.next = node;
            node.pre = mHead;
            mCache.put(node.key, node);
        }

        private DLinkedNode removeNode(DLinkedNode node) {
            // check if node is alone
            if (node == null || node.next == null || node.pre == null) return node;
            node.pre.next = node.next;
            node.next.pre = node.pre;
            node.next = null;
            node.pre = null;
            mCache.remove(node.key);
            return node;
        }

    }

}
```
