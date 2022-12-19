public class Solution {
	int short_time = Integer.MAX_VALUE;

	public int minMutation(String start, String end, String[] bank) {
		List<String> codeFactory = new ArrayList(Arrays.asList(bank));
		if(codeFactory.size()==0||!codeFactory.contains(end))
			return -1;
		if (!codeFactory.contains(start)) {// 完善基因库
			codeFactory.add(start);
		}
		compare(start, end, codeFactory,new ArrayList<String>(),0);
		if(short_time==Integer.MAX_VALUE)
			short_time=-1;
		return short_time;
	}

	/**
	 * 
	 * @param start
	 * @param compared
	 * @param codeFactory
	 * @return
	 */
	public void compare(String start, String compared, List<String> codeFactory, List<String> comparedList,int times) {
		List<String> resultList = new ArrayList<String>();// 所有合法的基因序列的集合
		times++;
		flag: for (String str : codeFactory) {
			if (compared.equals(str)||comparedList.contains(str))
				continue;
			int count = 0;
			for (int i = 0; i < compared.length(); i++) {
				if (compared.charAt(i) != str.charAt(i)) {
					count++;
					if (count >= 2) {
						continue flag;
					}
				}

			}
			if (count != 1) {
				continue;
			}
			resultList.add(str);
		}
		comparedList.add(compared);
		if (resultList.contains(start)) {
			short_time = Math.min(times, short_time);
		} else {
			for (String compare : resultList) {
				compare(start, compare, codeFactory,comparedList,times);
			}
		}
	}

}