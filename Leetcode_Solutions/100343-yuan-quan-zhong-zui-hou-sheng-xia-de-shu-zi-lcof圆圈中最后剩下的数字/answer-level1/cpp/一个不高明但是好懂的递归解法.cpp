先上代码：
```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        return helper(0,n,m-1);
    }
    int helper(int start, int n, int m){//传 m-1
        if(n==1)
            return 0;
        int del=(start+m)%n;
        int subRes=helper(del, n-1, m);
        if(subRes>=del)
            return subRes+1;
        return subRes;
    }
};
```


---

---


假设初始n为7，即初始状态剩下的数字为：
![image.png](https://pic.leetcode-cn.com/0a512cb009c22b6cc5243f8c323b34d1234a1756b4174ce0b788634ff5003645-image.png)

假设我们计算出当前要杀死的数字是3，则杀死当前数字后，剩下的数字为：
![image.png](https://pic.leetcode-cn.com/395c045fccb304f71e398122f2ded17051941f11461d1829ff75341a8205d879-image.png)


杀死一个数字后，n的规模减小为6，我们递归的求解规模更小的子问题，再利用子问题的结果求解当前结果。问题规模n为6时，对应的数字为：
![image.png](https://pic.leetcode-cn.com/041c522ea3bb980a7524a1fd27d402ee9eca2f2ecdebf3f7348793ca978ff8bf-image.png)

我们发现，子问题中的后三个数字，和当前剩余数字中的后三个数字是不一样的，其余数字是一样的：
![image.png](https://pic.leetcode-cn.com/9392997f590fe924c4337a9b9e4e97f2d8df49623cf02bba8881d88457104afc-image.png)
虽然不一样，但是有对应关系，对应关系为子问题中的数字加一等于剩余数字中的数字。

所以，我们求得子问题的解后，判断解是不是子问题的后三个数字，如果是，就让子问题的解加1，如果不是，直接返回子问题的解就好了。

