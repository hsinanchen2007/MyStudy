### 解题思路
循环直到i*i=num
当num<i*i的时候返回false
![image.png](https://pic.leetcode-cn.com/a06cd2eb86a431d3a34b866c4d7953885f70d7fbfbf59a301255a39f481fd75d-image.png)


### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        int res;
        int i = 1;
        if(num==2147483647){return false;}

        while(1){
            if(num == i*i){
                return true;
            }
            if(num<i*i){
                return false;
            }
            i++;
        }
    }
};
```