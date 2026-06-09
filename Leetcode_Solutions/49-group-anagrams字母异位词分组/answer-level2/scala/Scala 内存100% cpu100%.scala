
```
def groupAnagrams2(strs: Array[String]): List[List[String]] = {

    def compareBitMap(a1: Array[Int], a2: Array[Int]): Boolean = {
        for(i <- a1.indices) {
            if(a1(i) != a2(i)) return false
        }
        true
    }

    case class BitMapWrapper(s: String) {
        lazy val bitMap = getBitMap
        private def getBitMap = {
            val tag = new Array[Int](26)
            s.foreach { c =>
                tag(c - 'a') = 1 + tag(c - 'a')
            }
            tag
        }

        override def equals(obj: Any): Boolean = {
            obj match {
                case wrapper: BitMapWrapper =>
                    compareBitMap(bitMap, wrapper.bitMap)

                case _ => false
            }
        }

        override def hashCode(): Int = {
            var hashCode = 0
            for(i <- bitMap.indices) {
                if(bitMap(i) > 0) hashCode |= (1 << i)
            }
            hashCode
        }

        override def canEqual(that: Any): Boolean = {
            that match {
                case wrapper: BitMapWrapper =>
                    compareBitMap(bitMap, wrapper.bitMap)

                case _ => false
            }
        }
    }

    val map = mutable.HashMap[BitMapWrapper, Int]()
    var out = List.empty[List[String]]

    strs.foreach{ s =>
        val bitMap = BitMapWrapper(s)

        if(map.contains(bitMap))
            out = out.updated(map(bitMap), out(map(bitMap)) :+ s)
        else {
            map.put(bitMap, out.length)
            out = out :+ List(s)
        }
    }

    out
}
```
