### 解题思路
这题的思路与马拉车算法经典题”给定一个字符串，请在字符串后面添加字符使它成为回文字符串，返回在字符串后面添加的最短字符串“一致,该问题的解题思路是在查找必须包含最后一个字符的情况下，最长的回文子串是多少，那么之前不是最长回文子串的部分逆序后就是应该添加的部分。
例如str="abcd123321",包括最后一个字符'1'的最长子回文为"123321"，那么剩余部分"abcd"应该逆序后添加到str后面，即"abcd123321dcba"。
按照上面的逻辑本题目也可按照这个思路，这个要求是在字符串前面添加字符使之转化成回文串，那么我们可以先将字符串翻转后，找到必须必须包含最后一个字符的最长子回文，如str="aacecaaa",翻转后revStr="aaacecaa"，包含最后一个字符的最长子回文为"aacecaa"，剩余不是最长子回文部分"a"直接添加到str的前面。

下面的代码，是按照标准的马拉车代码写的，不懂马拉车算法的可以先自学一下。

### 代码

```java
class Solution {
    public String shortestPalindrome(String s) {
        //马拉车
        if(s==null)
            return null;
        if(s.length()<=1)
            return s;
        //翻转字符串
        String rev=reverse(s);
        //生成马拉车字符，在原字符串前、后和中间插入'#'
        char[] charArr=manacherString(rev);
        //pArr[i]表示以i位置的字符作为回文中心，扩出去得到的最大回文半径大小
        int[] pArr=new int[charArr.length];
        //之前遍历的所有字符中的回文半径中，最右即将到达的位置
        int pR=-1;
        //最近一次更新pR时，回文中心的位置
        int index=-1;
        //最大回文子串包括到最后一个字符时，回文半径大小
        int maxContainsEnd=-1;
        for(int i=0;i<charArr.length;i++){
            pArr[i]=pR>i?Math.min(pArr[2*index-i],pR-i):1;
            while(i+pArr[i]<charArr.length&&i-pArr[i]>-1){
                if(charArr[i+pArr[i]]==charArr[i-pArr[i]])
                    pArr[i]++;
                else
                    break;
            }
            if(i+pArr[i]>pR){
                pR=i+pArr[i];
                index=i;
            }
            //判断最大回文子串是否包括到最后一个字符    
            if(pR==charArr.length){
                maxContainsEnd=pArr[i];
                break;
            }
        }
        //非回文部分
        char[] res=new char[s.length()-(maxContainsEnd-1)];
        for(int i=0;i<res.length;i++)
            res[i]=charArr[2*i+1];
        return String.valueOf(res)+s;
    }
    private char[] manacherString(String s){
        char[] chas=s.toCharArray();
        char[] charArr=new char[chas.length*2+1];
        int index=0;
        for(int i=0;i<charArr.length;i++){
            charArr[i]=(i&1)==0?'#':chas[index++];
        }
        return charArr;
    }
    private String reverse(String s){
        char[] chas=s.toCharArray();
        int l=0,r=chas.length-1;
        while(l<r){
            char temp=chas[l];
            chas[l]=chas[r];
            chas[r]=temp;
            l++;
            r--;
        }
        return new String(chas);
    }
}
```