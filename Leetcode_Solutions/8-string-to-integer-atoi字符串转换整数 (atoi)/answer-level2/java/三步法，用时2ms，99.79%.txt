瞎起了一个名字，其实就是简单的三个步骤逐一进行即可：1.删除两端空格。2.判断正负号。3.找出连续的数字，并进行溢出判断。

需要注意：1.判断每个字符是否是数字时，.**第一个**字符可以是‘+’或‘-’，其余字符都必须是数字，循环才能继续。2.判断是否溢出时，分正数和负数两种情况。不能写成'ans*10>MaxInt',否则在判断时就可能发生溢出。

```java
public int myAtoi(String str) {
//        如果字符串为空直接返回0
        if(str==null)return 0;
//        1.去掉所有空格
        String s = str.trim();
//        如果去掉空格之后字符串为空，就返回0
        if (s.equals(""))return 0;
//        2.判断正负号
        int flag=1;
        if (s.charAt(0)=='-')flag=-1;
//        3.找出连续的数字
        int ans=0;
        for (int i=0;i<s.length();i++){
            char c=s.charAt(i);
            if (c>='0'&&c<='9'){//数字
    //            溢出判断
                if (flag==1){
                    if (ans>Integer.MAX_VALUE/10||(ans==Integer.MAX_VALUE/10&&c-'0'>7))
                        return Integer.MAX_VALUE;
                }else {
                    if (ans*flag<Integer.MIN_VALUE/10||(ans*flag==Integer.MIN_VALUE/10&&c-'0'>8))
                        return Integer.MIN_VALUE;
                }
                ans=ans*10+c-'0';
            }else if ((c=='-'||c=='+')&&i<1){//第一个字符c不是数字，但c可以是正负号
//             空方法体，什么也不操作，进入第二次循环
            }else{//既不是数字，也不是第一个正负号字符，直接结束循环
                break;
            }
        }
        return ans*flag;
    }
```

最坏情况每个字符访问一次，所以时间复杂度是：O(n)