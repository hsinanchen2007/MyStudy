### 解题思路
实质上和dp应该也算同源的方法 复杂度是同一量级的
用三个队列分别存放当前访问值乘2、乘3、乘5的值 同时在迭代的过程里取出三个队列里最小的作为下轮访问的值
取出数字的时候需要更新可能的值，为了避免重复插入的情况，比如队列一插入了6，队列二也插入了6 我们只允许从队列一中取出的值乘2、乘3、乘5 队列二中取出的值只允许乘3或乘5 队列三中取出的值只允许乘5

欢迎大家关注我的leetcode仓库～
[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
最近沉迷刷题 同时也在学习和实现lua，欢迎交流

### 代码

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;

        queue<long> q2;
        queue<long> q3;
        queue<long> q5;

        q2.push(2);
        q3.push(3);
        q5.push(5);
        long target = 0;


        for (int i = 1; i < n; i++) {
            long two = q2.front();
            long thr = q3.front();
            long fiv = q5.front();

            target = min(two, thr);
            target = min(fiv, target);

            if (target == two) {
                q2.pop();
                q2.push(target*2);
                q3.push(target*3);
                q5.push(target*5);
            } else if (target == thr) {
                q3.pop();
                q3.push(target*3);
                q5.push(target*5);
            } else {
                q5.pop();
                q5.push(target*5);
            }
        }

        return target;
    }
};
```