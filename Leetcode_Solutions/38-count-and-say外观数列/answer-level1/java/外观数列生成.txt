```
    private String[] dict;

    public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        dict = new String[n];
        dict[0] = "1";

        for (int i = 1; i < n; i ++) {
            String pre = dict[i - 1];

            StringBuilder sb = new StringBuilder();
            char preChar = pre.charAt(0);
            int count = 0;
            for (int j = 0; j < pre.length(); j ++) {
                if (pre.charAt(j) == preChar) {
                    count ++;
                } else {
                    sb.append(count);
                    sb.append(preChar);
                    preChar = pre.charAt(j);
                    count = 1;
                }
            }
            
            sb.append(count);
            sb.append(preChar);

            dict[i] = sb.toString();
        }

        return dict[n - 1];
    }
```
