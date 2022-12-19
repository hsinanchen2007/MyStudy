1、不应该遍历未压缩的字符串，因为它可能很长
2、 解析压缩字符串，比如"w3d"，表示第0个字符为w， 第4个字符为d
3、一些特殊情况，数字不能以0开头，以及总长度相等。
```
object Solution {
    def validWordAbbreviation(word: String, abbr: String): Boolean = {
        def f(l:List[Char], i:Int, tmp:Int, acc:List[(Int, Char)]):List[(Int, Char)] = l match {
            case h::t => 
            if(h.isDigit) f(t, i , tmp * 10 + h - '0', acc)
            else f(t, tmp+i+1, 0, (tmp + i, h)::acc)
            case Nil => acc
        }
        
        def g(s:List[Char],tmp:Int = 0, acc:Int = 0):Int = s match {
            case h::t => 
            if(h.isDigit) g(t, tmp * 10 + h - '0', acc)
            else g(t,0, acc + tmp + 1)
            case Nil => acc + tmp
        }
        
        def noLeadZero(s:List[Char], tmp:Int):Boolean = s match {
            case h::t => if(h.isDigit){
                if(h == '0' && tmp == 0) false 
                else noLeadZero(t, tmp * 10 + h - '0')
            }
            else noLeadZero(t, 0)
            case Nil => true
        }
        noLeadZero(abbr.toArray.toList, 0) && 
        word.length == g(abbr.toArray.toList) && 
        (f(abbr.toArray.toList, 0, 0, Nil) forall {case (i, char) =>if(i >= word.length) false else word(i) == char})
    }
}
```
