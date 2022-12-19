### 解题思路
滑动窗口：
这道题我用Map,HashMap,作答，用到的方法有s.charAt(返回指定索引处的字符串)与map.containsKey(是否包含该字母)。
n为字符串的长度，ans为最大无重复字母大小
创建map集合，key为Character类型，value为Integer类型
创建i，j，取得s.charAt(i)字母，如果不存在，不需要判断j的位置，即重复数字的索引
如果存在，计算j的索引与前一次的最大值
ans计算时候取(i-j+1)与前一次循环的ans的最大值
把字母与它的索引放入map表中
eg："abcabcbb"
1.i=0,ss=a,ans=1,map.put(a,1)
2.i=1,ss=b,ans=2,map.put(b,2)
3.i=2,ss=c,ans=3,map.put(c,3)
4.i=3,ss=a,map表中存在a,j=Math.max(1,0),ans=Math.max(3-1+1,3),map.put(a,4)
5.i=4,ss=b,map表中存在b,j=Math.max(2,1),ans=Math.max(4-2+1,3),map.put(b,5)
6.i=5,ss=c,map表中存在c,j=Math.max(3,2),ans=Math.max(5-3+1,3),map.put(c,6)
7.i=6,ss=b,map表中存在b,j=Math.max(5,3),ans=Math.max(6-5+1,3),map.put(b,7)
8.i=7,ss=b,map表中存在b,j=Math.max(7,6),ans=Math.max(7-7+1,3),map.put(b,8)
如上过程，ans最后得到3
### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(),ans = 0;
        Map<Character,Integer> map = new HashMap<>();
        for(int i = 0,j = 0;i < n;i++){
            char ss = s.charAt(i);
            if(map.containsKey(ss)){
                j = Math.max(map.get(ss),j);
            }
            ans = Math.max(i-j+1,ans);
            map.put(s.charAt(i),i+1);
        }
        return ans;
    }
}
```