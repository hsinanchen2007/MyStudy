### 代码

```java
class Solution {
    public int countCharacters(String[] words,String chars){
		int totalLength = 0;
		for(int i=0;i<words.length;i++){
			if(formWord(words[i],chars)){
				totalLength = totalLength + words[i].length();
			}
		}
		return totalLength;
	}
	
	public boolean formWord(String word,String chars){
		// 判断单词word能否由chars组成
		if(word.length()>chars.length()){
			return false;
		}
		for(int i=0;i<word.length();i++){
			char ch = word.charAt(i);
			String str = Character.toString(ch);
			if(chars.contains(str)){
				int index = chars.indexOf(ch);
				// 删掉刚刚用过的字符
				// String的本质是值传递，不是引用传递，这里可以放心操作
				chars = chars.substring(0, index)+chars.substring(index+1);
			}else{
				return false;
			}
		}
		return true;
	}
}
```

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/a353efe5df64a922d8c5ec3d6eb34547042d66dd9d94d8bdddc13c9523961363-wechat.png)
