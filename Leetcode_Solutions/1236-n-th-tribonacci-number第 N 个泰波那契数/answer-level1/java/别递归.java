### 解题思路
.....不能用递归，要超时.唉，看到旁边大佬给的解析说这个双百算法快，记住了哈哈哈哈

### 代码

```java
import java.util.Scanner;
public class Solution {
    public static void main(String[] args){
        Scanner input =new Scanner(System.in);
        System.out.print("请输入n的值");
        int n=input.nextInt();
        if(n<0||n>37){
            System.out.print("n的数值太大");
        }
        else if(n>=0&&n<=37){
            tribonacci(n);
        }
    }  
    public static int tribonacci(int num) {
        if(num==0||num==1||num==2){
            return num==0?0:1;
        }
        int a=0,b=1,c=1;
        int result=0;
        for(int i=3;i<=num;i++){
            result=a+b+c;
            a=b;
            b=c;
            c=result;
        }
        return result;
    }
}
```