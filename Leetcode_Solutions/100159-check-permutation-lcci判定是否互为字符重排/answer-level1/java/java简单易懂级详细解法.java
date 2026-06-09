### 解题思路
**题目：** 
    给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
**分析题意：**
    1:找出两个字符串是否为互为字符串，就是两个字符串排序后是否一致。
**解题思路：**     
    1：获取两个字符串的数组。
    2：判断两个数组长度，如果不一致直接返回，不必继续执行。
    2：通过Arrays.sort默认排序两个数组
    3：循环对比数组中元素，如果有一个不一致，那么将直接返回
**运行结果：**
![image.png](https://pic.leetcode-cn.com/3a4b10f1326a9ec6054908fd3724c1596ab32c4e898b100baa4fe1449edc1314-image.png)

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        //首先拿到两个字符串数组
		char[] charArray = s1.toCharArray();
		char[] charArray2 = s2.toCharArray();
        //获取是否字符串长度一致，不一致直接返回不符合
        if(charArray.length!=charArray2.length){
            //不符合
			return false;
        }
		//借助arrays默认排序
		Arrays.sort(charArray);
		Arrays.sort(charArray2);
		for (int i = 0; i <= charArray.length-1; i++) {
			if(charArray[i]!=charArray2[i]){
				//不符合
				return false;
			}
		}
		return true;
    }
}
```