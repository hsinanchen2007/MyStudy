```java
public boolean buddyStrings(String A, String B) {

		// 如果A 、 B中有一个长度小于2的，则直接返回false
		if (A.length() < 2 || B.length() < 2) {
			return false;
		}
		// 如果长度不相等，返回false
		if (A.length() != B.length()){
			return false;
		}
		
		char[] aArray = A.toCharArray();
		
		List<Character> aCharacters = new ArrayList<>();
		//如果a b相等，则在a中找某一个元素是否重复出现，如果存在返回TRUE，否则false
		if (A.equals(B)){
			for (int i=0; i<aArray.length; i++){
				if (aCharacters.contains(aArray[i])){
					return true;
				}else{
					aCharacters.add(aArray[i]);
				}
			}
			
			return false;
		}
		
		// 从头开始交换，然后比较是否相等
		char[] bArray = B.toCharArray();
		for (int i = 0; i < aArray.length - 1; i++) {
			//如果元素相等，则不比较
			if (aArray[i] == bArray[i]){
				continue;
			}
			for (int j = i + 1; j < aArray.length; j++) {
				
				//如果要交换的字符相等，则循环不交换, 或者上次交换的和这次交换的一样
				if(aArray[i] == aArray[j] || aArray[j] == aArray[j-1]){
					continue;
				}
				StringBuilder stringBuilder = new StringBuilder();

				// 拼接i前面的子串
				stringBuilder.append(A.substring(0, i));

				// 拼接j
				stringBuilder.append(aArray[j]);

				// 拼接i到j
				stringBuilder.append(A.substring(i + 1, j));

				// 拼接i
				stringBuilder.append(aArray[i]);

				// 拼接j+1到字符串结尾
				if (j < aArray.length - 1) {
					stringBuilder.append(A.substring(j + 1));
				}

				if (stringBuilder.toString().equals(B)) {
					return true;
				}
			}
		}

		return false;
	}