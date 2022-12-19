### 解题思路
![QQ截图20200320163421.png](https://pic.leetcode-cn.com/1339c4f30ba764b930e6390e868327a91951e483a436edb08fd48567215b6c95-QQ%E6%88%AA%E5%9B%BE20200320163421.png)

别问我思路，我不知道思路，这个题真是有史以来第一次没过脑子就码代码，纯凭着感觉摸出来的，第一反应是dp,结果码完了发现根本就没用到dp,递归方程是啥我都不知道，本来想提交看看哪些测试用例没通过再改改，结果这就尼玛AC了？我连题意还没搞明白呢！


实际上大致是有思路的：就是到s[j]时，s[0]到s[j]如果可分（即dp[j]=T)，要么s[0...j]本身是一个单词;要么，一定存在某个位置arr(1<=arr<=j)到j之间的字符串s[arr...j]是一个单词，而且s[0...arr-1]之间可分(即dp[arr-1]=T),而这个arr只可能是s[0]到s[j-1]里能够划分出单词的那些位置,我用arrayList记录这些位置，到s[j]时就遍历此时的arrayList,每成功分一次，就在arrayList里记录下这个位置


比如："apple",{"a","ap","ppl","le"}
j=0:dp[0]=T,arraylist={1}
j=1:遍历arraylist,s[1...1]=="p"not in dict;但"ap" in dict,所以arraylist={1,2},dp[1]=T
j=2:遍历arraylist,"pp" not in dict,"p" not in dict;而且"app" not in dict,dp[2]=F
j=3:遍历arraylist,"ppl" in dict,所以arraylist={1,2,4},dp[3]=T
j=4:遍历arraylist,"pple" not in dict,"ple" not in dict,"e" not in dict;而且 "apple" not in dict,所以dp[4]=F

我就这么做出来了，应该是凭感觉把规律碰对了，惭愧。。。。




补一下这题的递归方程：
dp[i] = ( dp[i-1] && contains(subStr(i-1,i))  )
        || (  dp[i-2] && contains(subStr(i-2,i))  )
        || (  dp[i-3] && contains(subStr(i-3,i))  ) 
        || ...
### 代码

```java
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
         if(wordDict.isEmpty()) return false;
        boolean [] dp=new boolean[s.length()];
        for (boolean b:dp
             ) {
            b=false;
        }
        ArrayList<Integer> arrayList=new ArrayList<>();
        if(wordDict.contains(s.substring(0,1))) {
            dp[0]=true;
            arrayList.add(1);
        }
        for(int j=1;j<dp.length;j++){
            for(int i=0;i<arrayList.size();i++){
                if(arrayList.get(i)<=j){
                    if(wordDict.contains(s.substring(arrayList.get(i),j+1))){
                        dp[j]=true;
                        arrayList.add(j+1);
                        break;
                    }
                }
            }




            if(wordDict.contains(s.substring(0,j+1))) {
                dp[j]=true;
                arrayList.add(j+1);
            }

        }
        return dp[s.length()-1];

    }
}
```