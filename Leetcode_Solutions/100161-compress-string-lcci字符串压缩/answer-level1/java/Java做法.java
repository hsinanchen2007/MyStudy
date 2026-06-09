### 解题思路
遍历所给S字符串，取出当前下标的字符和此下标之后的字符对比，相同+1，不同直接结束内层循环。并在sb对象上附加取出的字符和数量。下一组下标则为i+count ;如此循环到最后，三目运算选择最佳结果。


### 代码

```java
class Solution {
    public String compressString(String S) {
        
        StringBuilder sb = new StringBuilder();

        for(int i = 0; i < S.length(); ){
			//获取一个字符
			char c = S.charAt(i);
			//统计的个数
			int count = 1;
			//从c字符的下一位开始统计与之相同的个数
			for (int j = i+1; j < S.length(); j++) {
				if(S.charAt(j) == c){
					count++;
				}else break;
			}
			// i表示下标，前一种统计完后下一种字符下标为i+count
			i += count;
			// 附加字符
			sb.append(c);
			sb.append(count);
		}
        // 三目运算符选择字符串最短的形式
		String ss = (S.length() > sb.length()) ? sb.toString() : S ;
		return ss;
    }
}
```