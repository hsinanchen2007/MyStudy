```java
public int countNumbersWithUniqueDigits(int n) {
    int ans = 1;
    int count = 9;
    for (int i = 0; i < 8 && i < n; i++) {
        ans += count;
        count *= (9 - i);
    }
    return ans;
}

```
