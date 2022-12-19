### 解题思路
执行用时 :4 ms, 在所有 C 提交中击败了100.00% 的用户
内存消耗 :5.1 MB, 在所有 C 提交中击败了100.00%的用户
 加速方法其实是hash的思想：
1、一个是质数判断，10^6最多20bit，一个数组固定记录0~20是否质数，数据再大的话，对应扩展即可；
2、另一个某数中1的个数的判断，0~0xf建立数组记录好，每4bit判断一次，比除法、取模之类的快一些；
   同理，如果数组放大到32个元素，就可以每次算5bit了，还会更快。不过没必要了。
3、get1Counts函数调用改为直接在原函数里展开，也会略快，不过可读性就差了。
### 代码

```c
int count1Map[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
int get1Counts(int n)
{
    int cnt = 0;
    while(n > 0) {
        cnt += count1Map[n&0xf];
        n >>= 4;
    }
    return cnt;
}
int countPrimeSetBits(int L, int R)
{
    int primeMap[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0}; // 0 ~ 20是否质数
    int total = 0;
    for(int i = L; i <= R; i++) {
        int cnt = get1Counts(i);
        total += primeMap[cnt];
    }
    return total;
}
```