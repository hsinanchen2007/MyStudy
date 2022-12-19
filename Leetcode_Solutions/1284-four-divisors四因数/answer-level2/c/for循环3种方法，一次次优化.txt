### 解题思路
1、数字1、2肯定不满足四因子；2以上的数字，1和本身肯定是因子，所以只需要遍历查找2及num-1中满足2个因子的即可
2、1有一个用例会超时，对遍历进行优化。从2至num/2遍历即可
3、对2方法进一步优化，从2至sqrt(num)遍历，但需要考虑刚好能开根号的场景，这个时候只能算一个因子

### 代码
方法1：
![1.PNG](https://pic.leetcode-cn.com/c1e83ce767543fbfc5a34c87ee431149ecf2b685cf9c25996d880d3eb6d911c4-1.PNG)

int four_divisors(int num)
{
    int i;
    int cnt = 0;
    int sum = 0;
    
    if (num == 1 || num == 2) {
        return 0;
    }
    
    for (i = 2; i < num; i++) {
        if (num % i == 0) {
            cnt++;
            if (cnt > 2) {
                return 0;
            }
            sum += i;
        }
    }
    
    if (cnt == 2) {
        sum = sum + 1 + num;
        return sum;
    } else {
        return 0;
    }
}

int sumFourDivisors(int *nums, int numsSize)
{
    int i;
    int sum = 0;

    for (i = 0; i < numsSize; i++) {
        sum += four_divisors(nums[i]);
    }
    
    return sum;
}
方法2：
![2.PNG](https://pic.leetcode-cn.com/ce9d71a470194994c3b8215cf3ec752b7111c02350f94a6a30907d40bcb96646-2.PNG)
int four_divisors(int num)
{
    int i;
    int cnt = 0;
    int sum = 0;
    
    if (num == 1 || num == 2) {
        return 0;
    }

    for (i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            cnt++;
            if (cnt > 2) {
                return 0;
            }
            sum += i;
        }
    }
    
    if (cnt == 2) {
        sum = sum + 1 + num;
        return sum;
    } else {
        return 0;
    }
}

int sumFourDivisors(int *nums, int numsSize)
{
    int i;
    int sum = 0;

    for (i = 0; i < numsSize; i++) {
        sum += four_divisors(nums[i]);
    }
    
    return sum;
}

方法3：
![3.PNG](https://pic.leetcode-cn.com/2be97c785d59d7342e0182e1a47a101e547eac2bb8d78895217e35a205bb3e37-3.PNG)
int four_divisors(int num)
{
    int i;
    int cnt = 0;
    int sum = 0;
    
    if (num == 1 || num == 2) {
        return 0;
    }

    for (i = 2; i < sqrt(num); i++) {
        if (num % i == 0) {
            cnt = cnt + 2;
            if (cnt > 2) {
                return 0;
            }
            sum = sum + i + num / i;
        }
    }
    
    i = sqrt(num);
    if (i * i == num) {
        cnt++;
        if (cnt > 2) {
            return 0;
        }
        sum = sum + i;
    }
    
    if (cnt == 2) {
        sum = sum + 1 + num;
        return sum;
    } else {
        return 0;
    }
}

int sumFourDivisors(int *nums, int numsSize)
{
    int i;
    int sum = 0;

    for (i = 0; i < numsSize; i++) {
        sum += four_divisors(nums[i]);
    }
    
    return sum;
}



