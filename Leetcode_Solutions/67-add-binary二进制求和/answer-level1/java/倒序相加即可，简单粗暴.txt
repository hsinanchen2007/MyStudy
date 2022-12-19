```
public String addBinary(String a, String b) {
        //1. 非空字符串 2. 倒序相加即可
        int al = a.length();
        int bl = b.length();
        int l = al >= bl ? al : bl;
        int temp = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < l; i++) {
            //分别取值，取不到时赋值为0即可
            int at = al - i >= 1 ? Character.getNumericValue(a.charAt(al - i - 1)) : 0;
            int bt = bl - i >= 1 ? Character.getNumericValue(b.charAt(bl - i - 1)) : 0;
            //相加
            int t = at + bt + temp;
            if (t >= 2) {
                sb.insert(0, t % 2);
                temp = 1;
            } else {
                sb.insert(0, t);
                temp = 0;
            }
        }
        if (temp == 1) {
            sb.insert(0, 1);
        }
        return sb.toString();
    }
```
