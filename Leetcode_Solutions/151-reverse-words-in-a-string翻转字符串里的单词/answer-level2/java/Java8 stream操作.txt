```
public String reverseWords(String s) {
    String[] sArr = s.split(" ");
    Collections.reverse(Arrays.asList(sArr));
    String rs = Arrays.stream(sArr).map(i -> i.toString()).collect(Collectors.joining(" "));
    return rs.trim().replaceAll("\\s{1,}", " ");
}
```
