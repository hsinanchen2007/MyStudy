

## 方法一：移位
### 解题思路
1）首先把n和1做&运算，判断n的低次位是不是1；
2）把1左移一位得到2，再和n做&运算，就能判断n的次低位是不是1；
3）这样反复左移，每次都能判断i的其中一位是不是1；
4）**终止循环的条件是flag==0**。

<![幻灯片15.PNG](https://pic.leetcode-cn.com/2fee2c8fc93280b36ac4eb230e84960511fdac8889695f666b0fe25e03f52a65-%E5%B9%BB%E7%81%AF%E7%89%8715.PNG),![幻灯片16.PNG](https://pic.leetcode-cn.com/0490d74bf14d4f2d18ea97c92d4fa31d11155094d81c7ccb8dbeb96612403d8c-%E5%B9%BB%E7%81%AF%E7%89%8716.PNG),![幻灯片17.PNG](https://pic.leetcode-cn.com/631329df8e6b1e5cf5599f93a458a481f7dc85bb1500e0e24c1633c735e52d73-%E5%B9%BB%E7%81%AF%E7%89%8717.PNG),![幻灯片18.PNG](https://pic.leetcode-cn.com/e3fd40ede4f302787db9f49a4d43b475e682512b0d2458778e41a1e8ddf45559-%E5%B9%BB%E7%81%AF%E7%89%8718.PNG)>
## 方法二：做差
1. 把一个数减去1，再和原整数做与运算，会把整数最右边一个1变为0；
2. 重复运算，每个整数二进制表示中有多少个1就进行多少次这种运算；
3. 当整数变为0时停止循环；
![刷题思路2.png](https://pic.leetcode-cn.com/3fa9a446e5b9eeb8a17dfbcfe51bb7c7df680c18261c2af60d616394e9e23937-%E5%88%B7%E9%A2%98%E6%80%9D%E8%B7%AF2.png)







### 代码


```java []
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count=0;
		int flag=1;
		while(flag!=0) {
			if((n&flag)!=0) {
				count++;
			}
			flag=flag << 1;
		}
		return count;
    }
}
```
```java []
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count=0;
		while(n!=0) {
			count++;
			n=(n-1)&n;
		}
		return count;
    }
}
```

