### 解题思路
参考的是题解中官方题解方法一：按字符分组；
这里就不详细说了，看到我这个题解之前肯定已经看过官方题解了。
![QQ截图20200131174403.png](https://pic.leetcode-cn.com/d72ad3b1720a87b2a3ad85a4431bf5c52fb6bf5d36c498ee03bfd5000f969bed-QQ%E6%88%AA%E5%9B%BE20200131174403.png)
细节就是引入了groups数组存储
测试过程中出错的地方：在代码第13行，groups[t]的值应为1，而不是0，因为不一样的时候，已经是一个新的字符（0/1）了，已经出现了一次了

### 代码

```java
class Solution {
    public int countBinarySubstrings(String s) {
         int[] groups = new int[s.length()];
        char[] sa = s.toCharArray();
        // 填充groups数组
        int t = 0;
        groups[0] = 1;
        for(int i=1; i<s.length();i++) {
        	if(sa[i] == sa[i-1]) {
        		groups[t]++;
        	}else {
        		t++;
        		groups[t] = 1;
        	}
        }      
        // 对t遍历计算返回值
        int result = 0;
        for(int i=0;i<t;i++) {
        	result += Math.min(groups[i], groups[i+1]);
        }
		return result;
    }
}
```