##### 利用字符串保存数字，然后分别处理各个字符
```
class Solution {
public:
    int subtractProductAndSum(int n) {
        string number = to_string(n);
        int mul = 1, add = 0;
        for (auto num : number) {
        	mul *= (num - '0');
        	add += (num - '0');
        }
        return mul - add;
    }
};

```