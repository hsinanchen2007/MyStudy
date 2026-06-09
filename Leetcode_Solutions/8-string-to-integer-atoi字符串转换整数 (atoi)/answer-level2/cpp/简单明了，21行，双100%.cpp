### 解题思路
解题步骤：
第一步，找到第一个非空白字符
第二步，判断正负号
第三步，转换（注意边界）

符号判断（用较少的空间，表示多个信息）：
flag%2==0为负
flag%2==1为正
flag>=2即数据溢出

边界判断：
因为我们都是先用正数计算，最后才判断符号返回，所以我们的val最多加到INT_MAX（2147483647），
有两种溢出情况：
1、val>INT_MAX/10(214748364)且后面还有数要加时，就可以直接退出循环，标志溢出
2、val==INT_MAX/10(214748364)且后面的数大于7时，不管后面的是什么都可以按最大值处理，标志溢出

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int i,val;
        char flag=1;
        for(i=0; i<str.length() && str[i]==' '; i++);
        if(str[i]=='+' || str[i]=='-')
            flag = (str[i++]=='+')?1:0;   
        for(val=0; !(i>=str.length()||str[i]<'0'||str[i]>'9'); i++){
            if(val>=214748364)
                if(val>214748364||str[i]>'7'){
                    flag+=2;
                    break;
                }
            (val*=10)+=str[i]-'0';
        }
        if(flag>1)
            return flag%2?INT_MAX:INT_MIN;
        return flag%2?val:-val;
    }
};
```