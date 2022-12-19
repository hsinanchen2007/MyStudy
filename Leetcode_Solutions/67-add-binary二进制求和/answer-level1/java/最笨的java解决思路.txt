### 代码
```java
class Solution {
    public static String addBinary(String a, String b) {
		int aL = a.length();
		int bL = b.length();
		
		String str = "";
		if(aL > bL) {
			int cL = aL - bL;
			for(int i = 0; i < cL; i++) {
				str += "0";
			}
			b = str + b;
		}else if(aL < bL) {
			int cL = bL - aL;
			for(int i = 0; i < cL; i++) {
				str += "0";
			}
			a = str + a;
		}
		
		String flag = "0";
		List<String> arr = new ArrayList<>();
		for(int j = a.length() - 1; j >= 0; j--) {
			if(a.charAt(j) == '1' && b.charAt(j) == '1') {
				if(flag.equals("0")) {
                    if(j == 0) {
                        arr.add("0");
                        arr.add("1");
                    }else{
                        arr.add("0");
					    flag = "1";
                    }
				}else if(flag.equals("1")) {
					if(j == 0) {
						arr.add("1");
						arr.add("1");
					}else {
						arr.add("1");
						flag = "1";
					}
					
				}
			}
			
			if(a.charAt(j) == '0' && b.charAt(j) == '0') {
				if(flag.equals("0")) {
					arr.add("0");
					flag = "0";
				}else if(flag.equals("1")) {
					if(j == 0) {
						arr.add("1");
						arr.add("1");
					}else {
						arr.add("1");
						flag = "0";
					}
				}
			}
			
			if((a.charAt(j) == '1' && b.charAt(j) == '0') 
            || (a.charAt(j) == '0' && b.charAt(j) == '1')) {
				if(flag.equals("0")) {
					arr.add("1");
					flag = "0";
				}else if(flag.equals("1")) {
					if(j == 0) {
						arr.add("0");
						arr.add("1");
					}else {
						arr.add("0");
						flag = "1";
					}
					
				}
			}
		}
		
        Collections.reverse(arr);

        String result = listToString(arr);

		return result;
		
    }

    public static String listToString(List list) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < list.size(); i++) {
            sb.append(list.get(i));
        }
        return list.isEmpty() ? "" : sb.toString().substring(0, sb.toString().length());
    }
}
```