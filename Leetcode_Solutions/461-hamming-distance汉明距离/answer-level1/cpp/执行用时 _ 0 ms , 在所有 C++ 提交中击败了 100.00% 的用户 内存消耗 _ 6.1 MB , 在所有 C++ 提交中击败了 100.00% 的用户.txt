### 解题思路
x和y的汉明距离其实就是x和y异或之后得出的z的二进制位有多少个1嘛。
我们只需要求出x和y的异或结果z，再将z的二进制形式转换成字符串，用count函数查找字符串内有多少个'1'即可。

### 代码

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        
        int z=x^y;
        string str="";
        
        while(z>0)
        {
            int temp=z%2;
            
            switch(temp)
            {
                case 0:
                    str+="0";
                    break;
                case 1:
                    str+="1";
                    break;
            }
            
            z/=2;
        }
        
        return count(str.begin(),str.end(),'1');

    }
};
```