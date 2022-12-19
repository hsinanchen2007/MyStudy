每一个字母组合记作n为3或4进制的一个数值.
```
char[][] numChar = {
		{'a', 'b', 'c'},
		{'d', 'e', 'f'},
		{'g', 'h', 'i'},
		{'j', 'k', 'l'},
		{'m', 'n', 'o'},
		{'p', 'q', 'r', 's'},
		{'t', 'u', 'v'}, 
		{'w', 'x', 'y', 'z'}
		};

public List<String> letterCombinations(String digits) {
	List<String> list = new ArrayList<>();
	if(digits==null || digits.isEmpty())return list;
	int[] indexs = new int[digits.length()];//每一位数字对应的字母
	int[] record = new int[digits.length()];//每一位字母使用的下标
	for(int i=0; i<digits.length(); i++) {
		indexs[i] =digits.charAt(i)-'2';
		record[i] = 0;
	}
	while(true) {
		StringBuilder builder = new StringBuilder();
		for(int i=0; i<indexs.length; i++) {
			builder.append(numChar[indexs[i]][record[i]]);
		}
		list.add(builder.toString());
		record[0]++;//最低位加1
		for(int i=0; i<record.length; i++) {
			if(record[i]>=numChar[indexs[i]].length) {//本位的字母用完了进位
				if(i==record.length-1) {
					return list;
				}else {
					record[i] = 0;
					record[i+1] = record[i+1]+1;
				}
			}
		}
	}
}
```
