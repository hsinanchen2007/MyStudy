### 解题思路
刚开始考虑的是将数组转为整数加一之后，在把整数转为数组，感觉比较麻烦。后来看到评论里面提到
直接从数组着手处理，就尝试做了一下；从最后一个元素开始循环，首先判断是否继续循环（若元素不等于9，直接当前元素加一跳出循环，输出结果；若当前元素为9，当前元素值为零，进入下一循环）；但是也报错了，没有考虑到9,99,999,999...等情况。通过观察发现，加一后，其值分别为10,100,1000,10000...；想到构造多一位的数组，并设首位值为1，即可。

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
        for (int i= digits.length-1; i>=0; i--) {
            int singleresult = digits[i];
            if(singleresult==9){
                digits[i]=0;
                if(i==0){  
                    digits = new int[digits.length + 1];  
                    digits[0]=1;
                }
            }else{
                digits[i]=digits[i]+1;
                break;
            }
           
        }
        return digits;
      
    }
}
```