```
class Solution {
   public static String convert(String s, int numRows) {
       if(numRows == 1){
           return s;
       }
		String[] sArray = new String[numRows];
		for (int i = 0; i < numRows; i++) {
			sArray[i] = "";
		}
		boolean change = false;
		int index = -1;
		String an = "";
		for (int i = 0; i < s.length(); i++) {
			char zimu = s.charAt(i);
			if (!change) { // 向下添加
				sArray[++index] += zimu;
				if (index == numRows - 1) {
					change = true;
					if(numRows == 2) {
						index = -1;
						change=false;
					}
					continue;
				}
			}
			if (change && index != 1) {
				sArray[--index] += zimu;
				
			}
			if (change && index == 1) {
				change = false;
				index = -1;
			 
			}
		}

		for (int i = 0; i < sArray.length; i++) {
			an += sArray[i];
		}
		return an;
	}
}
```
