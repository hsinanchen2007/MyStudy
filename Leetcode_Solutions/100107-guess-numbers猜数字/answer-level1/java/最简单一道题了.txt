### 解题思路


### 代码

```java
class Solution {
    public int game(int[] guess, int[] answer) {
        int correct = 0;
    	for (int i = 0; i < 3; i++) {
			if (guess[i]==answer[i]) {
				correct++;
			}
		}
    	return correct;
    }
}
```