### 解题思路
两个Boolean数组来描述是否已经检查过了，之后只需要比较+更新数组即可。但是效率比较低。

### 代码

```java
class Solution {
    public String getHint(String secret, String guess) {
            int bull = 0 ,cow = 0;
	        int len = guess.length();
	        boolean [] flag1 = new boolean[len];//对于secret，检查是否用过了
	        boolean [] flag2 = new boolean[len];//对于guess,检查是否用过了
	        for(int i = 0 ; i < guess.length() ;i ++){
	            if(secret.charAt(i) == guess.charAt(i)){
	                bull++;
	                flag1[i] = true;
	                flag2[i] = true;
	            }
	        }
	        for(int i = 0 ; i < len ;i++) {
	        	if(flag1[i]) continue;
	        	for(int j = 0 ; j < len ;j ++) {
	        		if(flag2[j])continue;
	        		if(secret.charAt(i) == guess.charAt(j)) {
	        			cow++;
	        			flag1[i] = true;
	        			flag2[j] = true;
                        break;
	        		}
	        	}
	        }
	        String ans = bull + "" + "A" + cow +"" + "B";
	        return ans;
    }
}
```
时间复杂度O(N^2),空间复杂度O(N)。