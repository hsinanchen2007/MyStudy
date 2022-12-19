### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/31b763cf68e1b8f9ee747718e0ad4f998418db5e3269dc0a765642984e615d2a-image.png)

### 代码

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9) return n;
        long long  num=9,number=9,cur=9,digit=1,nine=9;
        long long num1=9,number1=9,cur1=9;
        while(number<n){
            //超出后再返回上一步比较麻烦，因此多设了几个变量num1,number1,cur1存储上次循环的各个值
            num1 = num;
            number1 = number;
            cur1 = cur;
            nine = nine*10;
            num = nine*(++digit); //   9*1  90*2  900*3
            number += num;
            cur = 9 + cur*10;  //9   99   999
        }
        num = num1;
        number = number1;
        cur = cur1;
        long long second = (n-number)/digit;
        cur += second;
        int last=(n-number)%digit;
        if(last==0){
            string str_cur = to_string(cur);
            return str_cur.back()-'0';
        }else{
            cur++;
            string str_cur = to_string(cur);
            return str_cur[last-1]-'0';
        }

    }
};
```