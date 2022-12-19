```
class Solution {
    public String reverseLeftWords(String s, int n) {
        if(s.length()<=1)return s;
        String front=s.substring(n);
        String rear=s.substring(0,n);
        return front+rear;
    }
}
```
继续浓缩成一行
```
class Solution {
    public String reverseLeftWords(String s, int n) {
        return s.substring(n)+s.substring(0,n);
    }
}
```

