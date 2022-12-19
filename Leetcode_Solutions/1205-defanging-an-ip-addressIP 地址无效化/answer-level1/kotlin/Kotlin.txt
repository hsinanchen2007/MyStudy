内存击败100%
```
class Solution {
fun defangIPaddr(address: String): String {
    var str:String = ""
for (i in address) {
if (i=='.') str+="[.]" else str+=i.toString()
}
    return str
}
}
```

