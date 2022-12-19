```
        int suffix = s.length - 1;
        for (int i = 0;i < suffix;i++){
            char tem = s[i];
            s[i] = s[suffix];
            s[suffix] = tem;
            suffix--;
        }
```
