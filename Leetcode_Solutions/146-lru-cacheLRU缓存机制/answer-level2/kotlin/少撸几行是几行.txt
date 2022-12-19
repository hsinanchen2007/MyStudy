```kotlin    
class LRUCache(capacity: Int) {
        private var map = mutableMapOf<Int, Int>()
        private var queue = ArrayList<Int>(capacity) //队头为最早访问，队尾为最近访问
        private var capacity = capacity

        fun get(key: Int): Int {
            if (map.get(key) == null) {
                return -1
            }

            //调整key为最近访问
            queue.remove(key)
            queue.add(key)

            return map.get(key)!!
        }

        fun put(key: Int, value: Int) {
            //key为新加入的时候才需要废弃最早访问的元素
            if (map.get(key) == null && map.size >= capacity) {
                map.remove(queue.elementAt(0))
                queue.removeAt(0)
            }

            //调整key为最近访问
            queue.remove(key)
            queue.add(key)

            //更改值
            map.set(key, value)
        }
    }
```