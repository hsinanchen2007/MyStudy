### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    //如果是使用动态规划的算法 那么就需要进行数据 递归 
    public String longestPalindrome(String s) {
        if("".equals(s)){
            return "";
        }
        int start=0;
        int end=0;
        for (int i=0;i<s.length();i++){//i 代表中心点
            int len1=len(s,i,i);
            int len2=len(s,i,i+1); // 注意就算是偶数作为中心点 中心点的坐标也是最小那个
            int len=Math.max(len1,len2);
            if(len>end-start){//如果新的长度更加长 那么就更新
                start=i-(len-1)/2; //始终i是中心坐标最小那个 
                end=i+len/2;
            }
        }
        return s.substring(start,end+1);

    }
    //这个函数的作用是不断从两侧扩张 寻找以i为中心点的 最长回文串
    public int len(String s,int L ,int R){
        while(L<=R&&L>=0&&R<s.length()&&s.charAt(L)==s.charAt(R)){
            L--;
            R++;
        }
        return R-L-1;
    }
}
```