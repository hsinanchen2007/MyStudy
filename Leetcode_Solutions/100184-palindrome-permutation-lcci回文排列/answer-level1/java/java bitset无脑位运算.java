### 解题思路
位运算可以是底层程序猿的最后一根猴毛

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
    	BitSet bs = new BitSet(128);
    	for(int i =0 ;i<s.length() ;i++) {
    		bs.flip(s.charAt(i));
    	}
    	return bs.isEmpty() || bs.cardinality()==1;
    }
}
```