### 思路
本题计算的结果就分为两种，
1. 到1的时候进入循环（即1，1，1……循环），返回true
2. 到非1的时候进入循环，返回false
- 因为都会产生循环，直到开始进入循环的点跳出循环，检查开始进入循环的点是否是1，若是1，n就是快乐数，若不是，n就不是快乐数
```
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> bobo;
        while(!bobo.count(n)){
            int sum = 0;
            bobo.insert(n);
            while(n != 0){
                sum = sum + (n%10) * (n%10);
                n /= 10;
            }
            n = sum;
        }
        return n == 1;
    }
};
```
代码二
```
//递归
class Solution {
public:
    unordered_set<int> bobo;
    bool isHappy(int n) {
        int sum = 0;
        if(n == 1) return true;
        else if(bobo.count(n))  return false;
        else{
            bobo.insert(n);
            while(n != 0){
                sum = sum + (n%10) * (n%10);
                n /= 10;
            }
            n = sum;
        }
        return isHappy(n);
    }
};
```

