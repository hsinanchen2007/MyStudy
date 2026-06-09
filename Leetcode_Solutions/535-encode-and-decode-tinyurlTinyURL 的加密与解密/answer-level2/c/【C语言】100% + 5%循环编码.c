### 解题思路
1.思路：
本题是个开放问题，哪怕一点都不操作都行。我的题解，想练练循环编码，因此写了个简单的循环编码，顺便复习/练习一下循环编码。
具体思路：将字符串中字符的ASICII码后移7位后对应的字母作为该字符的密文。
（1）可见字符的ASCII取值范围为[32, 126]。
（2）对于超过可见字符的范围的，则循环取前部分。循环的方法就是减去取值范围的宽度（126 - 32 + 1 = 95）。这样一来，后移7位后大于126的数，减去95即可折回到取值范围的开头部分开始。
2.corner condition：
（1）.对ASICII为119和120的边界字符，要手动验算一下加密算法是否符合预期，编码后是否能够跟开头的字符形成循环。----在算法设计之前就要先花5mins思考清楚。

3.知识点总结：
（1）.ASCII：可见字符ASCII码范围是[32, 126]。
（2）.数据范围的大小是：最大值 - 最小值 + 1，注意别忘了+1！！！！
(3).循环编码通过减数据范围大小即可实现，不需要取余。
4.耗时：1h35mins，花的时间太长了，哎~~。主要耗时点：
（1）开始时，使用取余来实现循环编码，发现取余会带来数据0，有数据0，那么字符串操作就操作不了，浪费了半个多小时时间。-----算法设计没有考虑周到；
（2）对可见字符的ASICII值范围不清楚------知识点没掌握；
（3）对简单循环编码算法不熟悉，不知道通过减取值范围即可实现循环。------知识点没有掌握；
......
![image.png](https://pic.leetcode-cn.com/3512612d3537499720c9f626f31d497a813f94f1c2196b468032e714d2919998-image.png)


### 代码

```c
/** Encodes a URL to a shortened URL. */
char* encode(char* longUrl) {
    int i = 0;
    int len = 0;
    char * ret = 0;
    len = strlen(longUrl);
    int temp = 0;
    //printf("encode len = %d\n",len);
    ret = (char *)malloc((len + 1) * sizeof(char));
    memset(ret, 0x00, (len + 1) * sizeof(char));
    for(i = 0; i < len; i++) {
        temp = (int)longUrl[i] + 7;
        if(temp > 126) {
            ret[i] = (char)((int)longUrl[i] + 7 - 95);
        }
        else {
            ret[i] = (char)((int)longUrl[i] + 7);
        }
    }
    //printf("ori string :%s\n",longUrl);
    //printf("encode string: %s\n",ret);
    return ret;  
    
}

/** Decodes a shortened URL to its original URL. */
char* decode(char* shortUrl) {
    int i = 0;
    int len = 0;
    char * ret = 0;
    len = strlen(shortUrl);
    ret = (char *)malloc((len + 1) * sizeof(char));
    memset(ret, 0x00, (len + 1) * sizeof(char));
    for(i = 0; i < len; i++) {
        if(shortUrl[i] < 39) {
            ret[i] = (char)((int)shortUrl[i] + 95 - 7);
        }
        else {
            ret[i] = (char)((int)shortUrl[i] - 7);
        }
    }
    //printf("decode: len = %d\n",len);
    //printf("decode string: %s\n",ret);
    return ret;     
}

// Your functions will be called as such:
// char* s = encode(s);
// decode(s);
```