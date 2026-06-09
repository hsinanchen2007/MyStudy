![image.png](https://pic.leetcode-cn.com/86b9d4004416a297746aff9a9f0c02c305c516a71c119d2f4cd1e95366947628-image.png)    

解法:对于任何一个`num`,从左往右遍历每一位,将第一次出现的6改为9,就可以得到最大输出结果.    

```
class Solution {
public:
    bool flag;
    int maximum69Number (int num) {
        flag = false;
        iterate(num);
        return num;
    }

    void iterate(int &num){
        if(num==0) return;
        int a = num % 10;
        num /= 10;
        iterate(num);
        if(!flag && a==6) {
            a = 9;
            flag = true;
        }
        num *= 10;
        num += a; 
    }
};
```
