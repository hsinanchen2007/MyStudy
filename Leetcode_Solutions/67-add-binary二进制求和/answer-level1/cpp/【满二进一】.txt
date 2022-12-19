# 思路
1. 一开始我们使得a的长度大于b的长度
2. 比较短的=>补零
3. 从最后一位出发，满二进一(通过status和high分别记录进位&余位)
```
class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();
        if(lenA < lenB) return addBinary(b , a);
        string result;
        
        int status = 0;  // 进位
        int high = 0;  // 余位
        int temp = 0;

        for(int i = 0; i < lenA - lenB; i++)  // 补零
        {
            b = '0' + b;
        }
        
        int pointer = lenA - 1;
        while(pointer >= 0)
        {
            temp = a[pointer] - '0' + b[pointer] - '0' + status;
            switch(temp)
            {
                case 0 : 
                {
                    status = 0;
                    high = 0;
                    break;
                }
                case 1 : 
                {
                    status = 0;
                    high = 1;
                    break;
                }
                case 2 : 
                {
                    status = 1;
                    high = 0;
                    break;
                }
                default : 
                {
                    status = 1;
                    high = 1;
                }
            }
            result =  to_string(high) + result;
            if(pointer == 0) result = (status ? to_string(status) : "")  + result;
            pointer--;
        }
        return result;
    }
};
```

代码优化：
*通过观察发现，status和high的赋值有逻辑，因此优化代码如下*
```
high = temp % 2;
status = temp < 2 ? 0 : 1;
```
最终代码：
```
class Solution {
public:
    string addBinary(string a, string b) {
        int lenA = a.size();
        int lenB = b.size();
        if(lenA < lenB) return addBinary(b , a);
        string result;
        
        int status = 0;  // 进位
        int high = 0;  // 余位
        int temp = 0;

        for(int i = 0; i < lenA - lenB; i++)  // 补零
        {
            b = '0' + b;
        }
        
        int pointer = lenA - 1;
        while(pointer >= 0)
        {
            temp = a[pointer] - '0' + b[pointer] - '0' + status;
            high = temp % 2;
            status = temp < 2 ? 0 : 1;
            result =  to_string(high) + result;
            if(pointer == 0) result = (status ? to_string(status) : "")  + result;
            pointer--;
        }
        return result;
    }
};
```

