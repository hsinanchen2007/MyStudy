### 解题思路
emmm，这是一个数学问题，然而我数学并不好，把约瑟夫环的这个数学解法看了好久才看明白，关于约瑟夫环可以看[这篇文章](https://www.cnblogs.com/jjscm/p/4463555.html),可以说是讲的很详细了。

### 代码

```golang
func lastRemaining(n int, m int) int {
    var ans int 
    for i := 2; i <= n; i++ { //从二选一开始倒推，因为模1没有意义。。。
        ans = (ans+m)%i;//最后的幸存者
    } 
    return ans;
}
```