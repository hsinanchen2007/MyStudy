解法一：动态规划：DP规则和初始化

执行结果：
通过
显示详情
执行用时 :
18 ms
, 在所有 Java 提交中击败了
59.53%
的用户
内存消耗 :
38.3 MB
, 在所有 Java 提交中击败了
22.43%
的用户
```
class Solution {
    
 	int min = 0;
    /**动态规划规则
    if(wi=wj){
        dp[i][j]=dp[i-1][j-1]
    }else{
        min=Math.min
            dp[i-1][j-1]
            dp[i][j-1]
            dp[i-1][j]
        dp[i][j]=min+1;
    }
    **/
	public int minDistance(String word1, String word2) {
		int l1 = word1.length();
		int l2 = word2.length();
        if (l1 == 0) {
            return l2;
        }
        if (l2 == 0) {
            return l1;
        }
        //注意初始化
        int[][] dp = new int[l1+1][l2+1];
        for(int i=0; i<=l1; i++){
            dp[i][0]=i;
        }
        for(int j=0; j<=l2; j++){
            dp[0][j]=j;
        }
        for(int i=0; i<l1; i++){
           for(int j=0; j<l2; j++){
                if(word1.charAt(i)==word2.charAt(j)){
                    dp[i+1][j+1]=dp[i][j];
                }else{
                     dp[i+1][j+1]=Math.min(dp[i][j],Math.min(dp[i+1][j],dp[i][j+1]))+1;
                }
               
            } 
        }
        return dp[l1][l2];
	}
    
}
```

解法二：BFS（按次数遍历）超时
```
int min = 0;

	public int minDistance(String word1, String word2) {
		int ll1 = word1.length();
		int ll2 = word2.length();
		min = Math.max(ll1, ll2);

		List<String[]> list = new ArrayList<>();
		String[] mid = new String[] {word1,word2};
		list.add(mid);
		int cc = 0;
		while(!list.isEmpty()) {
			
			if (cc >= min)
				break;// no need to process exceed limit;
			List<String[]> nl = new ArrayList<>();
			for(String[] mids:list) {
				word1 = mids[0];
				word2 = mids[1];
				int l1 = word1.length();
				int l2 = word2.length();
				int len = Math.min(l1,l2);
				int j = 0;
				for(int i = 0; i<len; i++) {
					if (word1.charAt(i) == word2.charAt(i)) {
						j=i+1;
					}else {
						break;
					}
				}
				word1 = word1.substring(j,l1);
				word2 = word2.substring(j,l2);
				 l1 = word1.length();
				 l2 = word2.length();
				if (l1 == 0) {
					if (cc + l2 < min) {
						min = cc + l2;
					}
					continue;
				}
				if (l2 == 0) {
					if (cc + l1 < min) {
						min = cc + l1;
					}
					continue;
				}
				
				nl.add(new String[] {word1.substring(1, l1), word2.substring(1, l2)});// change
				nl.add(new String[] {word1.substring(1, l1), word2});// remove 1st char from word1
				nl.add(new String[] {word1, word2.substring(1, l2)});// put 1st char of word2 as 1st of word1
				
			}
			list = nl;
			cc++;
		}

		return min;

	}
```

解法三： DFS（暴力递归），超时
```
	int min = 0;

	public int minDistance(String word1, String word2) {
		int l1 = word1.length();
		int l2 = word2.length();
		min = Math.max(l1, l2);

		pro(word1, word2, 0);

		return min;

	}

	private void pro(String word1, String word2, int count) {
		// System.out.println(word1+"+"+word2+"+"+count);
		if (count >= min)
			return;// no need to process exceed limit;

		int l1 = word1.length();
		int l2 = word2.length();

		if (l1 == 0) {
			if (count + l2 < min)
				min = count + l2;
			return;
		}
		if (l2 == 0) {
			if (count + l1 < min)
				min = count + l1;
			return;
		}

		if (word1.charAt(0) == word2.charAt(0)) {
			pro(word1.substring(1, l1), word2.substring(1, l2), count);
		} else {
			count++;
			pro(word1.substring(1, l1), word2.substring(1, l2), count);// change
			pro(word1.substring(1, l1), word2, count);// remove 1st char from word1
			pro(word1, word2.substring(1, l2), count);// put 1st char of word2 as 1st of word1
		}

	}
```



