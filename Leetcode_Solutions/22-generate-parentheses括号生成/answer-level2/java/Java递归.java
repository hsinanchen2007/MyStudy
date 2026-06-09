执行用时 :3 ms, 在所有 Java 提交中击败了86.49%的用户
内存消耗 :38.8 MB, 在所有 Java 提交中击败了50.57%的用户	
在网上看到了一个解法，但是改进了一点
原地址为：https://blog.csdn.net/be_gin_ner/article/details/90524141

    public static List<String> generateParenthesis(int n) {
		List<String> al = new ArrayList<>();
		add(al, "", 0, 0, n);
		return al;
	}

	public static void add(List<String> al, String s, int count1, int count2, int n) {
		if (count1 < n && count1 > count2) {
			String ss = new String(s);
			add(al, ss += "(", count1 + 1, count2, n);
			add(al, s += ")", count1, count2 + 1, n);
		} else if (count1 < n && count1 == count2) {
			add(al, s += "(", count1 + 1, count2, n);
		} else if (count1 == n) {
			for (int i = 0; i < n - count2; i++) {
				s += ")";
			}
			al.add(s);
		}
	}