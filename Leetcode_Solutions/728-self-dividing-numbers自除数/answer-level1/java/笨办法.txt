class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> list = new ArrayList<>();
		for (int i = left; i <= right; i++) {
			String s = String.valueOf(i);
			int index = 0;
			for (int j = 0; j < s.length(); j++) {
				if(s.charAt(j) != '0') {
					if(i % Integer.parseInt(String.valueOf(s.charAt(j)))==0) {
						index++;
					}
				}
			}
			if(index == s.length()) {
				list.add(i);
			}
		}
		return list;
    }
}