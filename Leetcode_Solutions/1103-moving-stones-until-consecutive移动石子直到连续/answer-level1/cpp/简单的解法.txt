![image.png](https://pic.leetcode-cn.com/6ba1bbb5e1928dae2fd59c574f68d76cd85b85e162e13b7ab217cb9f92d804d2-image.png)
分情况讨论即可。
```
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int x=min(min(a,b),c);
        int z=max(max(a,b),c);
        int y=a+b+c-x-z;
        if(y-x==1 && z-y==1) return {0,0};
        if(y-x<=2 || z-y<=2) return {1,z-y+y-x-2};
        else return {2,z-y+y-x-2};
    }
};
```


