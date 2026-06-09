# 解法1 直观计数法
```
    public String countAndSay(int n) {
        String ans = "1";
        for (int i = 2; i <= n; i++) {
            StringBuilder temp = new StringBuilder();
            char preChar = ans.charAt(0); 
            int preCharCount = 1;
            for (int j = 1; j < ans.length(); j++) {
                char ch = ans.charAt(j);
                if (ch == preChar) {
                    preCharCount++;
                    continue;
                }
                temp.append(preCharCount).append(preChar);
                preChar = ch;
                preCharCount = 1;
            }
            temp.append(preCharCount).append(preChar);
            ans = temp.toString();
        }
        return ans;
    }
```

# 解法2 递归解法
```
 public String countAndSay(int n) {
        if (n == 1) {
            return "1";
        }

        String preStr = countAndSay(n - 1);    
        char preChar = preStr.charAt(0);
        int preCharCount = 1;    

        StringBuilder ans = new StringBuilder();
        for (int i = 1; i < preStr.length(); i++) {
            char currChar = preStr.charAt(i);
            if (preChar == currChar) {
                preCharCount++;
                continue;
            }
            ans.append(preCharCount).append(preChar);
            preChar = currChar;
            preCharCount = 1;
        }
        ans.append(preCharCount).append(preChar);
        return ans.toString();
    }
```