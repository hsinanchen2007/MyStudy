简单易懂的实现。
```java
class Solution {
    public int myAtoi(String str) {
        int len = str.length();
        int first = 1;//判断是否进入数字识别
        int flag = 1;//存储结果的正负
        int ans = 0;//存储结果
        for(int i=0;i<len;++i){
            char temp = str.charAt(i);
            if(first==1){
                if(temp==' ')//空格跳过
                    continue;
                else if(temp=='+'){
                    flag = 1;
                }else if(temp=='-'){
                    flag = -1;
                }else if(temp>='0' && temp<='9'){
                    ans = ans*10 + (int) (temp-'0');
                }else{//其他情况直接返回0
                    return 0;
                }
                first = 0;//进入数字识别
            }
            else{
                if(temp>='0' && temp<='9'){//进入数字识别后识别到的是数字，继续
                    //判断越界情况。需要注意的是Integer.MAX_VALUE/10 等于 Integer.MAX_VALUE/10。思路同上一题
                    //这里是判断正数越界
                    if(flag==1 && (ans>Integer.MAX_VALUE/10 || (ans==Integer.MAX_VALUE/10 && temp>'7')))
                        return Integer.MAX_VALUE;
                    //这里是判断负数越界。
                    if(flag==-1 && (ans>Integer.MAX_VALUE/10 || (ans==Integer.MAX_VALUE/10 && temp>'8')))
                        return Integer.MIN_VALUE;
                    ans = ans*10 + (int) (temp-'0');
                }else{//识别的不是数字，直接返回结果
                    return flag*ans;
                }
            }
        }
        return flag*ans;
    }
}
```
