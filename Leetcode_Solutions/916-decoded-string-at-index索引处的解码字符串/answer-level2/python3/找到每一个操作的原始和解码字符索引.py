思路  
如果S='vk3u5xhq2v', 这种时候需要找到每一个操作的原始和解码字符索引, 记为(x, y), x表示decode(S)中的位置(从1开始计算), y表示S中的位置(从0开始计算)  
最终的字符为'vkuxhqv'  
索引记录表对应的就是[v(1,0), k(2,1), 3(6,1), u(7,2), 5(35,2), x(36,3), h(37,4), q(38,5), 2(76,5), v(77,6)]  
可以根据K值提前结束索引记录过程, 比如假设K=50, 上面的S在2(76,5)的时候由于76>=50, 跳出循环  
然后开始逆向找K对应的应该是原始S中的哪个字符, 类似于进制转换, 把K与每个decode(S)取余, 结果为0的时候说明答案就是对应操作中的原始位置.  

```
class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        i = cnt = 0
        c = ''
        x = []
        while i < len(S) and cnt < K:
            if S[i].isdigit():
                cnt *= int(S[i])
                if S[i-1].isdigit(): x[-1][0] = cnt
                else: x.append([cnt, len(c) - 1])
            else:
                c += S[i]
                cnt += 1
                x.append([cnt, len(c) - 1])
            i += 1
        ret = ''
        while x:
            t = x.pop()
            K %= t[0]
            if K == 0:
                ret = c[t[1]]
                break
        return ret
```
