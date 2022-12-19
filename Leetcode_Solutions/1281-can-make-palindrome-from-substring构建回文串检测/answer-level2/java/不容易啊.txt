有一点点动态规划的感觉

### 代码

```java
class Solution {
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        List<Boolean> ans=new ArrayList<Boolean>(queries.length);
        char[] wordList = s.toCharArray();
        int[][] wordcnt =new int[s.length()][26];
        int left,right,i,j,count,odd;
        wordcnt[0][wordList[0]-'a']++;
        for (i = 1; i < wordList.length; i++) {
               for(j=0;j<26;j++){
                   wordcnt[i][j]=
                           wordcnt[i-1][j];
               }
               wordcnt[i][wordList[i]-'a']++;
        }
        for(i=0;i<queries.length;i++){
            left=queries[i][0];
            right=queries[i][1];
            odd=0;
            for (j=0;j<26;j++){
                if(left>1)
                    count=wordcnt[right][j]-wordcnt[left-1][j];
                else
                    count=wordcnt[right][j];
                if(count>0&&count%2==1){
                    odd++;
                }
            }
            if(odd/2<=queries[i][2]){
                ans.add(true);
            }else {
                ans.add(false);
            }
        }
        return ans;
    }
}
```