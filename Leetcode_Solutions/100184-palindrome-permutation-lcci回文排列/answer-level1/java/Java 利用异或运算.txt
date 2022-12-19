如果一个字符出现奇数次，则异或运算结果为1，否则为0。利用count记录奇数字符的个数，最终返回count值是否小于2。
```
    public boolean canPermutePalindrome(String s) {
        byte[] array = new byte[127];
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            if((array[s.charAt(i)] ^= 1) == 1) count++;
            else count--;
        }
        return count < 2;
    }
```
