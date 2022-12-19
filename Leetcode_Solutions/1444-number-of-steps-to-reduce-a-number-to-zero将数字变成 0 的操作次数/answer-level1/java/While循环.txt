### 解题思路
While循环  
  判断num不为0时 每次循环执行次数sum加一 
  判断num 为偶数则除以2 为奇数减1 
一直执行到num=0 跳出循环 返回sum

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int sum=0;
     while(num!=0){
         sum++;
         if(num%2==0){
                num=num/2; 
         }
         else{
             num=num-1;
    
         }
     

     }
     return sum;
    }
}
```