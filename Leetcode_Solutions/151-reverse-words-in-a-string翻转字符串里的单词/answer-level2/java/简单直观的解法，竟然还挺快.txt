![image.png](https://pic.leetcode-cn.com/7c6ea10330d3e451441f38c35ad923b774eaf18f86d627b38c2178ea0beafbf9-image.png)

```
    public String reverseWords(String s) {
        s = s.trim();
        if(s.equals("")) {
            return "";
        }
        String[] sp = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for(int i = sp.length - 1; i >= 0; i--) {
            sp[i].trim();
            if(sp[i].equals("")) {
                continue;
            }
            sb.append(sp[i]);
            sb.append(" ");
        }
        return sb.toString().substring(0, sb.length() - 1);
    }
```

