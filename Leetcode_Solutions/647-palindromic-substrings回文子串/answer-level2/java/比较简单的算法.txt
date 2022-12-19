### 解题思路
此处撰写解题思路
回文字符串的长度可能为单数，也可能为双数，所以要分两种情况去解决。
我们可以首先找到这个回文字符串的中心字符，如果字符串的长度为奇数，那么中心字符一定存在，如果为偶数，那么中心字符存在两个，分别在i和i+1，两个指针分别对应字符串的首位依次++和--，如果情况满足，那么结果+1，否则，退出循环。看代码一眼就懂了哦。
### 代码

```java
class Solution {
    private int cnt=0;
    public int countSubstrings(String s) {
        for(int i=0;i<s.length();i++){
            solve(s,i,i);
            solve(s,i,i+1);
        }
        return cnt;
    }
    private void solve(String s,int start,int end){
        while(start>=0&&end<s.length()&&s.charAt(start)==s.charAt(end)){
            start--;
            end++;
            cnt++;
        }
    }
}
```