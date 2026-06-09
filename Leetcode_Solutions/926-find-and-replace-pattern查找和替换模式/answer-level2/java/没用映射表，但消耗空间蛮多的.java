	抛砖引玉了，这是我第一次独立做出来，结果发现和官方思路不太一样，就贴在这里了。希望有大神能给我一点建议。

	思路：用数字抽象字符，相同数字即为相同字符，以此构造对应pattern的数组和要测试的temp数组



class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ans = new ArrayList<>();
        for (int i = 0; i < words.length; i++) {
			if(isLike(words[i],pattern)) {
				ans.add(words[i]);
			}
		}
        return ans;
    }
    public boolean isLike(String temp , String pattern) {//用于匹配对应字符串
		int mark[] = new int[pattern.length()];
		int guess[] = new int[temp.length()];
		int k =0,m=0;
       
		for (int i = 0; i < pattern.length(); i++) {//用数字抽象字符pattern
			for(int j = i + 1 ; j<pattern.length();j++) {
				if(pattern.charAt(i) == pattern.charAt(j)) {
					if(mark[i]==0) {
						mark[i] =++k;
						mark[j] = mark[i];
					}else {
						mark[j] =mark[i];
					}
				}
			}
		}
		for (int i1 = 0; i1 < temp.length(); i1++) {//用数字抽象字符temp
			for(int j = i1 + 1 ; j<temp.length();j++) {
				if(temp.charAt(i1)== temp.charAt(j)) {
					if(guess[i1]==0) {
						guess[i1] =++m;
						guess[j] = guess[i1];
					}else {
						guess[j] =guess[i1];
					}
				}
			}
	}
		for (int j1 = 0; j1 < guess.length; j1++) {//匹配字符
			if(guess[j1]== mark[j1]) {
				continue;
			}else {
				return false;
			}
		}
		return true;
	}
}