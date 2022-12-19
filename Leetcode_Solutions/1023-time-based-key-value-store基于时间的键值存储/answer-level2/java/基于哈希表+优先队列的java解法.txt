思路是直接使用HashMap<String, PriorityQueue<Node>>,使用最大堆的思想能够最快得出最接近的时间戳。代码如下：
```
class TimeMap {
    Map<String, PriorityQueue<Node>> map;
    //Set<String> set;//去重用的
    public TimeMap() {
        map = new HashMap<String, PriorityQueue<Node>>();
        //set = new HashSet<String>();
    }
    
    public void set(String key, String value, int timestamp) {
        PriorityQueue<Node> queue = map.get(key);
        if (queue == null) {
            queue = new PriorityQueue<Node>(new Comparator<Node>() {
                @Override
                public int compare(Node o1, Node o2) {
                    return o1.compareTo(o2);
                }
            });
            map.put(key, queue);
        }
        //String nKey = key + value + timestamp;
        // if (!set.contains(nKey)) {
            queue.add(new Node(value, timestamp));
        //	set.add(nKey);
        //}
    }
    
    public String get(String key, int timestamp) {
        PriorityQueue<Node> queue = map.get(key);
        if (queue == null) return null;
        else {
            Iterator<Node> it = queue.iterator();
            while (it.hasNext()) {
                Node node = it.next();
                if (node.timestamp <= timestamp) return node.value;
            }
            return "";
        }
    }
    
    private static class Node implements Comparable<Node> {
        private int timestamp;
        private String value;
        public Node(String value, int timestamp) {
            this.value = value;
            this.timestamp = timestamp;
        }
        @Override
        public int compareTo(Node node) {//按从大到小排序
            return node.timestamp - timestamp;
        }
    }
}
```
直接使用java的api速度是很快的，至少我现在是前100%，然后我本来还使用了一个HashSet避免存储重复的时间戳，能进一步加快最大堆的遍历速度，但是好像不是很适合这道题（可能样例都没有重复值），去掉反而更快，也更省内存。

关于这道题，也可以用数组代替优先队列。单从查找速度，数组的二分查找肯定是优于最大堆的。但是这道题因为经常需要set，而堆的优势就是能很好的维护动态数组(复杂度比普通有序数组低)，所以这道题使用最大堆会更快一点。