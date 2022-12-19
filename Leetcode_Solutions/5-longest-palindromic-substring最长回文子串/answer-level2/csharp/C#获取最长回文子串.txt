### 解题思路
获取回文子串的主要思路是回文的特点，对称性。
所以可以已中心点向两边延伸来判断是否是回文，遍历字符串来找到最长的回文
回文分两种，基数回文-中心点不重复，偶数回文-完全对称重复。
### 代码

```csharp
public class Solution {
    public string LongestPalindrome(string s) {
        if(string.IsNullOrEmpty(s))return "";
        int start=0,end=0;//最终返回的起止索引
        for(var i=0;i<s.Length;i++){
            //两种回文-
            //1.奇数回文从同一个点向两边扩张,
            //2.偶数回文从相邻两个点向两边扩张 
            int len1=AroundLength(s,i,i);//获取当前索引下字符最大奇数回文
            int len2=AroundLength(s,i,i+1);//获取当前索引下偶数回文
            int len=Math.Max(len1,len2);//取较长的
            if(len>end-start+1){//全局取较长的
                start=i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.Substring(start,end-start+1);
    }
    private int AroundLength(string s,int left,int right) {
        int l=left,r=right;
        while(l>=0 && r<s.Length && s[l]==s[r]){
            l--;r++;
        }
        return r-l-1;//当前中心最大回文长度
    }
}
```