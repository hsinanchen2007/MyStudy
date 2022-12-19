很简单，遍历一遍字符串，设置两个标记值，标记大小写个数。
判断标准：>='a'即小写，<'a'即大写.
判断三种情况：
    1.全大写
    2.全小写
    3.首字母大写，其余小写
满足以上三种情况即返回true即可。
```
public boolean detectCapitalUse(String word) {
		int low = 0, high = 0;
		for (int i = 0; i < word.length(); i++) {
			if (word.charAt(i) >= 'a') {
				low++;
			} else {
				high++;
			}
		}
		if (low == word.length() || high == word.length() 
            || (high == 1 && low == word.length() - 1 
                        && word.charAt(0) < 'a')) {
			return true;
		} else {
			return false;
		}
	}
```
**时间复杂度：O(n) ;空间复杂度：O(1)**