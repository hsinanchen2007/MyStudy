
```
import scala.collection.mutable
class LFUCache(_capacity: Int) {

  val keyFreqMap = new mutable.HashMap[Int, Int]()
  val freqItemMap = new mutable.HashMap[Int, mutable.LinkedHashMap[Int, Int]]()
  var minFreq = 0

  def get(key: Int): Int = {
      if (_capacity == 0) {
            return -1
        }
      
    keyFreqMap.get(key) match {
      case Some(freq) =>
        keyFreqMap.update(key, freq + 1)
        val value = freqItemMap.getOrElse(freq, null).getOrElse(key, -1)

        freqItemMap.get(freq) match {
          case Some (itemMap) =>
            itemMap.remove(key)
            if(freq == minFreq && itemMap.isEmpty) {
              minFreq += 1
            }
            case None => println(freqItemMap)
        }
        freqItemMap.getOrElseUpdate(freq + 1, new mutable.LinkedHashMap[Int, Int]).put(key, value)

        value
      case None => -1
    }

  }

  def put(key: Int, value: Int) {
        if (_capacity == 0) {
            return
        }
        if (keyFreqMap.contains(key)) {
          keyFreqMap.get(key) match {
            case Some(freq) =>
              keyFreqMap.update(key, freq + 1)

              freqItemMap.get(freq) match {
                case Some(itemMap) =>
                  itemMap.remove(key)
                  if (freq == minFreq && itemMap.isEmpty) {
                    minFreq += 1
                  }

                case None => println(freqItemMap)
              }
              freqItemMap.getOrElseUpdate(freq + 1, new mutable.LinkedHashMap[Int, Int]).put(key, value)
            case None => println(keyFreqMap)
          }
        }
        else if (keyFreqMap.size < _capacity) {
            keyFreqMap += (key -> 1)
            minFreq = 1
            freqItemMap.getOrElseUpdate(1, new mutable.LinkedHashMap[Int, Int]).put(key, value)
        }
        else {
            val oldKey = freqItemMap.getOrElse(minFreq, null).head._1
            freqItemMap.getOrElse(minFreq, null).remove(oldKey)
            keyFreqMap.remove(oldKey)
            keyFreqMap += (key -> 1)
            minFreq = 1
            freqItemMap.getOrElseUpdate(1, new mutable.LinkedHashMap[Int, Int]).put(key, value)
        }
    }

}

/**
 * Your LFUCache object will be instantiated and called as such:
 * var obj = new LFUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```
