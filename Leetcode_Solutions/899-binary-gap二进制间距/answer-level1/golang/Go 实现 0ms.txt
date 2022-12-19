基本思路就是计算两个相邻1（是指两个1中间没有1）之间的距离，然后返回最长的那一个
```
func binaryGap(N int) int {
    max, counter, flag := 0, 0, 0
    for N!= 0{
        if N & 1 == 1{
            flag++
        }
        if flag == 1{
            counter++
        }
        if flag == 2{
            if counter > max{
                max = counter
            }
            counter = 1
            flag = 1
        }   
        N >>= 1
    }
    return max
}
```

![image.png](https://pic.leetcode-cn.com/2861a5bab38fc4a83430791f0680d7e552b58c90bfb3f8800825523b26d482cb-image.png)