### 解题思路
用例真恶心
### 代码

```cpp
class Solution {
public:
    bool isNumber(string s) {
        //去头尾空格
        s.erase(0,s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ')+1);
        if(s.empty()) return false;

        bool point = false;     //是否出现小数点
        int e = -1;             //e的位置
        bool res = false;       //是否出现数字
        int size = s.length();
        for(int i = 0; i < size; i++)
        {   
            if(s[i]=='+'||s[i]=='-')
            {
                if(i!=e+1) return false;    //如果+-出现的位置不是0或者e后面，则不符
            }
            else if(s[i] == '.')
            {
                if(point||e!=-1) return false;  //若小数点出现时已有小数点或者小数点在e后面，则不符
                point = true;
            }
            else if(s[i]=='e')
            {
                if(!res || e != -1) return false;   //若e出现之前没有数字或者已出现e，则不符
                res = false;                        //重置数字为未出现，以判断e后面是否有数字出现
                e = i;
            }
            else if(s[i]<'0'||s[i]>'9')
            {
                return false;                       //出现非法字符
            }
            else
            {
                res = true;                         //出现数字
            }
        }
        return res;        //未出现数字则为false
        
    }
};
```