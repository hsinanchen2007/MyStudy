其实也是单指针,利用一个指针，
直接添加，然后向后，只要遇到不相等，就将数字添加进去，
直到结束，over,100%
```java
public String compressString(String S) {
        if(S == null) return S;
        int len = S.length();
        StringBuilder sb = new StringBuilder();
        int l = 0;
        while(l < len){
            char c = S.charAt(l++);
            int count = 1;
            sb.append(c);
            while(l < len && c == S.charAt(l)){
                l++;
                count++;
            }
            sb.append(count);
        }
        return sb.toString().length() >= len ? S : sb.toString();
    }
```
Keep thinking, keep coding!