![image.png](https://pic.leetcode-cn.com/2e9f40243ce8dc6a62e32732e7f86f12e46fb0bbcd81b8a729cdbbd6186e2696-image.png)

### 解题思路
这一题只需要列出可能出现的情况并对应解决即可
可以分为三种：
123+1=124  只需要改变个位数
129+1=130  需要改变多位数，有进位
99+1=100   需要改变数组，多了一位数
对于第一种情况，直接改数组的最后一位数的数值
对于第二种情况，从最后一位开始查看9的位数，将之数值改为0，不是9的数值+1，并跳出循环
对于第三种情况，建立在第二种情况的前提上，这里我用到flag标记判断
如果是第三种情况，则给digits空间，修改数值

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        int len=digits.length,flag=0;
        if((digits[len-1]+1)<10){
            digits[len-1]+=1;
            return digits;
        }
        len=len-1;
        while(len>=0){
            flag=0;
            if(digits[len]==9){
                digits[len]=0;
                flag=1;
            }else{
                digits[len]+=1;
                break;
            }
            len--;
        }
        if(flag==1){//999+1=1000
             digits=new int[digits.length+1];
             digits[0]=1;
        }
        return digits;
    }
}
```