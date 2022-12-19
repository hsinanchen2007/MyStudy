1、numRows=1，直接返回；
2、numRows=2，偶数位置+奇数位置，然后拼接返回；
3、numRows>=3时，首先要找出第0行的下标的规则：step=numRows +（numRows-2）；
4、下标对step进行取余，获取到所在行，如果余数小于numRows，则直接为所在行，否则step-余数为所在行；

```
class Solution {
    public String convert(String s, int numRows) {
        if(s.length() <= numRows) {
			return s;
		}
        
        if(numRows == 1) {
            return s;
        }
        
        if(numRows == 2) {
            StringBuilder oddBuilder = new StringBuilder();
            StringBuilder evenBuilder = new StringBuilder();
            for(int i = 0; i < s.length(); i++) {
                if(i%2==0) {
                    evenBuilder.append(s.charAt(i));
                } else {
                    oddBuilder.append(s.charAt(i));
                }
            }
            
            return evenBuilder.append(oddBuilder).toString();
        }
        
        //对应行数列表
		List<StringBuilder> list = new ArrayList<StringBuilder>();

		for(int i = 0; i < numRows; i++) {
			list.add(new StringBuilder());
		}

		int step = numRows + (numRows - 2);


		for(int i = 0; i < s.length(); i++) {
			int index = i % step;

			int destListIndex = index < numRows ? index : step - index;
			list.get(destListIndex).append(s.charAt(i));
		}

		StringBuilder resultBuilder = new StringBuilder();
		for(int i = 0; i < list.size(); i++) {
			resultBuilder.append(list.get(i));
		}


		return resultBuilder.toString();
    }
}
```

