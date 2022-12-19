### 解题思路
此处撰写解题思路
利用for 中的i为center 向两边拓展 如果相等就延伸
延伸过程记录最大子串长度和子串的起始位置
## 文章摘抄笔记
首先，要明白for作用是以一个中心向两侧扩展找到这个中心最长回文串的长度，参数left和right就是为了指定中心。
其次，中心可能是一个或两个字符。如：对于字符串“abcda”，“c”是中心；对于字符串“adccda”，“cc”是中心。
那么，expandAroundCenter(s, i, i)就是在找以 i（一个字符）为中心的最长回文串的长度；expandAroundCenter(s, i, i + 1)是在找以 i 和i+1（两个字符）为中心的最长回文串的长度。
将得到的两个长度和缓存的最长回文串长度相比较。若新得到的长度较长，表达式：start = i - (len - 1) / 2;end = i + len / 2; 就得出了新的最长回文串的开始和结束位置。
最后，for循环遍历了一遍，以一个字符为中心总共找了 n 次，以两个字符为中心总共找了 n-1 次，所以说“总共有2n−1 个这样的中心”。

## 动态规划理解笔记
中心扩散的方法，其实做了很多重复计算。动态规划就是为了减少重复计算的问题。动态规划听起来很高大上。其实说白了就是空间换时间，将计算结果暂存起来，避免重复计算。作用和工程中用 redis 做缓存有异曲同工之妙。
动态规划关键是找到初始状态和状态转移方程。

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {//最大回文子串就是你最大对称子串
    //这个问题需要的就是找到串，其次判断是否是回文串 利用中心扩散法
    if(s == null || s.length() == 0){
        return "";
    }
     int len=1,left=0,right=0,MaxLen=0,MaxStart=0;
     int lenStr=s.length();
     for(int i=0;i<lenStr;i++){//i为中心center
      right=i+1;
      left=i-1;
      while(left >= 0 && s.charAt(left)==s.charAt(i)){//判断左移动 字符和center 相等情况
       left--;//更新指针
       len++;
      }
      while(right<lenStr && s.charAt(right)==s.charAt(i)){//判断右移动 字符和center 相等情况
       right++;
       len++;
      }
      while(right<lenStr && left>=0 && s.charAt(right)==s.charAt(left)){
          //判断左右移动right和left 相等情况
       left--;
       right++;
       len=len+2;
      }
      if(len>MaxLen){//更新最大 并记录最大值的 起始位置
          MaxLen=len;
          MaxStart=left;
      }
      len=1;//每一轮更新len
     }
     return s.substring(MaxStart + 1,MaxStart+MaxLen+1);//检测最后弹出while的情况
    }
}
```