### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/a17597b52156aa04190ac228f834b53968344a428fca376e293e24e6cffcf060-image.png)

不理解这个执行时间怎么算的，这么传统的方法为什么就100%了？
### 代码

```cpp
class Solution {
public:
    bool isUgly(int num) {
        if(num<=0){
            return false;
        }
        while(num!=1){
            if(num % 2 == 0){
                num/=2;
            }else if(num % 3 == 0){
                num/=3;
             }else if(num % 5 == 0){
                num/=5;
            }else{
                return false;
            }
        }
        return true;
    }
};
```