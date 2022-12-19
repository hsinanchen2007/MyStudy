### 解题思路
题目逻辑很简单，用if else对奇，偶数进行分类讨论，其中偶数除以二的操作用移位运算符可以简化复杂度

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
       int count=0;
       while(num!=0) 
       {
           if(num%2==0)
        {
            num=num>>>1;
            count++;
        }
           else
        {
            num--;
            count++;
        }
       }
    return count;
    
    
    }
}
```