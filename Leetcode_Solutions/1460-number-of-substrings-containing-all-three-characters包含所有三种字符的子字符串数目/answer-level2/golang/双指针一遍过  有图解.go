### 解题思路

维护两个指针`i`,`j`，一个代表子串开始位置，一个代表子串结束位置（左闭右开）。

`i` 和 `j`之间最小距离不能低于3

1. 如果`s[i:j]`中包含了a 和 b 和 c。则代表`s[i:j]`, `s[i:j+1]`, `....`, `s[i:]`都是可行子串。 总数为`len(s)-j+1`个。

    也就是以`i`位置为开始，有`len(s)-j+1`个子串可行。

2. 如果不包含，代表还没找到以i开始的有效子串， `j++` 继续找。直到`j`到头。

3. 如果`j`到头，代表一个更长的序列也找不到同时包含`abc`。则更短的序列也不可能，`i`不必递加，直接输出结果。

4. 回到`1`， 可行后，`i++`。保持`i` `j`距离前提。

5. 因为`i++` 可能会让必要的`abc`中之一被提出。所以要重新判断`s[i:j]`是否包含`abc`。从此处重复1的操作。

这种解法乍一看是O(n)，最坏情况是O(2n)。 但其实在我的代码中判断子串是否包含abc要用更多的时间，最坏接近O(n^2)? 
可以用带有记忆的方法比如用数组存当前abc数量来改进。

最终时间复杂度O(n)

### 图解

<![1.png](https://pic.leetcode-cn.com/c7f62d3672c1b54151981c80f17171e76a8bf356a8ed8d37385966f10287d62d-1.png), ![2.png](https://pic.leetcode-cn.com/d1f38fbb566880344f15793c59075926f44bfa8681d238065bd46b2aba1caf3d-2.png),![3.png](https://pic.leetcode-cn.com/06304b8319663b69b465c3017a25dcfe477ccd63d611055ab5591a7e5a9cc86b-3.png),![4.png](https://pic.leetcode-cn.com/3134459f5cc053f6ec099d2673d0b9eacd50f1ef77d630a3487b97b7ba39e654-4.png),![5.png](https://pic.leetcode-cn.com/b4ce02d9bc291d50bad25c50aa9b6050d6b45c94fb8aeea4c7e120cde9f6ee8b-5.png),![6.png](https://pic.leetcode-cn.com/9a299cdf49204f970773a019fe7a46ca33d23f181e015e646f8d441927a38fb3-6.png),![7.png](https://pic.leetcode-cn.com/9aeef83d178c509a7806f9f8c79c882f906b668b095024c9db950ed1e0154384-7.png),![8.png](https://pic.leetcode-cn.com/87406fdff78b8adc03ee05f70106e89e10afb794edcf1ec5c2a3b95a1625034c-8.png),![9.png](https://pic.leetcode-cn.com/b675992c1bdd8bf0146cba2492c0b24c8c7cb1a85403ceb21c67d8fbfcdd9b64-9.png),![10.png](https://pic.leetcode-cn.com/57634a72a0611721b9637d866b7eeaf5fc76f3303f8dee61b7a0ba22cb452ecc-10.png),![11.png](https://pic.leetcode-cn.com/e40e526c0a3416d42bb197bc9630415bd2ada281b56936352511c21d73ea76b8-11.png),![12.png](https://pic.leetcode-cn.com/6646a0de193f02347f79f109eef46b6b6bc1c576cb7b94c52afb1a82fc9663a6-12.png),![13.png](https://pic.leetcode-cn.com/38dc38023c892db854800d6b7fa1023a587e01d3df170dc7ea1472ac0d664c7b-13.png),![14.png](https://pic.leetcode-cn.com/9d85d4d7769d4eaa6550f81286af96f6e313a3378d0f0b1456a7536dad652be6-14.png),![15.png](https://pic.leetcode-cn.com/261f3dd8f1d9865e6c3dcbeb8d0cdd3cb2394ee179cac2c5e6a9a1fa2630e3ec-15.png),![16.png](https://pic.leetcode-cn.com/03aa5249c1a523a8958631f3adf7de4a718e8642b49ac4f4703536d3e4fecdd1-16.png),![17.png](https://pic.leetcode-cn.com/eb4971bdb11d2cc1a92348cb20e366fe95aab91225d8737df928d302cc0aa1b6-17.png)>















### 改进后真·O(n)代码

```Golang []
func numberOfSubstrings(s string) int {
    if len(s) <= 2{
        return 0
    }
    i, j := 0, 3                    // 初始化指针

    now := []int{0,0,0}             // 三长度的数组用于存放当前子串a b c各自数量

    for z:=0; z<3; z++{             // 初始化数量数组
        now[s[z]-'a'] ++
    }

    out := 0
    for i<len(s)-2 {                // 边界条件可以是这个也可以是j <= len(s) 
        if !zeroInArray(now){       // abc都不为0个
            out += (len(s)-j+1)     // 加结果
            now[s[i]-'a'] --        // 取出第i个字符
            i++                     
        } else {                        
            j++
            if j > len(s){break}    // 越界弹出
            now[s[j-1]-'a'] ++      // 增加第j个字符
        }
    }
    return out
}

func zeroInArray(nums []int) bool { // 判断数量数组中是否有0
    for _, c := range nums{
        if c == 0{
            return true
        }
    }
    return false
}
```
```python []
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        if len(s) <= 2:
            return 0

        i = 0
        j = i+3
        now = [0,0,0]
        for z in range(0, 3):
            now[ord(s[z])-97] +=1
        
        out = 0
        while i < len(s)-2:
            if 0 not in now:
                out += (len(s)-j + 1)
                now[ord(s[i])-97] -= 1
                i+=1
            else:
                j+=1
                if j > len(s):
                    break
                now[ord(s[j-1])-97] += 1
        return out
```


### 比赛慌不择路代码


```python3
class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        i = 0
        j = i+3
        
        if len(s) <= 2:
            return 0
        out = 0
        while i < len(s)-2:
            if 'a' in s[i:j] and 'b' in s[i:j] and 'c' in s[i:j]:
                out += (len(s)-j + 1)
                i+=1
                if j < i+3:
                    j = i+3
            else:
                j+=1
                if j > len(s):
                    break
        return out
```


