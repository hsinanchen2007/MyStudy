```
    public int maximum69Number (int num) {
        String s = Integer.toString(num);

        char[] chars = s.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i]=='6'){
                chars[i]='9';
                break;
            }
        }
        StringBuffer res = new StringBuffer();
        return Integer.parseInt(res.append(chars).toString());
    }

```
