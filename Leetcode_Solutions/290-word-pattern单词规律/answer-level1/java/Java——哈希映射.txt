![QQ图片20200311211505.png](https://pic.leetcode-cn.com/89abb1942fe16b34950fbf58a5558fda9c7e2e333840b763fd8c7f4dc742e112-QQ%E5%9B%BE%E7%89%8720200311211505.png)

### 解题思路
1、首先要保证两个字字符串相对应（即把它们转换为数组后的长度要相等，不相等则返回false）

2、借助哈希表完成“翻译”工作（翻译准则只有一个，一一对应）

3、实现哈希表后，然后就遍历，开始往哈希表填入数据（填入数据时有讲究：空哈希表可直接插入数据；哈希表中同时不存在此时遍历得到的Key和Value值时可插入数据）————这个过程等于就是在制定“ASCII码表”：起先没有任何规则，你要创造一个一个全新的对应关系，什么是全新的对应关系呢？就是你选的Key和Value在map中都找不到，这就是全新的对应关系

4、然后是题目要求的 遵循完全匹配，即不可以出现这样的情况：假如你已经插入了两条数据，一是字符a对应的ASCII值为97，二是字符b对应的ASCII值为98，之后你再遍历得到的数据是字符a对应的ASCII值为98或者字符c对应的ASCII值为97，这两种情况你认为可以插入map中成为新的对应关系么？答案是否定的，所以，遇到这样类似的情况，我们即可返回false

5、最后再提一句，如果你已经插入了两条数据，一是字符a对应的ASCII值为97，二是字符b对应的ASCII值为98，之后你再遍历得到的数据是字符a对应的ASCII值为97，你觉得还应插入map中么？答案是否定的，因为你已经制定好了这一规则了，为啥又要增加一个重复的嘞

### 代码

```java
class Solution {
    public boolean wordPattern(String pattern, String str) {
	char[] chs = pattern.toCharArray();
	String[] strs = str.split(" ");
	if(chs.length != strs.length) {
		return false;
	}
	Map<Character, String> map = new HashMap<>();
	for(int i = 0; i <= chs.length-1; i++) {
		if(map.isEmpty() || (!map.containsKey(chs[i]) && !map.containsValue(strs[i]))) {
			map.put(chs[i], strs[i]);
		}else if( (map.containsKey(chs[i]) && !map.get(chs[i]).equals(strs[i])) ||
				(!map.containsKey(chs[i]) && map.containsValue(strs[i])) ) {
			return false;
		}
	}
	return true;
    }
}
```