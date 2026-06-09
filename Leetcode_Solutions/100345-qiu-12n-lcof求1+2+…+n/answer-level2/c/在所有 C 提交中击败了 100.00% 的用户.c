### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/99915981e70c4eb2291c31a30f4f9f8d1fd45b1f0d2a9727e5586e3f777a1262-image.png)


### 代码

```c
int sumNums(int n)
{
    int sum = n;
    n && (sum += sumNums(n-1));
    return sum;
}
```