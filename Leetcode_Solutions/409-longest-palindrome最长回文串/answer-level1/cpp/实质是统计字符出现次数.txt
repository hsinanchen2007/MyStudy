### 解题思路
1.首先要明白回文串的结构:xxxxxxQxxxxxx
2.统计每个字符出现的次数，如果出现了偶数次，那就可以对称放到两边构成回文串。
3.如果出现了奇数次，那就是减去一次成了偶数次。

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> arr(128,0);            //字符哈希
        int maxLength = 0;                 //回文串偶数部分的最大长度
        int flag=0;                        //是否有中心点

        for(int i=0;i<s.length();i++)
        {     //统计字符个数
            arr[s[i]]++;         
        }
        for(int i=0;i<128;i++)
        {   
            //如果字符为偶数个
            if(arr[i] % 2==0)
            {               
                //则均可以使用在回文串里
                maxLength+=arr[i];
            }
            else
            {
                maxLength += arr[i]-1;     //如果为奇数，则丢弃一个，其余使用在回文串中
                flag=1;                    //标记回文串有中心点
            }
        }
        return maxLength + flag;             //最终结果 = 最大长度 + 中心点
    }
};
```