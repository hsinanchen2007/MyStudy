我的想法是直接构造交替位二进制数字，然后再与原数比较是否相等。效率还行，所有 Java 提交中击败了96.57%的用户，但写代码可能太复杂了，可以参考一下。
看代码：
```java
public boolean hasAlternatingBits(int n) {
        if (n<2)
            return false;
        int tmp=n;
        int num=0;
        boolean flag=(tmp&1)==0;
        if (flag){//如果最后一位为0，那交替形式应该为：***1010形式
            for (int i=0;tmp>0;++i){
                if ((i&1)==1){//i为奇数
                    num+=2<<(i-1);
                }
                tmp>>=1;
            }
            return num==n;
        }else {//如果最后一位为1，那交替形式为：***0101形式
            for (int i=0;tmp>0;++i){
                if ((i&1)==0&&i>0){//i为偶数
                    num+=1<<i;
                }
                tmp>>=1;
            }
            return num==n-1;
        }
    }
```
