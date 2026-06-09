1.获得原来数的二进制表达式，然后在后面补0到32位，就是颠倒后的二进制数
2.对该二进制数求其实际代表的值，但是有一个坑就是：补了多少位，求值的时候就要去掉几位。
![微信图片_20200405112853.jpg](https://pic.leetcode-cn.com/3c1914c4ed3b9eab7bbaad8873f009d6761428afb81311a6379a3bc7e5bc463c-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200405112853.jpg)

```
 uint32_t reverseBits(uint32_t n) {
        string sn = "";
	    while (n >= 1) {
		    int temp = n % 2;
		    sn += temp;
		    n /= 2;
	    }
        int len = 32-sn.size();
        int temp = len;
	    while (len-->0)
	    {//不足32位，后面补0
		    sn += "0";
	    }
	    uint32_t m = 0;
	    for (int i = 0; i < sn.size()-temp; i++) {//这里要记住，只计算原有的位数
		    m += sn[i] * pow(2, sn.size() - 1 - i);
	    }
	    return m;
    }
```
