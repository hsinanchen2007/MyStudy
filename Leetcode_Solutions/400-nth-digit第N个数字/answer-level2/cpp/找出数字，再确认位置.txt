### 解题思路
根据题解里面的思路写的，但是想再记录一下
1.观察 1位数有9个，2位数有90个，3位数有900个，依次类推
```
找到该位置是几位数
int i=1;
while(n>pow(10,i-1)*9*i)
{
    n-=pow(10,i-1)*9*i;
    i++;
}
```
2.找出是哪个数字
```
int num=pow(10,i-1)+n/i;
```
3.通过计算余数找到在数字的哪个位置
```
int m=n%i;
```

### 代码

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        int i=1;
        while(n>pow(10,i-1)*9*i)
        {
            n-=pow(10,i-1)*9*i;
            i++;
        }
        int num=pow(10,i-1)+n/i;//找出是哪个数字
        int m=n%i;//找出在数字的哪个位置
        if(m==0)//如果无余数，说明刚刚好是前一个数字的最后一位
        {
            num--;
            m=i;
        }
        return to_string(num)[m-1]-'0';
    }
};
```