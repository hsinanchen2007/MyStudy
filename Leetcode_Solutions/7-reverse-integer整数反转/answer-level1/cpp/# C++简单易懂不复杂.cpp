### 解题思路
此处撰写解题思路

### 代码

# C++基础解法，只是设了一个long
class Solution {
public:
    int reverse(int x) {
        long  result(0);
        
        while(x!=0){
            result=result*10+x%10;//result*10移向高位，然后取出新的末尾
            x/=10;//取出末尾后去掉最后一位
        }
        if(result>INT_MAX||result<INT_MIN)
            return 0;
        else
            return  result;
    }
};
```