```
StringBuilder builder = new StringBuilder();
        int start = 0;
        int count = 0;
        for (int i = 0; i < S.length(); i++) {
            if ('(' == S.charAt(i)) {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                //获取到一组原语
                builder.append(S, start+1, i);
                start = i+1;
            }
        }

        return builder.toString();
```