## 不使用循环
**以38为例：38=3×10+8=3×9+3+8=4×9+2，所以38%9=2就是答案**
```cpp
class Solution {
public:
    int addDigits(int num) {
        if(num>9){
            int ans = num%9;
            if(ans==0) return 9;
            else return ans;
        }
        return num;
    }
};
```
## 模拟法----使用循环
```cpp
class Solution {
public:
    int addDigits(int num) {
        int res=0;
        while(num>=10){
            res=0;
            while(num){
                int temp=num%10;
                res+=temp;
                num/=10;
            }
            num=res;
        }
        return num;
    }
};
```