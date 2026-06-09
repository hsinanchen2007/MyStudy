### 解题思路
好坑啊这道题，我一直没明白那个returnSize,还是一个指针不知道什么意思。。。原来直接将num_people赋值即可/笑哭
此外通过本题又补上了一个知识点：
在函数内部声明的数组若作为返回值要注意，当该函数调用完毕了会**释放**这个函数占用的空间，此时去访问这个地址将会返回
*runtime error: load of null pointer of type 'int'*之内错误提示。

在dev C++中测试了一下：
![2.png](https://pic.leetcode-cn.com/d32411a81efa3f3756e3802a683eeda5b2e2abef628a9add5621120ad85eac35-2.png)
![1.png](https://pic.leetcode-cn.com/a744186f8f7b1689dff29f1c7edf99f299b8f03d0669ae11ad1beb3db366b1c0-1.png)
可以看到输出了乱码

应该用malloc()来动态分配内存空间，并用memset()来赋值，注意对于memset()中第一个参数若是int类型或short，即单位内存空间4大于一个字节的，一般只能赋值0或-1。若赋值1了，每个int的值会变为00000001 00000001 00000001 00000001。

参考：

- [runtime error: load of null pointer of type 'const int' 错误提示](https://blog.csdn.net/qq_34824576/article/details/86496130)
- ![string.h中int数组使用memset()使用注意！！！.png](https://pic.leetcode-cn.com/e0c3fed26fd67f0799df26debeb3653b88228215b3d7a0de07f6c952d4409698-string.h%E4%B8%ADint%E6%95%B0%E7%BB%84%E4%BD%BF%E7%94%A8memset\(\)%E4%BD%BF%E7%94%A8%E6%B3%A8%E6%84%8F%EF%BC%81%EF%BC%81%EF%BC%81.png)
### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    int X=1,i=0;
    int *result;
    result=(int*)malloc(sizeof(int)*num_people);
    memset(result,0,sizeof(int)*num_people);
    while(X<=candies){
        result[i%num_people]+=X;
        candies-=X;
        i++;
        X++;
    }
    if(candies>0) result[i%num_people]+=candies;

    *returnSize=num_people;
    return result;
}
```