def lengthOfLastWord(s: String): Int = {
    var max = 0
    var sum = 0
    s.toCharArray.foreach(a =>{
      if(a.equals(' ')) sum=0
      else {
        sum+=1
        max=sum
      }
    })
    max
  }