### 解题思路
1.因为字符串A要包含B，所以A的长度肯定要大于等于B的长度。先对A进行构造使其长度先大于等于B的长度，同时记录重复次数，如果A长度一开始就比B的长度长，那么A不变，重复次数就为1。
2.在A字符串的长度大于等于B的长度时，只需要让A的长度再增加一倍就能得出是否重复n次得到B。
3.重复构造字符串tA=A+A，如果tA不包含B的话就表示无法通过重复A得到B，此时返回-1；否则，就计算B在tA中最先出现的位置，并计算B在tA中匹配结束的位置。
4.通过tA的长度减去B的最后匹配的位置就得出匹配完B后还剩多长，这部门多出来的长度时不需要重复的，于是需要减去这部分重复的次数，就得到答案。

### 代码

```java
class Solution {
    public int repeatedStringMatch(String A, String B) {
        int n=B.length();
        String temp=A;
        while(A.length()<B.length()){
            A+=temp;
        }
        int i=A.length()/temp.length();
        if(A.contains(B)){
            return i;
        }
        String tA=A+A; 
        i*=2;
        if(!tA.contains(B)){
            return -1;
        }
        int j=tA.indexOf(B);
        int k=j+B.length()-1;
        // System.out.println("i=="+i);
        // System.out.println("tA.length=="+tA.length()+"k=="+k);
        int afterLen=tA.length()-k-1;
        return i-(afterLen/temp.length());
      }
    }
```