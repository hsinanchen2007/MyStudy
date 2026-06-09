### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
      bool isUgly(int num) {            //迭代
        if(num==1) return true;
        int tmp;
        while(num!=1){
            tmp=num;
            if(num%5==0) num/=5;
            else if(num%3==0) num/=3;
            else if(num%2==0) num/=2;
            if(tmp==num) return false;  //2,3,5一个也不能除的说明这个不符合
        }
        return true;
    }
    bool isUgly(int num) {              //把属于2，3，5的全消掉，再判断是否等于1
        if (num == 0) return false;
        while (num % 2 == 0) num /= 2;
        while (num % 3 == 0) num /= 3;
        while (num % 5 == 0) num /= 5;
        return num == 1;
    }
    bool isUgly(int num){              //基于迭代的递归
        if(num==1) return true;
        int tmp=num;
        if(num%5==0) num/=5;
        else if(num%3==0) num/=3;
        else if(num%2==0) num/=2;
        if(tmp!=num) return true && isUgly(num);
        else return false;
    }
};
```