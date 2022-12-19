### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public static int minDistance(String word1, String word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        int dp[][] = new int[len1+1][len2+1];
        for (int i = 0; i <len1+1 ; i++) {
            dp[i][0]=i;
        }
        for (int i = 0; i < len2+1 ; i++) {
            dp[0][i]=i;
        }

        for (int i = 1; i <=len1 ; i++) {
            for (int j = 1; j <=len2 ; j++) {
                if(word1.charAt(i-1) == word2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j] = Math.min(Math.min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                }
            }
        }
        return dp[len1][len2];
    }
}
```

以 word1 为 "horse"，word2 为 "ros"，且 dp[5][3] 为例，即要将 word1的前 5 个字符转换为 word2的前 3 个字符，也就是将 horse 转换为 ros，因此有：

(1) dp[i-1][j-1]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 2 个字符 ro，然后将第五个字符 word1[4]（因为下标基数以 0 开始） 由 e 替换为 s（即替换为 word2 的第三个字符，word2[2]）

(2) dp[i][j-1]，即先将 word1 的前 5 个字符 horse 转换为 word2 的前 2 个字符 ro，然后在末尾补充一个 s，即插入操作

(3) dp[i-1][j]，即先将 word1 的前 4 个字符 hors 转换为 word2 的前 3 个字符 ros，然后删除 word1 的第 5 个字符

(4) word1[i] == word2[j] , dp[i][j] = dp[i-1][j-1]
记住这4种情况。

dp[i][j] = Math.min(dp[i-1,j],dp[i][j+1],dp[i][j])+1;
这个公式记住下，我们待会会在下面的这个图讲解中用到


![WechatIMG12033.jpeg](https://pic.leetcode-cn.com/afac4373917f8684e9039bd1ba4c1151eb58f36fe456645fd0375ddbf951c46a-WechatIMG12033.jpeg)

我们首先来说下第一幅图

dp[0,1] --> [] -->r  就是空格到 r，就是1步，插入a
dp[0,2] --> [] -->ra  就是空格到 ra，就是2步，插入ra
dp[0,3] --> [] -->ras  就是空格到 ras，就是3步，插入ras
dp[1,0] --> a -->[]   a到空格，就是1步，把a删掉
dp[1,1] --> a -->r   a到r，就是替换

dp[1,2] --> a -->ra  a到ra，可以参考上面第四种情况  现在i是1，j是2  word1[i]=word[j]--> word1[1]=word[2]
也就是，dp[1,2] = dp[0,1] 。看图也应该知道，a是相等的，只要在前面加个r就可以了，所以只需要1步

dp[1,3] --> a -->ras  a到ras，大家也看到了。我只需要在dp[1,2]基础上，再插入一个字母s就能拼成ras，这是最简便的

dp[2,0] --> as -->空格 ，就是2步，把as都删掉

dp[2,1] --> as-->r , 到这里，我开始给大家科普一下 dp[i][j] = Math.min(dp[i-1,j],dp[i][j+1],dp[i][j])+1;

1. dp[2][1] = dp[2][0]+1=3 ，对应dp[i][j-1]就是上面的第二种情况，插入操作。把as变为空，插入r,因为as到空需要2步，再插入r需要1步，所以这里就是3步了
2. dp[2][1] = dp[1,1]+1 = 2, 对应dp[i-1][j]就是上面的第三种情况，把a变为r，然后把s删掉，替换后删除，所以这里是2步
3. dp[2][1] = dp[1][0]+1=2, 对应dp[i-1][j-1] 就是上面的替换操作，把a变为空，然后把s替换为r。所以这里是2步操作
4. 所以这里我们要取这三步最小的那一步作为 dp[i][j]的值

dp[2,2] --> as-->ra ,从dp[1][1] dp[i-1][j-1] 从a变为r，然后把s替换为a。两步，或者 dp[1][2] dp[i-1][j]
在a前面插入r，然后把s删掉。也是2步

dp[2,3] --> as-->ras,这里 word1[i]=word2[j]  dp[2]=dp[3],s=s 所以 dp[2][3] = dp[1][2],只要完成a变为ra。后面的s就在那里，就不需要变动

dp[3,0] --> asd-->[], 3步，把asd全部删掉

dp[3,1] --> asd-->r,
1. dp[i-1,j-1] dp[2,0]+1 -->as 变成 []，然后把d替换为r，所以是3步。
2. dp[i-1,j]  dp[2,1]+1 --> as变成r，然后删掉d，所以是3步。
3. dp[i,j-1] 这里不能dp[3,0]+1,把asd删掉，再插入r，所以这里是4步。 
4. Math.min(dp[i-1,j-1],dp[i-1,j],dp[i,j-1])+1  所以这里是3

dp[3,2] --> asd --> ra 
1. dp[i-1,j-1] dp[2,1]+1 -->as 变成 r，然后把d替换为a,所以是3步。
2. dp[i-1,j]  dp[2,2]+1 --> as变成ra，然后删掉d，所以是3步。
3. dp[i,j-1] 这里不能dp[3,1]+1,把asd变为r，然后再插入a，所以这里是4步。 
4. Math.min(dp[i-1,j-1],dp[i-1,j],dp[i,j-1])+1  所以这里是3

dp[3,3] -->asd -->ras
上面都分析完了，所以这里交给你了

两个图，我分析了一个图，另一个也交给你们了。如果一步步看下来，我觉得你应该能结合图更好的理解
Math.min(dp[i-1,j-1],dp[i-1,j],dp[i,j-1])+1  这个公式


