### 解题思路

以数字 21345为例

将数字分解成:
```
0     - 20000 
20000 - 21000
21000 - 21300
21300 - 21340
21340 - 21345
```

![image.png](https://pic.leetcode-cn.com/d02487875bdf1deb0a4319ac5012acfddbb66033e5d5d65e9c2d428cb2cd2213-image.png)

从上图观察,可以得知
当x位不为一时,有明显的规律
当x位位一时,需要加上低位x位的所有值.


### 代码

```cpp
class Solution {
public:
    int countDigitOne(int n) {
        
        int count = 0; //1的个数
        int num = 0;   //当前位的数字
        int c = 0;     //低位之和
        int k = 0;     //第多少位

        while(n){
            num = n%10;
           
           if(num == 1){
                count += c + 1;
            }
            else if(num > 1){
                count = count + pow( 10, k );
            }
            if(num != 0){
                for(int i = 1; i <= k; i++){
                    count = count + num * pow( 10, k - 1);
                }
            }

           // cout << count << " " << num << " " << k <<
           // " " << c  <<endl;  
            c = c + num * pow(10, k);
            k = k + 1;
            n /= 10;
        }

        return count;
    }
};
```