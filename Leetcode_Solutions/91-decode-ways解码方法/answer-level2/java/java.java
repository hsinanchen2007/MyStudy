### 解题思路


### 代码

```java
class Solution {
    public int numDecodings(String s) {
        /*
            用f(num)表示解码方法数
            f(111) 添加数字6 => f(1116) 等价于 f(111)+单独6 加上 f(11)+f(16)
            f(1118 2229) 等价于 f(1118) * f(2229) 因为 f(82)不存在
        */

        if(s.length() == 1){
            return s.equals("0")?0:1;
        }
        
        int[] f= new int[s.length()+1];
        f[0] = 1;
        f[1] = 1;
        for(int i=2 ; i<=s.length() ; i++){
            f[i] = f[i-1]+f[i-2];
        }
        
        int last = 0;
        int start = -1; //区间长度需-1
        int res = 1;
        
        for(int i=0 ; i<s.length() ;i++){
            int num = s.charAt(i)-'0';
            if(num == 1 || num == 2){
                if(i == s.length()-1){
                    res *= f[i-start];//尾处理
                }
                //无需重置start
            }else{
                if(num == 0){
                    if(last != 1 && last != 2){
                        return 0; 
                    }
                    res *= f[i-start-2];// 0无法单独存在会绑定前一个1或2
                }else if( last == 1 ){
                    res *= (f[i-start]);// (start,i)区间内全为1和2，组合个数为 f[i-start]
                }else if( last == 2){
                    res *= num<7 ? f[i-start] : f[i-start-1];// 大于7的数和2无法绑定
                }
                start = i;
            }
            last = num;
        }
        return res;
    }
}
```