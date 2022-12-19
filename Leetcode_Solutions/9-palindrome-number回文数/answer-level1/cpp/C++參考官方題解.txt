### 解题思路
反轉一半的數字，注意點為：
1. 如果反轉全部數字，可能出現溢出（如果有溢出説明絕對不是對稱的，應當返回false），只檢查一半更有效率
2. 反轉一半數字時，應當滿足剩下數字比已經反轉部分大（代碼部分用revertedNumber保存反轉部分）
3. 跳出循環時，有兩種情況，一是反轉部分和剩餘部分一樣大，此時原數位數為奇數。二是反轉部分比剩餘部分多一位，説明原數據是偶數

### 代码

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0||(x%10==0&&x!=0)) return false;
        int revertedNumber=0;
        while(revertedNumber<x)
        {
            revertedNumber=revertedNumber*10+x%10;
            x/=10;
        }
            return revertedNumber==x||revertedNumber/10==x;
    }
};
/**public class Solution {
    public bool IsPalindrome(int x) {
        // 特殊情况：
        // 如上所述，当 x < 0 时，x 不是回文数。
        // 同样地，如果数字的最后一位是 0，为了使该数字为回文，
        // 则其第一位数字也应该是 0
        // 只有 0 满足这一属性
        if(x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int revertedNumber = 0;
        while(x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }

        // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
        // 例如，当输入为 12321 时，在 while 循环的末尾我们可以得到 x = 12，revertedNumber = 123，
        // 由于处于中位的数字不影响回文（它总是与自己相等），所以我们可以简单地将其去除。
        return x == revertedNumber || x == revertedNumber/10;
    }
}
。*/
```