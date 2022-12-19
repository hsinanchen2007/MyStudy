### 解题思路
算法思想：

- 很显然存在递推关系，所以很明显要用动态规划，虽然递推关系不太能直接用公式来描述
- 递推关系： strs[n]中的字符确定方法为：strs[n-1]中的连续字符个数+这个字符
- 递推起点为 strs[0]和strs[1]



1. 确定递推起点 strs[0]和strs[1]
2. 逐个向后推，递推关系如上表示
3. 最后返回 strs[n-1]，因为编号从0开始




### 代码

```java
class Solution {
   public String countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        //用数组去存放递推的结果
        String[] strs=new String[n];
        //递推起点
        strs[0]="1";
        strs[1]="11";
        //依次递推从2到n-1的每一个字符串
        for(int i=2;i<n;i++){
        	//k记录strs[i-1]中正在被计算个数的字符索引，从0开始
            int k=0;
            //必须初始化为空字符串，否则会出现空指针异常
            strs[i]="";
            //用j来跟随相同的字符，若相同则++
            int j=0;
            while(j<strs[i-1].length()) {
            	//num记录相同字符的个数
                int num=0;
                //当字符相同时，num++，j++
                while (j<strs[i-1].length()&&strs[i - 1].charAt(j) == strs[i - 1].charAt(k)) {
                    num++;
                    j++;
                }
                //当字符不同后跳出上面的循环，此时需要更新strs[i]的值
                strs[i] = strs[i].concat("" + num + strs[i - 1].charAt(k));
                //将j的值赋给为k，以记录下一次循环所要计算的字符的重复个数
                k = j;
            }
        }
        //最后返回结果
        return strs[n-1];
    }
}
```