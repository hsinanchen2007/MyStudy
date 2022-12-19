### 解题思路
执行用时 :
0 ms
, 在所有 java 提交中击败了
100.00%
的用户
内存消耗 :
34.1 MB
, 在所有 java 提交中击败了
100.00%
的用户
### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int res=0;
        if(Arrays.equals(answer, guess)) {
        	return 3;
        }
        for(int i=0;i<3;i++) {
        	if(guess[i]==answer[i]) {
        		res++;
        	}
        }
        
        return res;
    }
}
```