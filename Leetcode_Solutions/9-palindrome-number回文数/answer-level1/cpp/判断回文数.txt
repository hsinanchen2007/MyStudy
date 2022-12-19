### 解题思路
用取余数，放入字符数组（因为考虑有负号），再通过比较前后头尾两个字符是否相同来判断
此时数组放着的字符数与题目给的数字顺序是相反的

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        char Array[10000];
        int size = 0;
        int m_iNum = x;
        while(m_iNum!=0){
            Array[size] = m_iNum%10+'0';//取余数，放置相反位置数字 这里是一个字符数组 算出来的数还要变成字符才行
            m_iNum/=10;//取个位前面的数
            size ++;
        }
        if(x<0){
            Array[size] = '-';//如果是负数怎么办，加个负号在末尾
            size+=1;
        }
        for(int i = 0;i<size;i++){
            if(Array[i] != Array[size-1-i]){//如果不是相等就输出false
                return false;
            }
        }
        return true;
    }
};
```