##
- 执行用时 :38 ms, 在所有 Java 提交中击败了34.32% 的用户
- 内存消耗 :45.7 MB, 在所有 Java 提交中击败了69.70%的用户
##
```
public static String convert(String s, int numRows){
		if(numRows==1){
			return s;
		}else{
			char[] arr=s.toCharArray();
			StringBuffer sb=new StringBuffer();
			int top=2*numRows-3;
			int step=2*numRows-2;
			List<Integer> num=new ArrayList<Integer>();
			List<Integer> result=new ArrayList<Integer>();
			num.add(0);
			for(int i=1;i<numRows;i++){
				num.add(i);
				if(top>numRows-1){
					num.add(top--);
				}	
			}
			//找出符合首行下标
			for(int i=0;i<arr.length;i++){
				if((step*i)<arr.length){
					result.add(step*i);
				}else{
					break;
				}
			}
			//找出符合中间若干行的下标
			for(int i=1;i<num.size()-1;i+=2){
				for(int j=0;j<arr.length;j++){
					if((num.get(i)+step*j)<arr.length){
						result.add(num.get(i)+step*j);					
					}
					if((num.get(i+1)+step*j)<arr.length){
						result.add(num.get(i+1)+step*j);
					}else{
						break;
					}
				}			
			}
			//找出符合最后一行的下标
			for(int i=0;i<arr.length;i++){
				if((numRows-1+step*i)<arr.length){
					result.add(numRows-1+step*i);
				}else{
					break;
				}
			}
			//组成新字符串
			for(Integer n:result){
				sb.append(arr[n]);
			}
			return sb.toString();
		}	
	}
```
