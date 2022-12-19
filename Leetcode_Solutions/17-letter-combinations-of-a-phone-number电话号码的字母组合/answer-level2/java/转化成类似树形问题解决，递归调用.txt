    //递归思想
	String[] nums = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
	List<String> res = new LinkedList<>();
	public List<String> letterCombinations(String digits) {
		if(digits.length() == 0) return res;
		helper(digits,0,"");
		return res;	
    }
	//参数2，3分别是处理到第几个字符，和前面以及处理好的字符
	private void helper(String digits, int index, String string) {
		//递归函数
		//递归结束条件   注意此时可以看作是树形结构DFS到底到空节点  此时要返回从根节点到叶子节点的字符串
		//在这里就是诸多字符串中的一条
		if(index == digits.length()) {		
			res.add(string);
			return;
		}
		//递归部分
		char c = digits.charAt(index);
		assert (c >= '0' && c <= '9' && c != '1');
		String s = nums[c - '0'];	//注意这里-'0'
		for(int i = 0; i < s.length(); i ++) {
			helper(digits,index+1,string.concat(s.charAt(i) + ""));
		}
	}
	public static void main(String[] args) {
		LeetCode17 lt = new LeetCode17();
		String digits = "23";
		System.out.println(lt.letterCombinations(digits));
	}