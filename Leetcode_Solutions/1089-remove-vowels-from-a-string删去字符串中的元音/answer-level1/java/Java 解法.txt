```java
public String removeVowels(String S) {
    char[] letters = S.toCharArray();
    int pos = 0;

    for (int offset = 0; offset < letters.length; offset++) {
        if (letters[offset] != 'a' && letters[offset] != 'e' &&
                letters[offset] != 'i' && letters[offset] != 'o' &&
                letters[offset] != 'u') {
                    if (pos != offset) {
                        letters[pos] = letters[offset];
                    }
                    pos++;
                }
    }

    return new String(letters, 0, pos);
}
```
