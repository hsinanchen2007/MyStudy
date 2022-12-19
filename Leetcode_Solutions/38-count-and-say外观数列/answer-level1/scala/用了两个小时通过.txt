def countAndSay(n: Int): String = {
    var strings = new Array[String](31)
    strings(1) = "1"
    for (i <- 2 until 31) {
      var cur = ""
      var k1, k2, k3 = 0
      val current = strings(i - 1)
      for (j <- 0 until current.length) {
        if (j < current.length) {
          if (current(j) == '1') k1 += 1
          else {
            if (k1 > 0) cur += s"${k1}1"
            k1 = 0
          }
          if (current(j) == '2') k2 += 1
          else {
            if (k2 > 0) cur += s"${k2}2"
            k2 = 0
          }
          if (current(j) == '3') k3 += 1
          else{
            if (k3 > 0) cur += s"${k3}3"
            k3 = 0
          }
        }
      }
      if(k1>0) cur+=s"${k1}1"
      if(k2>0) cur+=s"${k2}2"
      if(k3>0) cur+=s"${k3}3"
      strings(i) = cur
    }
    return strings(n)
  }