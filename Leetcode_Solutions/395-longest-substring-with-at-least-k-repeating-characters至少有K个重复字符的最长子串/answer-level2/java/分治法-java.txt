### 解题思路
对每个元素都计算它在子串里的出现频率是否大于等于k个,若不大于等于k个必然不在最终结果里,分两半递归求解.
*此子问题没有重叠子问题性质*
- 找到给定字符串（由小写字符组成）中的最长子串 T,要求 T 中的每一字符出现次数都不少于 k 。
- 注意: 不要求连续,只要存在多余等于k个就行, 使用数组来存'频率':time

### 代码

```java
class Solution {
    /*
    找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。
    注意: 不要求连续,只要存在多余等于k个就行, 使用数组来存'频率':time
    */
    char[] strs;
    int k;
    public int longestSubstring(String s, int k) {
        if(s.length()<k) return 0;
        this.strs=s.toCharArray();
        this.k=k;
        return recur(0,s.length()-1);
    }
    public int recur(int l,int r){
        // 不合法的返回
        if(r-l+1<k) return 0;
        // 初始化time数组
        int[]time=new int[26];
        for(int i=l;i!=r+1;i++)
            time[strs[i]-'a']++;
        // 不合法的略过
        while(l<=r&&time[strs[l]-'a']<k) l++;
        while(l<=r&&time[strs[r]-'a']<k) r--;
        if(r-l+1<k) return 0;
        //对该子串里的元素逐个遍历,不符合的递归分治求解
        for(int i=l;i!=r+1;i++){
            if(time[strs[i]-'a']<k){
                return Math.max(recur(l,i-1),recur(i+1,r));
            }
        }
        // 其中的每一个元素都是合法的
        return r-l+1;
    }
}
```