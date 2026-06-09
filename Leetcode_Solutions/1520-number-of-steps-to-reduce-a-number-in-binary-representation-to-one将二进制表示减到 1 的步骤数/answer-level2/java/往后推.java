### 解题思路
此处撰写解题思路
二进制的除2是在二进制中向右移动一位 操作次数1步
例如 6(110) / 2 = 3(11)  

当最后一位是1为奇数,奇数加1变偶数,偶数又要右移一位 操作次数2步
在这个操作中 在二进制中 数字 1 会变成 0, 0 会变成 1,以后的校验就要换过来计算操作数
3(011) + 1 = 4(100) / 2 = 2(10)

向右移动1位 操作数1步
2(10) / 2 = 1(1)

尾部为1 需要的操作数是2步
尾部是0 需要的操作数是1步


### 代码

```java
class Solution {
    public int numSteps(String s) {
        int length = s.length();
        if(length==1){
            return 0;
        }
        int count = 0;
        char[] cs = s.toCharArray();
        boolean addOne=false;
        for (int i = length-1; i > -1; i--) {
            if(addOne){
                if(cs[i] == '1'){
                    count+=1;
                }else {
                    count+=2;
                }
            }else if(cs[i] == '1'){
                if(i == 0){
                    return count;
                }
                count+=2;
                addOne=true;
            }else {
                count+=1;
            }
        }
        return count;
    }
}
```