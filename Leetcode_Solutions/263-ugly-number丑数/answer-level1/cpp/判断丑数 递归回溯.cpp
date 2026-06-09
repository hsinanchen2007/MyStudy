### 解题思路
递归和回溯。
因为最大的数不超过2^31-1，所以递归层数不会超过31次，所以效率不会很低。
![image.png](https://pic.leetcode-cn.com/dd4e44dad166168890da1d73392ae012b7d3a64285caea55144941afce95bfd0-image.png)

### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) {
        if(num<1) 
            return false;
        return search(num);//开始递归
    }
    bool search(int num)
    {
        if(num==1) 
            return true//递归终止
        if(num%2!=0 && num%3!=0 && num%5!=0 ) 
            return false;//不是2，3，5的倍数，说明这条路走不通，返回上一层。
        else 
            return num%2==0?search(num/2):false || num%3==0?search(num/3):false || num%5==0?search(num/5):false;//递归调用
    }
};
```