![捕获.PNG](https://pic.leetcode-cn.com/a8570d7ccc24fb04bee02329e0e4d79467944adf5f3833fde88669ffcf9cee07-%E6%8D%95%E8%8E%B7.PNG)

```
class Solution {
public:
    int numberOfSteps (int num) {
        int k = 0;
        while(num > 0){
            num%2==0?num/=2:num-=1;
            k++;
        }
        return k;
    }
};
```
