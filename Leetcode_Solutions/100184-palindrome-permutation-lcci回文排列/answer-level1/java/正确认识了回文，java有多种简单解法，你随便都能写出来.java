### 解题思路
**题目:**
    给定一个字符串，编写一个函数判定其是否为某个回文串的排列之一。
    回文串是指正反两个方向都一样的单词或短语。排列是指字母的重新排列。
    回文串不一定是字典当中的单词。
**分析题意：**
    1：回文指的就是类似“aba”,正反的值都是一样的。
    2：分析出给定的字符串经过排序后是否能达到回文效果。
**解题思路：**
    1：回文其实我们认真分析一下，是不是就是，一组字符串中如果所有字符出现的次数是偶数，或者只有一个字符出现了一次，其他都出现了偶数次，那么是不是就能拼装成一个回文字符串，例如
![image.png](https://pic.leetcode-cn.com/1277792c1fe9a180326ed29cc626c6274b2635789c4293e486bddfe7783494d0-image.png)
这下就简单了。
    2：首先我们循环遍历字符串
    3：然后将字符串依次放入一个list中，再放入之前判断之前是不是放进去过，如果是那么就删除，不是就添加进去一个。
    4：最后得到的结果集合，如果其中的字符不是1个或者0个那么就证明它不是回文字符串。

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
		//获取字符串数组
		char[] charArray = s.toCharArray();
		List<Character> list=new LinkedList<>();
		for (int i = 0; i < charArray.length; i++) {
			//判断是否包含，包含删除不包含就添加。
			if(list.contains(charArray[i])){
				list.remove(Character.valueOf(charArray[i]));
			}else {
				list.add(charArray[i]);
			}
		}
		   //如果最后发现list中有1个以上的字符，那么就代表不是回文
		if(list.size()>1){
			return false;
		}
		return true;	
    }
}
```