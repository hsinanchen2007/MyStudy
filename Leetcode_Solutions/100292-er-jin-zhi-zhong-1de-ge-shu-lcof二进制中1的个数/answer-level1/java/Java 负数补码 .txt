### 解题思路

## 方法1：将n分为正负数求
  数字在计算机中都是以补码形式存储，正数和0的补码都是原码本身：例如 2 原码：0010  补码：0010 ；负数的补码是其对应正数各位取反，再+1：例如 -2的补码是 先求|-2|=2的原码 0010， 取反：1101，再+1：1110
# n为负数
   - 首先将求n的绝对值的原码，用a[32]代表二进制位，不断除2，将余数放进a[i]，i从31到0，（从低位开始放值）
   - 然后将原码取反加一，得到n的补码。找到数组a[]中最右边的1，然后将其前面的数组中数取反，最后得到的就是补码（因为取反+1没有改变最右边1开始的右边所有位，只改变了最右边1之前的位，比如上面2的原码与-2的补码）
   - 计算补码中1的个数返回。
   

# n为正数
   - 不断除2，统计余数为1的个数

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count=0;
         int mod;
         if(n<0){
             count = compant(n);
         }else{
             while(n!=0){
               mod = n%2;
               n = n/2;
               if(mod==1){
                 count++;
               }  
             }
         }
         
         return count;
    }
    public int compant(int n){
        int a[]=new int[32];
        int count=1;
        n = Math.abs(n);
        int i=31;
        while(n!=0){
            a[i]= n%2;
            i--;
            n=n/2;
        }
        for(i=31;i>=0;i--){
            if(a[i]==1){
                for(int j=i-1;j>=0;j-- ){
                    if(a[j]==0){
                        a[j]=1;
                        count++;
                    }else{
                        a[j]=0;
                    }
                    
                }
                break;
            }  
        }
        return count;
    }
}
```

## 方法2：
 
如果一个整数不为0，那么这个整数至少有一位是1。如果我们把这个整数减1，那么原来处在整数最右边的1就会变为0，原来在1后面的所有的0都会变成1(如果最右边的1后面还有0的话)。其余所有位将不会受到影响。
举个例子：一个二进制数1100，从右边数起第三位是处于最右边的一个1。减去1后，第三位变成0，它后面的两位0变成了1，而前面的1保持不变，因此得到的结果是1011.我们发现减1的结果是把最右边的一个1开始的所有位都取反了。这个时候如果我们再把原来的整数和减去1之后的结果做与运算，从原来整数最右边一个1那一位开始所有位都会变成0。如1100&1011=1000.也就是说，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0.那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。

```
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count=0;
        while(n!=0){
            n= n & (n-1);
            count++;
        }
        return count;
    }
}

```
