![image.png](https://pic.leetcode-cn.com/8d9fa8771b633f48a741da578849c47a2d5b5334782412397e61df0750482fca-image.png)

```
    public String longestWord(String[] words) {
        Set<String> set = new HashSet();
        Arrays.sort(words, new Comparator<String> (){
            public int compare(String s1, String s2) {
                return s1.length() - s2.length();
            }
        });
        String res = "";
        for(String s: words) {
            if(s.length() <= 1 || set.contains(s.substring(0, s.length() - 1))) {
                set.add(s);
                if(s.length() > res.length() || (s.length() == res.length() && s.compareTo(res) < 0)) {
                    res = s;
                }
            }
        }
        return res;
    }
```

