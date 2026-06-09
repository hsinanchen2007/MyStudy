将字符串中出现的不同字符存储到list中并进行排序，然后根据list中元素的顺序分别上升下降的存储到stringbuffer中。
```
public static String sortString(String s) {
	List<Character> list=new ArrayList<>();
	List<Character> letter=new ArrayList<>();
	char[] letters=s.toCharArray();
	for(int i=0;i<letters.length;i++) {
		letter.add(letters[i]);
		if(!list.contains(letters[i])) {
			list.add(letters[i]);
		}
	}
	Collections.sort(list);
	StringBuffer sb=new StringBuffer();
	while(letter.size()>0) {
		//上升
		for(int i=0;i<list.size();i++) {
			if(letter.contains(list.get(i))) {
				sb.append(list.get(i));
				//然后将letter中对应的元素减去
				letter.remove(letter.indexOf(list.get(i)));
			}
		}
		if(letter.size()==0) {
			break;
		}
		//下降
		for(int i=list.size()-1;i>=0;i--) {
			if(letter.contains(list.get(i))) {
				sb.append(list.get(i));
				//然后将letter中对应元素相减
				letter.remove(letter.indexOf(list.get(i)));
			}
		}
	}
	return sb.toString();
}
```
