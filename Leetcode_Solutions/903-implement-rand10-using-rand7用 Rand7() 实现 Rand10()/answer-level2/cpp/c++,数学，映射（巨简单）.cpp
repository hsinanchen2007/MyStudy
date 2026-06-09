### 解题思路
1到7的数据无法表示1到10，但随机取两次，就能表示最多49个数字.（设两次的数字为tp1和tp2）
想法很简单，所以实现起来的方法有很多种，比如
（1）下面就是取第一次1，2，3；第二次1，2，3，4（舍去其他情况），有12种情况，舍去(1,1)和(3,4),剩下的10种情况映射到1到10就是tp2-1+(tp1-1)*4.
（2）方法一舍去的情况有些多，其实可以第一次取奇偶性，第二次的1到5，产生2*5=10种结果，对应的方程就是5*(tp1%2)+tp2，效率快了很多
(3)总之有很多种方法，做对了就行，大家可以多尝试

### 代码

```cpp
// 方法一

class Solution {
public:
    int rand10() {
        int tp1,tp2;
        while(1){
            tp1=rand7();
            tp2=rand7();
            if(tp1>3||tp2>4||tp1+tp2==2||tp1+tp2==7)continue;
            return  tp2-1+(tp1-1)*4;
        }
    }
};
```

```cpp
//方法二

class Solution {
public:
    int rand10() {
        int tp1,tp2;
        while(1){
            tp1=rand7();
            tp2=rand7();
            if(tp1==7||tp2>5)continue;
            return  5*(tp1%2)+tp2;
        }
    }
};
