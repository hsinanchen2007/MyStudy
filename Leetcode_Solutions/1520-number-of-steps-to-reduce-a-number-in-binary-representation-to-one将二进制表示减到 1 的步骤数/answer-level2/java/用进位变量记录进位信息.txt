### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numSteps(String s) {
// 1结尾：且只有一位时，结束。
            //       有多位时，直接将step+2，并且字符串去除掉最右边位，且进位。
            // 0结尾的情况，step+1，并且去掉最右边位，前一位置为1，且进位。
            int step = 0;
            char[] chars = s.toCharArray();

            boolean flag = false; // 是否进位
            for( int i=s.length()-1; i>=0; i-- ){
                if((i==0 && chars[i] == '1' && !flag)  || (i==0 && chars[i]=='0' && flag) ) break;
                else if( i==0 && chars[i]=='1' && flag ){
                    step++;
                    break;
                }
                else if( (i!=0 && chars[i] == '1' &&  !flag)  || (i!=0 && flag && chars[i] == '0') ) { // 此位为1
                    step+=2;
                    flag=true;
                }
                else if(!flag && chars[i] == '0' ){ // 此位为0
                    step+=1;
                    flag=false;
                }
                else if(flag && chars[i]=='1' ){
                    step+=1;
                    flag =true;
                }
            }
            return step;
    }
}
```