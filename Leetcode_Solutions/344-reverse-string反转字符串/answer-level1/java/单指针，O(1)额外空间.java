申请O(1),
```java []
public void reverseString(char[] s) {
    int current = 0;
    while(2 * current < (s.length-1)){
        s[current] = (char)(s[current] ^ s[s.length-1-current]);
        s[s.length-1-current] = (char)(s[current] ^ s[s.length-1-current]);
        s[current] = (char)(s[current] ^ s[s.length-1-current]);
        current ++;
    }
}
```
