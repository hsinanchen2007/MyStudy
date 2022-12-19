## 一、暴力美学
数字转字符串，管它什么正负数，反转比较即可。
```python3 []
class Solution:
    def isPalindrome(self, x: int) -> bool:
        x = str(x)
        return x == x[::-1]
```
## 二、常规解法
需要注意就是10，-5，这类本身反转都不成回文数直接pass，但是对x%10小心x=0的情况即可。
```python3 []
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x == 0:
            return True
        elif x < 0 or x % 10 == 0:
            return False
        xx = x
        res = x % 10
        x //= 10
        while x != 0:
            if x >= 214748364: return False
            res = res * 10 + x % 10
            x //= 10
        return xx == res
```
## 如官方所述：翻转一半
如下所示，官方解释很全，结合例子完全可以理解，翻转到一半的巧妙之处，就是来利用回文数特征。
101:
反转一次:x=10,y=1
反转二次:x=1,y=10
(不等，但是实际上相等，因此y//10)

1001:
反转一次:x=100,y=1
反转二次:x=10,y=10
(刚好相等)

1301:
反转一次:x=130,y=1
反转二次:x=13,y=11
反转三次:x=1,y=113

因此反转结束的条件就是原先x值没有反转过后的y大，但是结果是包含奇数长度与偶数长度的。对于奇数长度的回文数，如101，需要让y再整除10后再比较.

同时在这种情况下，不需要考虑溢出问题。
x=2147483647
反转一次:x=214748364,y=7
反转二次:x=21474836,y=74
反转三次:x=2147483,y=746
反转四次:x=214748,y=7463
反转五次:x=21474,y=74638
此时一定y>x然后不等，直接是假。

```c []
bool isPalindrome(int x){
	if(x == 0) return true;
	else if(x<0||x%10==0) return false;
	int reverseNum = 0;
	while(x>reverseNum){
		reverseNum = reverseNum*10 + x % 10;
		x /= 10; 
	}
	return x==reverseNum||x==reverseNum/10;
}
```

## 四、基于官方的思想的解法
回文数，就是左侧两侧相等，正反读都相等，官方给出翻转到一半的思想，回文数的特征啊。
而给出的整数最大值也就长度为10位，2**31-1,因此顶多这个数长度为10位，那么就从中间开始找。(就是从中间开始瞎找)

1.设置初始值，power = 10**5，然后用x//power，如果商在(0,9)之间内，那么刚好证明此时是最高位，然后开始比较即可。否者<0或>9，对应应该让power//10与power*10。(一坨if else判断)
2.什么时候得出结果？因为从中间5开始找的，counter=5，当counter=0后就是回文数。
当商在(0,9)之间内，如果最高位与最低位不相等，返回假。

xx = x 拷贝x值到xx(取低位用的)

110012:
当$10^5$时，高位正好出现，开始两头对比(1!=2)返回假

101:
$10^5$:高位:101/$10^5$=0(未出现最高位)
$10^4$:高位:101/$10^4$=0(未出现最高位)
$10^3$:高位:101/$10^3$=0(未出现最高位)
$10^2$:高位:101/$10^2$=1(出现最高位),最低位:101%10=1,相等;x=101/100=1,xx=xx%10=10
$10^1$:高位:1/10=0,最低位:10%10=0,相等;x=1/10=0,xx=xx%10=0
$10^0$:高位:0/1=0,最低位:0%10=0,相等
此时表明一半的都比较完了，都是相等，那就是回文数了。

```python3 []
class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x == 0:
            return True
        elif x < 0 or x % 10 == 0:
            return False
        isfind = 0
        counter = 5
        xx = x
        power = 10000  # 初始化为10**5
        while counter:
            # power = pow(10, counter-1)
            high = x // power
            if isfind:
                if high == xx % 10:
                    x %= power
                    xx //= 10
                    counter -= 1
                    power //= 10  # 缩小
                else:
                    return False
            elif 0 < high < 10:  # 最高位找到
                isfind = 1
            elif high > 9:
                power *= 10  # 增大
                counter += 1
            else:
                power //= 10  # 缩小
                counter -= 1
        return True
```
```c []
bool isPalindrome(int x){
	if(!x) return true;
	else if(x<0||x%10==0) return false;
	int isfind=0,counter=5,xx=x,high;
	int power = 10000;  // 设置高低都行
	while(counter){
		high = x / power;
		if(isfind){
			if(high==xx%10){
				x %= power;
				xx /= 10;
				counter--;
				power /= 10;
			}else return false;
		}else if(high>0&&high<10) isfind = 1;
		else if(high>9) {power*=10;counter++;}
		else {power/=10;counter--;}
	}
	return true;
}
```
就是暴力找最高位，本题最高位就第十位，从中间找快一点，这样不用判断溢出，虽然效率。。天多if else，想想即可。



