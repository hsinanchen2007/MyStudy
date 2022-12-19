在这个题，我们主要碰到的麻烦是如何避免重复计算。很显然一个字符串的子集是从1-length的累计和。
经过我们的观察发现首字母相同的序列一定是被字典包含或者是包含字典，由此我们得到了下面的代码
```
public int findSubstringInWraproundString(String p) {
        String[] v = new String[26];
        char[] ch = p.toCharArray();
        int result = 0;
        for(int i = 0; i < ch.length; i++){
            int start = i;
            while(i + 1 < ch.length && (ch[i] + 1) % 26 == ch[i + 1] % 26) i++;
            for(int j = start; j <= i; j++){
                String pre = v[ch[j] - 'a'] == null ? "" : v[ch[j] - 'a'];
                if (pre.length() >= i + 1 - j) break;
                else {
                    result += i - j + 1 - pre.length();
                    v[ch[j] - 'a'] = p.substring(j, i + 1);
                }
            }
        }
        return result;
    }
```
