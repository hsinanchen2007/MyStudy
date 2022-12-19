解法1:可以用String 的 replaceAll
解法2:遍历字符串,判断是否是 '.' 如果是,拼接'[.]',如果不是则拼接原字符

```
    private final String STR = "[.]";
    public String defangIPaddr(String address) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < address.length(); i++) {
            char ccc = address.charAt(i);
            if (ccc == '.'){
                sb.append(STR);
            }else{
                sb.append(ccc);
            }
        }
        return sb.toString();
    }
```
