### 解题思路
1. 周赛的时候， 没有sqrt。  超时。
2. 如果是完全平方数，直接break。 因为因子重复了。 完全平方数 就是 4，9，16，25这些数。
3. 判断因子个数， 如果是4个，就相加。
4. 为什么可以sqrt 比如 24的因数有1、2、3、4、6、8、12、24.     1×24、2×12、3×8、4×6 。只用判断小于sqrt的数就可以了。比如2和12， 计算出来2是， 那么就把12也一起加了。
5.  比如一个数的约数在其开方的右边，那必然会存在一个一个约数在其开方的左边。 
![无标题.png](https://pic.leetcode-cn.com/1590b226cbf9e0aab4e8f2ff67661c3107a4b322e7e2d46e245c732c7f36c521-%E6%97%A0%E6%A0%87%E9%A2%98.png)

### 代码

```c
int sumFourDivisors(int* nums, int numsSize){
    int ret = 0;
    int cnt = 1;
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        int temp = nums[i];
        int num = sqrt(temp);
        for (int j = 2; j <= num; j++) {
            if (num * num == temp) {
                break;
            }
            if (temp % j == 0) {
                cnt++;
                sum += j + (temp / j);
                
            }
            if (cnt > 2) {
                break;
            }
        }
        if (cnt == 2) {
            ret += 1 + temp + sum;
        }
        sum = 0;
        
        cnt = 1;
    }
    
    return ret;
}
```