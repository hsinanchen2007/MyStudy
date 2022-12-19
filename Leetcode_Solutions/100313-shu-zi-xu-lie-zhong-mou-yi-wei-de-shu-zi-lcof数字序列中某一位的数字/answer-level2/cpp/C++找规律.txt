### 解题思路
注意强制转换

### 代码

```cpp
class Solution {
public:
    int findNthDigit(int n) {
        if(n<0) return -1;
        int a=n;
        int k=1;
        while(a>k*9*pow(10,k-1))
        {
            a=a-k*9*pow(10,k-1);
            k++;
        }
        int num=pow(10,k-1)+(a/k-1);//这个数
        int m=a%k;//第几位
        if(m==0) return num%10;
        num++;
        
        for(int i=1;i<m;++i)
        {
            num=num-pow(10,k-i)*(int)(num/pow(10,k-i));
        }
        
        return num/pow(10,k-m);
    }
};
```