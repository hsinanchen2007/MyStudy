### 代码

```java
class Solution {
	// 暴力解法，看看思路就好，不用学我
    public int minimumLengthEncoding(String[] words){
		// 可以压缩的情况：某一单词是前面已经传入的单词的一个后缀，或某之前传入的单词是当前单词的一个后缀
		// 是否为后缀可以通过一个isSuffix(String origin,String str)方法来判断
		// 计算无法压缩的n个单词的总长度，并加上n-1个'#'的长度，即是返回值
		if(words.length == 0){
			return 0;
		}
		List<String> res = new ArrayList<>();
		for(int i=0;i<words.length;i++){
			if(i == 0){
				res.add(words[i]);
			}else{
				for(int j=0;j<res.size();j++){
					if(isSuffix(res.get(j),words[i])){
						break;
					}else if(isSuffix(words[i],res.get(j))){
						res.set(j, words[i]);// 修改res中对应位置的值
						break;
					}
					if(j == res.size()-1){
						// 若没有后缀关系的元素，则需要将这个单词加入res中
						res.add(words[i]);
					}
				}
			}
		}
		// 遍历结果数组，计算最终应该返回的总长度
		int sum = res.size();// '#'号的数量
		for(int i=0;i<res.size();i++){
			sum += res.get(i).length();
		}
		return sum;
	}
	
	public boolean isSuffix(String origin,String str){
		int i = str.length()-1;
		int j = origin.length()-1;
		if(i>j){
			return false;
		}
		while(i>=0 && j>=0){
			if(str.charAt(i) == origin.charAt(j)){
				i--;
				j--;
				continue;
			}else{
				return false;
			}
		}
		return true;
	}
}
```