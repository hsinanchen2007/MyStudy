### 解题思路
100到1000,10到100,1到10的转换方法类似，可以抽象出一个方法，然后就是分类讨论，题解如下；

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        int n=0;
        if ((n=num/1000)!=0){
            for (int i = 0; i <n ; i++) {
                sb.append("M");
            }
            num=num-1000*n;
        }
        num=setNum(100,"M","D","C",num,sb);
        num=setNum(10,"C","L","X",num,sb);
        num=setNum(1,"X","V","I",num,sb);
        return sb.toString();
    }

    private int setNum(int nn, String m, String d, String c, int num,StringBuilder sb) {
        int n=0;
        if ((n=num/nn)!=0){
            if (n==9){
                sb.append(c).append(m);
            }else if (n==4){
                sb.append(c).append(d);
            }else if (n>=5){
                sb.append(d);
                for (int i = 0; i <n-5 ; i++) {
                    sb.append(c);
                }
            }else {
                for (int i = 0; i <n ; i++) {
                    sb.append(c);
                }
            }
            num=num-nn*n;
        }
        return num;
    }
}
```