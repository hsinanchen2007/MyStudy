![image.png](https://pic.leetcode-cn.com/97309de16a3db029755d19b4939488839a01470101d51cf37f95cb03b0479390-image.png)
直接递归解决问题
```
class Solution {
public:
    int addDigits(int num) {
        if(num < 10) return num;
        
        int temp = 0;
        while(num > 0){
            temp += num % 10;
            num /= 10;
        }
        return addDigits(temp);
    }
};
```
