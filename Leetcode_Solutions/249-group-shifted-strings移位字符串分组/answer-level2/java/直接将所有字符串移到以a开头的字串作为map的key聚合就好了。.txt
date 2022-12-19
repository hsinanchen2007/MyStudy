好处是，如果字串本身就以a开头，无需遍历直接塞到map里

```java
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String>> map = new HashMap<>();
        for (int i = 0; i < strings.length; i++) {
            String tmp = strings[i];
            StringBuilder sb = new StringBuilder();
            int c = 0;
            for (int j = 0; j < tmp.length(); j++) {
                if (j == 0) {
                    c = tmp.charAt(j) - 'a';
                    if (c == 0) {
                        sb.append(tmp);
                        break;
                    }
                }
                if (tmp.charAt(j) - c >= 'a') {
                    sb.append((char)(tmp.charAt(j) - c));
                } else {
                    sb.append((char)('z' - (c - (tmp.charAt(j) - 'a') - 1)));
                }
            }
            String key = sb.toString();
            map.putIfAbsent(key, new ArrayList<>());
            map.get(key).add(tmp);
        }
        return new ArrayList<>(map.values());
    }
```