![Untitled-1.jpg](https://pic.leetcode-cn.com/39f31d2d0317a36f5effbb4e239af65879387be284fe606040e082633c67ce2b-Untitled-1.jpg)
![Untitled-2.jpg](https://pic.leetcode-cn.com/9336a3d5b6d77c506f298911aa8294fa3618991c38836347485301a27394f4bf-Untitled-2.jpg)
![Untitled-3.jpg](https://pic.leetcode-cn.com/aa0421a5a25d72acc0decdf2e2a2c26883153b7d4916b4f61708f350ac23dc26-Untitled-3.jpg)
![Untitled-4.jpg](https://pic.leetcode-cn.com/9725ea21a5110e8233c9ee458ae535415fc5f9a0bed83ddd9f92b8225cf9249e-Untitled-4.jpg)
![Untitled-5.jpg](https://pic.leetcode-cn.com/a75fdd3c962465a151bc5f743c118eb04adcfda6592cdca71f2d18c5d966c158-Untitled-5.jpg)
![Untitled-6.jpg](https://pic.leetcode-cn.com/e010dc8ce18fe87bd59ca89dff65f7f3adf206f52a542bd46d6928a0325d2577-Untitled-6.jpg)
![Untitled-7.jpg](https://pic.leetcode-cn.com/0e874b4ec9a20cc3bbcfb4a6657cff4604e75b621936d541cec5caa594199d04-Untitled-7.jpg)
![Untitled-8.jpg](https://pic.leetcode-cn.com/9ec79e08865219778a3a9140b944abef6b85fc5db6df44bc76f521b98b324291-Untitled-8.jpg)
![Untitled-9.jpg](https://pic.leetcode-cn.com/e5c361a61f7227aea319047a72fd1e8703a68d57a4d2eec7d66e9b4ae748e785-Untitled-9.jpg)
![Untitled-10.jpg](https://pic.leetcode-cn.com/a595bc1a7db01d04a2199691fc1d18d76db6a693fbf56c8d8b9f6ef13d4396a8-Untitled-10.jpg)
```
class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        s_size = len(s)
        p_size = len(p)

        '''我们给该动态规划一个哨兵节点！，dp[0][0] = True. 
        哨兵状态适合：当给一个初始条件，从第一个点就可以开始按着dp的状态转移方程进行下去的问题。
        该问题，如果给出没有字符串的时候为真，那么第一个字符就可以进行进行下去了。因为-2的问题，并不在当i=0 or 1 的时候发生。
        
        '''

        dp = [[False for _ in range(p_size+1)] for _ in range(s_size+1)]
        dp[0][0] = True

        '''
        由于哨兵节点导致index错位， 在s和p中index分别表示为：i-1 和 j-1
        对于填表内外循环的问题： 只要在循环中没有出现加法计算，例如： i+1  或者是 j+1 内外循环无所谓谁在内，谁在外。 
        
        
        这也给我们写dp问题提个醒，只要不涉及到index的加法，就可以随便写，不用考虑填表是需要横着填还是竖着填，随便遍历就行。内外循环可以互换
        
        '''

        #特殊情况处理！！原因下文有详细讲解，往下看
        for j in range(2, p_size + 1):
            dp[0][j] = dp[0][j-2] and p[j-1] == "*"



        for i in range(1, s_size+1):
            for j in range(1, p_size+1):
                if p[j-1] != "*":
                    dp[i][j] = (s[i-1] == p[j-1] or p[j-1] == '.') and dp[i-1][j-1]

                else:
                    dp[i][j] = dp[i][j-1] or dp[i][j-2] or\
                               ((s[i-1] == p[j-2] or p[j-2] == ".") and dp[i-1][j])

                    '''
                    注意： 这里dp[i][j-2] 因为j从1开始，因此会导致j-2可能是负数，可是python里面，index本来就可以是负数，
                    而这里如果取负数，那么结果一定是一定是false，而这正是我们想要的结果。
                    因为在or运算里， false等于该条件不存在，我们在超出范围的时候，本来也不需要该条件！
                    
                    解释一下为何无论如何一定是false：
                    因为超出边界只有一种可能，就是p首字母就是*，而这时，要填的dp中的位置一定是i=1，j=1点，而此时，由于是首次循环
                    除了0，0点之外，其他任何点都一定是false。而or运算中，dp[i][j-2]是dp[1][-1]点，一定不是0，0 点！
                    
                    特殊情况处理：
                    当然也正式因为这个特征，让一个特殊情况产生了bug，即第二位如果是*的时候，例如 bc 和 a*bc
                    若*=0时候，结果本应该是true，因为第一位的 a 被第二位的 * 消去了，此时p[0:1]应该是个空字符，而空字符就应该是true
                    但是由于判定条件中本该起作用的： dp[i][j-2] = dp[i][0], 由于dp[i][0]并没有被更新过，
                    （因为所有i=0 or j=0 的dp值都没有被更新过，除了0，0 点），因此dp[i][0]一定是false。这导致dp[i][j] 不可能是true
                    因此我们需要处理一下这个问题。
                    '''

        return dp[-1][-1]

foo = Solution()
print(foo.isMatch("", "a*b*"))
```
