其实当n<4的时候，可能性都很显然，而当大于4的时候，就比较麻烦，我们可以反向思维，用 当前栅栏的总可能 - 此处违规的可能 得出答案。
当前的总可能为 k * （n - 1 个栅栏的合规可能），而此处违规的可能前提为前两个栅栏同色 ，所以为（n - 3处合规的可能 * k）- 提前违规的可能，即（n - 3处合规的可能 * 1）（因为前两个栅栏同色， 任何n - 3处合规的可能都可能会提前违规）


```
class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0) return 0;
        if(n == 1) return k;
        if(n == 2) return k * k;
        if(n == 3) return k * k * k - k;
        return k * numWays(n - 1, k) - numWays(n - 3, k) * (k - 1);
    }
};
```
