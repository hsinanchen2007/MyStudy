## 解题思路:动态规划
首先解题要先理解正则表达式具体匹配规则,先来做个最简单的假设:<br>
- 假设`s=ab`,`p=a*b*`,那么毫无疑问`s.match(p)`是成立的
- 根据上面的例子,`p`变成`a*b*c`,那么这就是不成立的，因为`s`并没有`c`，如果`p`再加一个`*`变成`a*b*c*`，那么匹配又会变成立，因为`c`这个时候可以匹配为0个

- 那么当匹配到`*`号的时候具体到代码上逻辑是这样的:
```js
if(p.charAt(i) === '*'){
  dp[i+1] = dp[i-1]
}
```
以上的逻辑思路就是当匹配到`a*b*c*`中时，判断最后一个`*`是否匹配成立只需要看第2个`*`,即`a*b*`是否匹配，如果匹配那么`a*b*c*`也是成立的,假如`s`换成是`ad`，那么走到`a*b`的时候就已经不匹配了,经过状态转移`a*b*c*`也不会匹配，所以使用**动态规划**就再合适不过

### 第一步：建立二维数组
假设`s=abbcddd`,`p=a*b*.dd*`,因此先建立一张对应二维数组的表:<br>
![0010-01.png](https://pic.leetcode-cn.com/636ca778a0f274465fb6a5850e6399456e7a38a29edcd6e89e19037900d59a75-0010-01.png)

为何要在`p`前面加一个空字符串(只是在表格中加)，原因也很简单，假设当`s='',p=a*`时匹配是成立的，那么根据上面的逻辑`dp[0][j+1]=dp[0][j-1]`,那么就需要一个空值为true才能确保转移到`a*`后仍然为true<br>
然后先建立一种简单的匹配情况，字符可以先把`s`假设为空字符串，`p`不变，那么可以s匹配p的结果如下(假设0为false,1为true):<br>
![0010-02.png](https://pic.leetcode-cn.com/f3e9c4c207410b4f5e18badf12f37681fe84831c260a0383401eed2645d44130-0010-02.png)

如上图，当`p[j]='.'`的时候可以当成是任意字符串但不能为空，因此匹配也为false，结合上述逻辑，一开始先匹配第一个空字符的逻辑可以总结为:
```js
    dp[0][0] = true;
    for (let i = 1; i < p.length; i++) {
        if (p.charAt(i) === "*") {
            dp[0][i + 1] = dp[0][i - 1]
        }
    }
```
这个时候匹配完的`dp[0]`意义就是后续`dp[i][j]`进行状态转移的判断依据

### 第二步: 匹配状态转移
在`dp[0]`全部赋值后开始对字符串`s`和模式字符串`p`进行逐一匹配，那么匹配过程一共会碰到三种情况:<br>
- `p[j]`为普通字符时:<br>
  如果`s[i]===p[j]`,那么通过`dp[i+1][j+1]=dp[i][j]`判断，例子如下图：<br>
![0010-03.png](https://pic.leetcode-cn.com/f292a605348e9b5020971468ae3f05a2cb8d888132b4658370047cb04ef6813f-0010-03.png)

- `p[j]`为`.`时:<br>
  可以把`p[j]`看成任意但不为空的字符，也是通过`dp[i+1][j+1]=dp[i][j]`判断，例子如下图：<br>
![0010-04.png](https://pic.leetcode-cn.com/3c2d2cabac3ddc63deaed95b7e0a679927d245450c10945a8181bb1f58c2527b-0010-04.png)

- `p[j]`为`*`时:<br>
  1.如果`p[j-1]!==s[i]&&p[j-1]!=='.'`时，和上面的`dp[0][j+1]=dp[0][j-1]`的逻辑一样，把前一个`*`的状态值转移过来，如下图:<br><br>
![0010-05.png](https://pic.leetcode-cn.com/b79cef283ca21f0dfbe0430c9aec5f45737479e3290635b0341df1d7295fb11c-0010-05.png)


  当`i=0,j=3`时,`s[0]!==p[2]`，因此`dp[i+1][j+1]=false`<br>

  2.当`p[j-1]==s[i]`时，对`*`可以匹配成功的情况可以分为三种，假设`p[j-1]=b`，出现的个数为`n`:<br>
  - `n=0`时，复用上面的逻辑，即`dp[i+1][j+1]=dp[i+1][j-1]`
  - `n=1`时，`dp[i+1][j+1]`只需要等于`dp[i+1][j]`的值即可，如下图：
![0010-06.png](https://pic.leetcode-cn.com/0cd5640c9ecda3fa12252d88c92c74a449596950866dcac91dbb0365d9be5146-0010-06.png)
  - `n>=2`时，这个时候`dp[i+1][j]`和`dp[i+1][j-1]`都有可能为`false`，如下图:
  
![0010-07.png](https://pic.leetcode-cn.com/a539d282ffd5c634c2d1d7f05c60aff59568849d00e55772999bf5de1128242b-0010-07.png)
    那么在出现多个`b`后`dp[i+1][j+1]`可以根据`dp[i][j+1]`判断<br>
  综上所述，当`p.charAt(j) === '*'`时，具体逻辑可以归纳为:<br>
  ```js
    if (p.charAt(j - 1) !== s.charAt(i) && p.charAt(j - 1) !== '.') {
        dp[i + 1][j + 1] = dp[i + 1][j - 1]
    } else {
        dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1])
    }
   ```
匹配完成后返回`dp[s.length][p.length]`就是最终结果。

## 代码实现
```js
let isMatch = function (s, p) {
    let dp = Array(s.length + 1);
    for (let i = 0; i < dp.length; i++) {
        dp[i] = Array(p.length + 1).fill(false)
    }
    dp[0][0] = true;
    for (let i = 1; i < p.length; i++) {
        if (p.charAt(i) === "*") {
            dp[0][i + 1] = dp[0][i - 1]
        }
    }

    for (let i = 0; i < s.length; i++) {
        for (let j = 0; j < p.length; j++) {
            if (p.charAt(j) === '.') {
                dp[i + 1][j + 1] = dp[i][j]
            }

            if (p.charAt(j) === s.charAt(i)) {
                dp[i + 1][j + 1] = dp[i][j]
            }

            if (p.charAt(j) === '*') {
                if (p.charAt(j - 1) !== s.charAt(i) && p.charAt(j - 1) !== '.') {
                    dp[i + 1][j + 1] = dp[i + 1][j - 1]
                } else {
                    dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1])
                }
            }
        }
    }
    return dp[s.length][p.length]
};
```

看到最后的客官欢迎评论指出实现思路的不足，同时推荐阅读我写的[leetcode图解](https://github.com/biaodigit/LeetCode)，大部分题都会使用图文结合讲解解题思路，主要编程语言为js，欢迎提出建议&&点star，你的一枚star是我持续更新的动力👏