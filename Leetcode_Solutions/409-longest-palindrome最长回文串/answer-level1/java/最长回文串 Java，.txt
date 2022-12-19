### 解题思路
遍历字符串，统计各字母个数。若为偶数直接加，若为奇数，加奇数减一。同时判断是否存在奇数个，存在则答案再加一，保证回文串中间有一位，否则不加。

### 代码

```java
class Solution {
    public int longestPalindrome(String s) {
        int[] num = new int[60];//创建数组存储大小写字母，由于大小写字母间相减差额为32，即有其他字符，故至少为26+32的数组大小
        int res = 0;//最终结果
        int res2 = 0;//记录一下是否有奇数，无为0，有加1，因为必有一个在中间
        for(int i = 0;i<s.length();i++){
            num[s.charAt(i) - 'A']++;
        }
        for(int j = 0;j<num.length;j++){//依次判断各字母数量
            if(num[j]%2==0 && num[j]>0){//若为偶数直接加
                res += num[j];
            }else if(num[j]>0){//若为奇数，奇数减一变偶数
                res += num[j]-1;
                res2 = 1;//有奇数则回文中间可以多一个
            }
        }
        return res + res2;
    }
}
```