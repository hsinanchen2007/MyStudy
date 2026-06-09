```
private static final char[] f = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    public boolean isAdditiveNumber(String num) {
        final int len = num.length();
        if (len < 3)
            return false;
        char[] ch = num.toCharArray();
        
        for (int i = 0; i < len; i++) {
            ch[i] -= '0';
        }
        
        
        for (int i = 1; i <= len >> 1; i++) {
            
            for (int j = i + 1; j + Math.max(j - i, i) <= len; j++) {
                int left = 0;
                int centre = i;
                int right = j;
                for (;right > 0 && right < len;) {
                    int temp = com(ch, len, left, centre, right);
                    left = centre;
                    centre = right;
                    right = temp;
                }
                if (right == len)
                    return true;
            }
            
        }
        
        return false;
    }
    
    /**
     * 1 2 3 4 4 6   8   0 1 2 6
     * m   n   k   index
     * 
     * 计算 12 + 34 = 4... 和的首位非1，肯定未进位，推出 和的长度为 max（12.lenght， 34.lenght）
     * 进而推导出 index
     * 
     * 计算 m~n 加上 n~k 的字符的和k-index，并返回结果中的index，如果不存在k~index，则返回-1
     * 
     * @return index //和的最后一位所在位置的索引 + 1
     * 
     */
    private int com(char[] ch, int len, int m, int n, int k) {
        int len1 = n - m;
        int len2 = k - n;
        
        // 防止出现 0 开头的数
        if ((len1 > 1 && ch[n - len1] == 0) || (len2 > 1 && ch[k - len2] == 0))
            return -1;
        
        if (len1 < len2) {
            int temp = len2;
            len2 = len1;
            len1 = temp;
            
            temp = k;
            k = n;
            n = temp;
        }
        
        
        
        int index = Math.max(n, k) + len1;
        
        /*
         * 和 进位的情况
         * 和的首位必须是 1 // 因为这是两个数加法，所以进位不可能进 2
         * a + b = c // c 的首位是 1，以下两种情况会进位
         * 最长位数的加数的首位非 1 
         * 两个加数的长度相等   
         * ...未考虑到 0 + 1 = 1 的情况...
         */
        if (ch[Math.max(n, k)] == 1 && (ch[n - len1] != 1 || len1 == len2)) 
            if (len1 == len2 && len1 == 1 && ch[n - 1] * ch[k - 1] == 0){} // 增加 a + 0 = a 的情况不进位
            else index ++;
        
        
            
        
        if (index > len)
            return -1;
        
        int flag = 0;
        for (int i = 1; i <= len2; i++) {
            if (ch[index - i] != f[ch[n - i] + ch[k - i] + flag])
                return -1;
            flag = ch[n - i] + ch[k - i] + flag > 9 ? 1 : 0;
        }
        
        for (int i = len2 + 1; i <= len1; i++) {
            if (ch[index - i] != f[ch[n - i] + flag])
                return -1;
            flag = ch[n - i] + flag > 9 ? 1 : 0;
        }
        
        return index;
    }
```
