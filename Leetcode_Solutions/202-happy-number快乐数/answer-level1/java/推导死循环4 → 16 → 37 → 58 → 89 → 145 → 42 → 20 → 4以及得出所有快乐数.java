### 看到很多人提到的4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4死循环理论和数字 1 和 7 ，我就很想不通这个规律是怎么得到的，于是我用python试了试怎么得出来的。
#### 思路：
这个循环显然是之前有人试出来的，所以我就从2开始观察，对每个数按照平方和的结果与起点对比，因为大部分是死循环，所以我设置了最大循环次数是1000，如果循环了1000次回不到起点，我们就认为不会回到起点了，大家有兴趣的可以把这个上限调高点再去观察。
#### 下面是代码，注释很清楚了：
```python []
# 新建一个计算各位数平方之和的函数
def numSum(num):
	nSum = 0
	while num:
		nSum += (num % 10) **2
		num = num // 10
	return nSum
```
#### 观察每个数每个数能否回到起点，有了这一步才能得出下一步的结果
```python []
if __name__ == '__main__':
    #****************************** 训练模型得出死循环 ******************************#
    # 1就没必要观察了，直接从2开始
    num = 2
    # 这个列表用来存不快乐数
    loopNumList = []
    # 要观察的最大数字是多少
    maxNum = 1000
    # 下面开始训练
    while num < maxNum:
        # 这里用tmp替换n运算，因为后面对比要用到原始数字n，所以不要对n修改
        tmp = num
        # 循环计数，以及最大循环次数，1000次没有回到起点，应该就差不多认为不会回到起点了，你也可以自行调整
        # 一定要用最大循环次数，要不然会死循环
        counts = 1
        maxLoops = 1000
        while counts < maxLoops:
            tmp = numSum(tmp)
            if numSum(tmp) == num:
                print("%s 循环了 %s 次回到起点" % (num, counts))
                loopNumList.append(num)
                # 一旦检测到回到起点了，就要跳出循环，检测下一个数
                break
            counts += 1
        # else:
        # 	print("%s 循环了 %s 没有回到起点" % (num, counts))
        num += 1
    print()
    print("%s 以内的死循环： " % maxNum)
    print(loopNumList)
```
```
output:
4 循环了 7 次回到起点
16 循环了 7 次回到起点
20 循环了 7 次回到起点
37 循环了 7 次回到起点
42 循环了 7 次回到起点
58 循环了 7 次回到起点
89 循环了 7 次回到起点
145 循环了 7 次回到起点

1000 以内的死循环： 
[4, 16, 20, 37, 42, 58, 89, 145]
```

#### 我现在才有点思路那些人是怎么得到这个神奇的死循环，直接给出4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4的循环结果：
```python []
if __name__ == '__main__':

    # 这里是为展示4的循环路径，因为我已经通过下面的过程知道了4会进入死循环
    unHappyNum = 4
    while 1:
        unHappyNum = numSum(unHappyNum)
        print(unHappyNum, end = "——>")
        if numSum(unHappyNum) == 4:
            break
```
```
output
16——>37——>58——>89——>145——>42——>20——>
```
#### 有了上面的思路，我们很轻易就能得出指定区间内所有的快乐数：
```python []
if __name__ == '__main__':
    #****************************** 训练模型得出快乐数 ******************************#
    #有了上面的思路，只需要把 if numSum(tmp) == num 中的 num 改为 1 就可以得到区间内所有的快乐数
    num = 1
    # 这个列表用来存快乐数
    happyNumList = []
    # 要观察的最大数字是多少
    maxNum = 300
    while num < maxNum:
        tmp = num
        counts = 1
        maxLoops = 1000
        while counts < maxLoops:
            tmp = numSum(tmp)
            if numSum(tmp) == 1:
                # print("%s 循环了 %s 次回到起点" % (num, counts))
                happyNumList.append(num)
                break
            counts += 1
        num += 1
    print("%s 以内的快乐数： " % maxNum)
    print(happyNumList)
```
```
output
300 以内的快乐数： 
[1, 7, 10, 13, 19, 23, 28, 31, 32, 44, 49, 68, 70, 79, 82, 86, 91, 94, 97, 100, 103, 109, 129, 130, 133, 139, 167, 176, 188, 190, 192, 193, 203, 208, 219, 226, 230, 236, 239, 262, 263, 280, 291, 293]
```
#### 最后附上我的解法，是用的死循环理论，耗时有点久：
```java []
class Solution {
    public boolean isHappy(int n) {
        List<Integer> unHappy = Arrays.asList(4,16,37,58,89,145,42,20);
        if (n <= 0) {
            return false;
        }
        while(n != 1) {
            n = numSum(n);
            if (unHappy.contains(n)) {
                return false;
            }
        }
        return true;
    }
    
    private int numSum(int x) {
        int ret = 0;
        while (x > 0) {
            ret += (x%10) * (x%10);
            x /= 10;
        }
        return ret;
    }
}
```