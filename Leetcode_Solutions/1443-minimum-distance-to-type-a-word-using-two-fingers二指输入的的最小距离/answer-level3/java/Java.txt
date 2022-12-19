### 解题思路
在二指移动中可以以二指相对字符串的位置来定义状态
dp[x][y]表示二指分别在x处与y处时移动的距离
定义0<=x,y<=word.length();
0表示手指还未移动
x或y ==word.length()时表示移动完毕

显然x,y中的较大值也是总体移动的进度
分析状态i到i+1的转移方式
dp[?][i]或dp[i][?] 其中 ?<i  转化为ndp[i+1][]或ndp[][i+1]

最后找出最小值即可

### 代码

```java
class Solution {
    public static String STR =null;
    public int minimumDistance(String word) {
        STR=word;
        int[][] dp = new int[word.length()+1][word.length()+1];
        dp[0][0]=0;
        for(int i=0;i<word.length();i++){
            int[][] ndp = new int[word.length()+1][word.length()+1];
            int temp = Integer.MAX_VALUE;
            for(int x=0;x<i;x++){
                ndp[x][i+1]=dp[x][i]+mov(i,i+1);
                temp=Math.min(dp[x][i]+mov(x,i+1),temp);
                ndp[i+1][i] = temp;
            }

            temp = Integer.MAX_VALUE;
            for(int y=0;y<i;y++){
                ndp[i+1][y]=dp[i][y]+mov(i,i+1);
                temp=Math.min(dp[i][y]+mov(y,i+1),temp);
                ndp[i][i+1] = temp;
            }

            dp=ndp;
        }
        int result = Integer.MAX_VALUE;
        for(int x=0;x<dp.length;x++){
            for(int y=0;y<dp[0].length;y++){
                if(x==word.length()||y==word.length()){
                    if(x==y){continue;}
                    result = Math.min(result,dp[x][y]);
                }
            }
        }
        return result;
    }
    public static int mov(int a, int b) {
        if(a==0||b==0){
            return 0;
        }
        int c1 = STR.charAt(a-1)-'A';
        int c2 = STR.charAt(b-1)-'A';
        return Math.abs(c1/6-c2/6)+Math.abs(c1%6-c2%6);
    }
}
```
### 解题思路
暴力搜索
测试用例为"HAPPY"时输出正常
但提交时有异常,在这里反映下

以下为报错代码

```java
class Solution {
    public static Map<String, Integer> map = new HashMap<>();
    public int minimumDistance(String word) {
       return dfs(word,(char)0,(char)0,0);
    }

    public static int dfs(String word, char p1,char p2 ,int index){
        if(index == word.length()){
            return 0;
        }
        Integer integer = map.get("" + p1 + p2 + index);
        if(integer!=null){
            return integer;
        }
        int len = dfs(word,p1,word.charAt(index),index+1)+mov(p2,word.charAt(index));
        int len2 = dfs(word,word.charAt(index),p2,index+1)+mov(p1,word.charAt(index));
        int min = Math.min(len,len2);
        map.put(""+p1+p2+index,min);
        return min;
    }


    public static int mov(char a, char b) {
        if(a==0||b==0){
            return 0;
        }
        int c1 = a-'A';
        int c2 = b-'A';
        return Math.abs(c1/6-c2/6)+Math.abs(c1%6-c2%6);
    }
}
```
修改后可以通过
```
class Solution {
  
     public int minimumDistance(String word){
         Map<String, Integer> myMap = new HashMap<>();
        return dfs(word,(char)0,(char)0,0,myMap);
     }
     
    public static int dfs(String word, char p1,char p2 ,int index,Map<String, Integer> myMap){
        if(index == word.length()){
            return 0;
        }
        Integer mapVal = myMap.get("" + p1 + p2 + index);
        if(mapVal!=null){
            return mapVal;
        }
        int len = dfs(word,p1,word.charAt(index),index+1,myMap)+mov(p2,word.charAt(index));
        int len2 = dfs(word,word.charAt(index),p2,index+1,myMap)+mov(p1,word.charAt(index));
        int min = Math.min(len,len2);
        myMap.put(""+p1+p2+index,min);
        return min;
    }


    public static int mov(char a, char b) {
        if(a==0||b==0){
            return 0;
        }
        int c1 = a-'A';
        int c2 = b-'A';
        return Math.abs(c1/6-c2/6)+Math.abs(c1%6-c2%6);
    }
}
```
