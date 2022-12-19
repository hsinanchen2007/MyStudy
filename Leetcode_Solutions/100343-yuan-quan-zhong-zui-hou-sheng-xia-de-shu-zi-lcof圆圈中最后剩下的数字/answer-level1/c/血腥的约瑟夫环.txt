### 解题思路
最开始使用的是模拟循环链表的方法，可惜测试用例大范围给得太恐怖，数字稍微大一点就超时

后面学习了*[约瑟夫环](https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/huan-ge-jiao-du-ju-li-jie-jue-yue-se-fu-huan-by-as/)*递推公式：
![1.png](https://pic.leetcode-cn.com/0447740d7ccda72a0cc426ee50e14243c84154b964a1725dfdafc2a4eeeba914-1.png)


### 代码

```c
int lastRemaining(int n, int m){
    if(n==1) return 0;
    return (lastRemaining(n-1,m)+m)%n;
}
```
```c
//这时不赞成的一种方式，会超时
int lastRemaining(int n, int m){
    if(m==1) return n-1;
    int i,pointer;
    int *p=(int*)malloc(n*sizeof(int));
    for(i=0;i<n-1;i++) p[i] = i+1;
    p[n-1]=0;
    pointer=0;
    int count=m-1;
    while(p[pointer]!=p[p[pointer]]){
        if(count==1){
            p[pointer]=p[p[pointer]];
            count=m;
            continue;
        }
        pointer=p[pointer];
        count--;
    }
    return pointer;
}
```
