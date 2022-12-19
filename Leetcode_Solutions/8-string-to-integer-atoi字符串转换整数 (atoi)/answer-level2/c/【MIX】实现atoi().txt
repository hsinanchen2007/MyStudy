### 解题思路
1. 去空白+定符号+边界判定+值计算
2. 正则表达式

### 代码

```java []
class Solution {
    public int myAtoi(String str) {
        if(str == null || str.length()==0)
            return 0;

        // 去除空白, 直接调用trim()
        str = str.trim();
        if(str.length()==0)
            return 0;

        long res = 0L;
        int index = 0;
        int sgn = 1;
        
        // 符号判断
        if(str.charAt(index) == '+'){
            ++index;
            sgn = 1;
        }else if(str.charAt(index)=='-'){
            ++index;
            sgn = -1;
        }else if(!Character.isDigit(str.charAt(index))){
            return 0;
        }

        for(int i=index; i<str.length(); ++i){
            if(Character.isDigit(str.charAt(i))){
                res = res*10+(str.charAt(i)-'0');
                if(res*sgn > Integer.MAX_VALUE || res*sgn < Integer.MIN_VALUE)
                    return sgn==1? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }else{
                break;
            }
        }
        return (int)res*sgn;
        
    }
}
```
```python []
class Solution:
    def myAtoi(self, str: str) -> int:
        if str == None or len(str) == 0:
            return 0
        
        # 去除空白
        str = str.strip()
        if(len(str) == 0):
            return 0
        
        # 定义符号
        index = 0
        sgn = 1
        
        if str[index] == '+':
            index +=1
            sgn = 1
        elif str[index] == '-':
            index +=1
            sgn = -1
        elif str[index].isdigit() is False:
            return 0

        res = 0
        MAX_INT = 2**31-1
        MIN_INT = -2**31

        for i in range(index, len(str)):
            if str[i].isdigit():
                res = res*10 + int(str[i])
                if sgn*res < MIN_INT or sgn*res > MAX_INT:
                    return MIN_INT if sgn == -1 else MAX_INT
            else:
                break

        return res*sgn
```
```c []
typedef long long ll;
int myAtoi(char * str){
    // 定义极值
    static const int MAX_INT = (int)((unsigned)~0>>1);
    static const int MIN_INT = -(int)((unsigned)~0>>1)-1;

    if(str == NULL || sizeof(str)==0)
        return 0;

    // space
    while(isspace(*str))
        ++str;

    int sgn = 1;
    if(*str == '+')
        ++str;
    else if(*str == '-'){
        sgn = -1;
        ++str;
    }else if(!isdigit(*str)){
        return 0;
    }

    ll res = 0L;
    while(isdigit(*str)){
        res = res*10+*str-'0';
        if(sgn * res >= (ll)MAX_INT || sgn * res <= (ll)MIN_INT)
            return sgn == 1?MAX_INT:MIN_INT;
        ++str;
    }
    return (int)(res*sgn);
}
```
```c++ []
#include <cassert>
typedef long long ll;
class Solution {
public:
    int myAtoi(string str) {
        if(str.length()==0)
            return 0;
        // 去除空白字符
        int start=0, end=str.length()-1;
        while(start < end){
            if(isspace(str[start]))
                ++start;
            else if(isspace(str[end]))
                --end;
            else
                break;
        }
        // 不能有效转换
        if(start > end)
            return 0;
        
        // 处理正负号, 默认为postive
        int sgn = 1;
        while(start < end){
            if(str[start] == '+'){
                sgn = 1;
                ++start;
                break;
            }else if(str[start] == '-'){
                sgn = -1;
                ++start;
                break;
            }else if(isdigit(str[start])){
                break;
            }else{
                return 0;
            }
        }

        assert(start <= end);
        ll res = 0;
        for(int i=start; i<=end; ++i){
            if(isdigit(str[i])){
                res = res*10+str[i]-'0';
                if(sgn * res > INT32_MAX || sgn * res < INT32_MIN)
                    return sgn==1 ? INT32_MAX : INT32_MIN;
            }else{
                break;
            }
        }
        return sgn*res;
    }
};
```
**正则表达式**
```python []
class Solution:
    def myAtoi(self, str: str) -> int:
        # 使用正则表达式匹配
        import re
        str = str.strip()
        Vmax = pow(2, 31)-1
        Vmin = -pow(2, 31)
        res = re.match(r'[-+]?\d+', str)
        if res:
            if int(res.group())<=Vmax and int(res.group())>=Vmin: 
                return int(res.group())
            else:
                return Vmin if int(res.group())<0 else Vmax
        else: return 0
```
```python []
class Solution:
    def myAtoi(self, str: str) -> int:
        # 正则表达式<间洁>
        import re
        return max(min(int(*re.findall(r'^[+-]?\d+', str.strip())), 2**31-1), -2**31)
```