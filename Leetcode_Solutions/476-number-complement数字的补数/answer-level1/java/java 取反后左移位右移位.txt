```
 public int findComplement(int num) {
         int count =32; //32位数
         int tmp = num;
         //计算给定数num的二进制位数
         while(tmp != 0){
             tmp >>= 1;
             count--;
         }
         //对num取反，左移动count位除去多余的1，右移count位去掉左移产生的0
         return num == 0 ? 1 : ((~num << count) >>> count);
    }
```
