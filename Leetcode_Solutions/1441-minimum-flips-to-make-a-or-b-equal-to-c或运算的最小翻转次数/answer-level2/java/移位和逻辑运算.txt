### 解题思路
看题目联想到的是取3个变量的每个二进制位直接进行比较，使用逻辑运算+位运算的话就非常直观了。
![捕获.PNG](https://pic.leetcode-cn.com/b37e2aa0db71086835f4fdc6f0bb479dd4ab7a1a7177fd50647b817b537470d0-%E6%8D%95%E8%8E%B7.PNG)

### 代码

```java
class Solution {
    public int minFlips(int a, int b, int c) {
        /*移位运算*/
        int count=0;
        for (int i = 0; i <31 ; i++) {
            int bitLocation = 1 << i;
            if(bitLocation==0){
                break;
            }
            int abit = a & bitLocation;
            int bbit = b & bitLocation;
            int cbit = c & bitLocation;
            if(cbit==bitLocation){
                if((abit|bbit)!=bitLocation){
                    count++;
                }
            }else{
                if((abit&bbit)==bitLocation){
                    count+=2;
                }else if((abit|bbit)==bitLocation){
                    count++;
                }
            }
        }
        return count;
    }
}
```