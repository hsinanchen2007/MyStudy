### 解题思路
其实暴力解法也是可以的，但是超时了，然后就学习理解了官方解答的方法一，结合自己的理解，思路如下图：
最重要的是将结果的范围直接精确到几个取值，思想就是官方解答所说：
![QQ截图20200201171606.png](https://pic.leetcode-cn.com/97e263680866a43d96454665c6429b0b10d8bf4f53520eb275bf6d9247083f5b-QQ%E6%88%AA%E5%9B%BE20200201171606.png)

结合个人思考，思路如下：

![IMG_0450.PNG](https://pic.leetcode-cn.com/0badb4b3e238d751beddd1af77d043e92e575fd61d63601eb6411af9c35a11f9-IMG_0450.PNG)


### 代码

```java
class Solution {
    public int repeatedStringMatch(String A, String B) {
		int times = B.length()/A.length();
		if(times==0) {
			if(A.contains(B)) return 1;
            if((A+A).contains(B)) return 2;
			else return -1;
		}
		String temp = A;
		for(int i=1;i<times;i++) {
			A += temp;
		}
		if(A.contains(B)) return times;
        if((A+temp).contains(B)) return times+1;
        if((A+temp+temp).contains(B)) return times+2;
		return -1;
    }
}
```