### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/ba9ea94c3adcf32e20499017b1b46b59db8e37c4e3a63c890383c7f091a55142-image.png)

### 代码

```cpp
class Solution {
public:
    int numberOfSteps (int num) {
        int times = 0;
        do{
            if(num%2)--num;
            else num /=2;
            times++;
        }while(num);
        return times;
    }
};
```