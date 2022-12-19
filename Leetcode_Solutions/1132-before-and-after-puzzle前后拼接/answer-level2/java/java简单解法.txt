代码如下:
```
public List<String> beforeAndAfterPuzzles(String[] phrases) {
        List<String> res = new ArrayList<>();
        if (phrases.length == 1) {
            return res;
        }

        Set<String> set = new HashSet<>();
        StringBuilder sb;
        for (int i = 0; i < phrases.length; i++) {
            String suffix = phrases[i].substring(phrases[i].lastIndexOf(" ") + 1);
            for (int j = 0; j < phrases.length; j++) {
                if (i == j) {
                    continue;
                }
                String[] split = phrases[j].split(" ");
                if (split[0].equals(suffix)) {
                    sb = new StringBuilder();
                    sb.append(phrases[i]).append(phrases[j].substring(suffix.length()));
                    set.add(sb.toString());
                }
            }
        }

        res = new ArrayList<>(set);
        Collections.sort(res);
        return res;
    }
```
