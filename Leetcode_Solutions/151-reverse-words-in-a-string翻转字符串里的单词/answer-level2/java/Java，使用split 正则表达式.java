```
        s = s.trim();
        String[] words = s.split(" {1,}");
        StringBuffer ret = new StringBuffer();
        for (int i = words.length - 1; i >= 0 ; i--) {
            ret.append(words[i]);
            if (i != 0) {
                ret.append(" ");
            }
        }
        return ret.toString();
```
