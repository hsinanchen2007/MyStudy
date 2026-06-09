### 解题思路
1.如果最后一个字母是0,说明是偶数,则直接删掉最后一个字母。
  类似 1110 -> 111
2.如果最后一个字母是1,则从前往后找最后一个是0的位置index。
    2.1 如果找到,则将最后一个index位置直接变1,index位置之后的全部变0
         101011 ->   101100
    2.2 如果找不到,说明当前字符全是1,需要进位操作。
        第一个字母为0,后面全是1
         1111 -> 10000
 

### 代码

```java
class Solution {
    public int numSteps(String s) {
        int step =0;
        while (!s.contentEquals("1")){
            step++;
            if(s.charAt(s.length()-1)=='0'){
                s=s.substring(0,s.length()-1);
            } else {
                int flagZero = s.lastIndexOf('0');
                StringBuilder sb = new StringBuilder();
                if(flagZero==-1){
                    sb.append("1");
                    for(int i=0;i<s.length();i++){
                        sb.append("0");
                    }
                } else {
                    sb.append(s.substring(0,flagZero));
                    sb.append("1");
                    for(int i=flagZero+1;i<s.length();i++){
                        sb.append("0");
                    }
                }
                s=sb.toString();
            }
        }
        return step;
    }
}
```