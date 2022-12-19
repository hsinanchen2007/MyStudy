![2020011101.PNG](https://pic.leetcode-cn.com/884a7f407f3b9d396c69f3e807cda645cdd05963eccc60748b38ca63c8e90e6c-2020011101.PNG)
### 解题思路
1)外层循环遍历每个字符串的字符;
2)内存循环遍历字符串数组A的每个字符串元素;
3)当出现((A[j].charAt(i)-'a')>(A[j+1].charAt(i)-'a'))时,即列中是降序时,停止内存循环遍历,输出结果out++;

### 代码

```java
class Solution {
    public int minDeletionSize(String[] A) {
        int out = 0;
    	for(int i =0;i< A[0].length();i++) {
    		int j =0;
    		while(j<A.length-1) {
    			if((A[j].charAt(i)-'a')<=(A[j+1].charAt(i)-'a')) {
    				j++;
    			}else {
    				out++;
    				break;
    			}
    		}
    	}
        return out;
    }
}
```