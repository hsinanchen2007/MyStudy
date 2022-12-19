### 解题思路
    首先我们寻找数字规律
     *  0 0
     *  1 1
     *  2 10
     *  3 11
     *  4 100
     *  5 101
     *  6 110
     *  7 111
     *  8 1000
     *  9 1001
     *  10 1010
     *  11 1011
     *  12 1100
     *  13 1101
     *  14 1110
     *  15 1111
     *  16 10000
     
     排除0,1 我们可以看出当num为2的整数次方的时候，含1的个数总是1，
     其他时候9的位数是8的位数(总是1)+(9-8)的位数,13的位数是8的位数(总是1)+(13-8)的位数
     所以我们在遍历的过程中，记住两个值，当前整数次方的位置，当前的base值
     int index = 1;
     int base = 0;
     for(int i = 0;i<=num;i++){
         if(i == 0){
             bits[i] = 0;
        }else if(i==1){
            bits[i] = 1;
        }else if(i == (int)Math.pow(2,index)){
            base = i;
            index++;
            bits[i] = 1;    
        }else{
            bits[i] = 1 + bits[i-base];
        }
    }
    return base;


### 代码

```java
class Solution {

    public int[] countBits(int num) {
        int[] bits = new int[num+1];
        int index = 1;
        int base = 0;
        for(int i = 0;i<=num;i++){
            if(i ==0){
                bits[i] = 0;
            }else if(i==1){
                bits[i] = 1;
            }else if(i == (int)Math.pow(2,index)){
                base = (int)Math.pow(2,index++);
                bits[i] = 1;
            }else{
                bits[i] = 1+bits[i-base];
            }
        }
        return bits;
    }
}
```