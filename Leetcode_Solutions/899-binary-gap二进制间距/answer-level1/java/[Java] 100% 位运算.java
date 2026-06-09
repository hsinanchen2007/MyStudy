- **解题思路：**
- 和官方给出的解法二的思路相似：从二进制低位开始遍历，用count记录连续的两个1之间的距离。

```
public int binaryGap(int N) {
        int count = 0, max = 0;                     //这里count初始化为0，解决了只含一个1或不含1的情况
        while(N != 0){
            if((N & 1) == 1){
                max = (count > max) ? count : max;
                count = 1;
            }else{
                if(count > 0)   count++;            //在遇到一个1之后的0才开始计数
            }
            N = N >>> 1;
        }
        return max;
    }
```
