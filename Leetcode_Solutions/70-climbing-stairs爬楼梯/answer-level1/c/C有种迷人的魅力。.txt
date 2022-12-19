### 解题思路
此处撰写解题思路
![QQ截图20200322175134.png](https://pic.leetcode-cn.com/706f0a44b23c5e15defb136258b3565f0b9deb47f0297affe011d1e7e9efea03-QQ%E6%88%AA%E5%9B%BE20200322175134.png)

### 代码

```c
int climbStairs(int n){
    unsigned int a=1,b=2;
    int ans,i;
    if(n==1){
        return 1;
    }
    for(i=1;i<n;i++){
        ans=b;
        b=a+b;
        a=ans;
    }
    return ans;

}
```