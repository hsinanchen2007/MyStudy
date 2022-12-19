```
class Solution {
    func isPalindrome(_ x: Int) -> Bool {
        // 排除负数以及可以整除10的数但是x==0应该return true
        if x < 0 || x % 10 == 0 && x != 0 {
            return false
        }
        var X = x
        var reverse = 0
        // 只反转X的一半，如何判断是一半？
        // 当已反转reverse > 变化后的X，则此时已反转X的一半或多一位
        // 譬如X=12321，当reverse==123，X==12，此时已反转X的一半多一位
        // 譬如x=1221，当reverse==12，X==12，此时已反转X的一半
        while X > reverse {
            reverse = reverse * 10 + X % 10
            X /= 10
        }
        return X == reverse || X == reverse / 10
    }
}
```
该方法参照了官解的第三种方法，既不使用字符串，也避免了直接反转数字可能导致的溢出问题（本来不会溢出的回文数反转后也不会溢出，但是如果输入一个并不是回文数的数呢？），而且也大大减小了时间复杂度（虽然每次测试的时间都有长有短）。
![屏幕快照 2019-07-30 下午4.11.25.png](https://pic.leetcode-cn.com/1e082e9c5432306605a8d362609ab2f13ce4fb3457299c5fc9a940442c476701-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-07-30%20%E4%B8%8B%E5%8D%884.11.25.png)
