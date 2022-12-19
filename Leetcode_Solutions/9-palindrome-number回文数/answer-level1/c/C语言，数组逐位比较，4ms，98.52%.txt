### 解题思路
1. x < 0，false
2. x < 10，true
3. 将 x 从个位起每位放入数组，int取值范围是-2147483647 ~ 2147483647，因此数组长度是10就够了
4. 然后比较数组中 第0个和最后一个，第1个和倒数第二个。。。只要有一个不相等即false
5. 此种解法无需考虑是奇数位还是偶数位，从两端比较，奇数位最中间的不用比较

![截屏2020-04-07上午12.08.59.png](https://pic.leetcode-cn.com/c4b2a12c9ffe671b261e6caf7dce8aeef6bb0fba8d195224341f23a2814c692e-%E6%88%AA%E5%B1%8F2020-04-07%E4%B8%8A%E5%8D%8812.08.59.png)


### 代码

```c
bool isPalindrome(int x){
    if (x < 0) return false;

    if (x < 10) return true;

    int numbers[10];
    int index = 0;
    int src = x;
    while (src) {
        numbers[index] = src % 10;
        src /= 10;
        index++;
    }

    int i = 0, j = index - 1;

    while( i < j) {
        if (numbers[i] != numbers[j]) return false;
        i++;
        j--;
    }
    
    return true;
}
```