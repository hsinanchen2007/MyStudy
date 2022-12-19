```java
public static Boolean isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

@SuppressWarnings("WeakerAccess")
public String reverseVowels(String s) {
    char[] letters = s.toCharArray();
    int left = 0;
    int right = letters.length - 1;

    while (left < right) {
        if (!isVowel(letters[left])) {
            left++;
        }
        if (!isVowel(letters[right])) {
            right--;
        }
        if (isVowel(letters[left]) && isVowel(letters[right])) {
            char tmp = letters[left];
            letters[left] = letters[right];
            letters[right] = tmp;
            left++;
            right--;
        }
    }

    return new String(letters);
}
```
