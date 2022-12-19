### 解题思路
isRecent 用于解决cnt相同时的最近节点排序

### 代码

```java
class LFUCache {

        class ValNode implements Comparable<ValNode>{
            int key;
            int val;
            int cnt;
            int isRecent;

            final static int RECENT = 1;
            final static int NOT_RECENT = 0;

            ValNode(int key, int val) {
                this.key = key;
                this.val = val;
                this.cnt = -1;
                isRecent = 1;
            }

            public void setRecent() {
                isRecent = RECENT;
            }

            public void pass() {
                isRecent = NOT_RECENT;
            }

            @Override
            public int compareTo(ValNode valNode) {
                int cntDiff = cnt - valNode.cnt;
                if (0 != cntDiff)
                    return cntDiff;
                return isRecent - valNode.isRecent;
            }

            @Override
            public String toString() {
                return String.format("key: %d, val: %d, cnt: %d", key, val, cnt);
            }
        }

        private static final int NON_VAL = -1;
        private final int capacity;
        private LinkedList<ValNode> list;
        private LinkedHashMap<Integer, ValNode> map;


        public LFUCache(int capacity) {
            map = new LinkedHashMap<>(capacity);
            this.capacity = capacity;
            list = new LinkedList<ValNode>();
        }

        public int get(int key) {
            ValNode node;
            if ((node = map.get(key)) == null) return NON_VAL;

            reSortStack(node);
            showList("GET " + key);

            return node.val;
        }

        public void put(int key, int value) {
            if (capacity <= 0)
                return;

            ValNode node;
            if ((node = map.get(key)) == null) {
                if (list.size() == capacity) {
                    ValNode lfuNode = list.poll();
                    map.remove(lfuNode.key);
                }

                node = new ValNode(key, value);
                list.add(node);
            }
            node.val = value;
            map.put(key, node);
            reSortStack(node);
            showList("PUT k:" + key + " v:" + value);

        }

        private void reSortStack(ValNode node) {
            ++node.cnt;
            node.setRecent();
            Collections.sort(list);
            node.pass();
        }

        public void showList(String str) {
            System.out.println(str);
            /*
            for (ValNode valNode: list) {
                System.out.println(valNode);
            }
            */
            System.out.println("================");
        }

    }
```