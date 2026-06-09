### 解题思路
第一次解法（行不通）：
把二进制数通过Math.pow转化为十进制数
之后偶数除二，奇数加一，
发现该解法超时，行不通。



第二次解法（行的通）：
仔细分析，发现二进制数只有第一位为1时才为奇数，且二进制10000除于2为1000，1000除于2为100
所以直接在二进制数的基础上进行运算
规则：
当第一位为1时，二进制数加一（11加一变100，101加一变110)，次数加一count++
当第一位为0时，二进制数除二（直接截取字符串s（100变10）），次数加一count++
当二进制数为1时，即字符串为1时，返回结果count
### 代码

```java
class Solution {
    public int numSteps(String s) {
        int count = 0,s_len = s.length();
        if(s_len==1){
            return 0;
        }
        StringBuilder sb = new StringBuilder(s);
        for(int i=s_len-1;i>0;i=s_len-1){
            if(sb.charAt(i)=='1'){
                sb.replace(i,i+1,"0");
                for(int j=i-1;j>=0;j--){
                    if(sb.charAt(j)=='1'){
                        if(j==0){
                            sb.replace(j,j+1,"0");
                            sb = new StringBuilder("1"+sb);
                            s_len = sb.length();
                            count++;
                        }else {
                            sb.replace(j,j+1,"0");
                        }
                    }else {
                        sb.replace(j,j+1,"1");
                        count++;
                        break;
                    }
                }
            }else {
                sb = sb.delete(i,i+1);
                count++;
                s_len--;
            }
        }
        return count;
    }
}
```