核心的想法就是从二进制地位开始相加，可能存在三个结果：
0：0+0；
1：1+0；
2：1+1；
3：1+1+1；（ps：第三个1是上一位的进位）
只有当值为2或者3时才会有进位，将进位标识符置为1，下一位相加时将标识符相加;

准备工作，将两个字符串转换为两个数组，要求两个数组的长度相同，且长度小的要高位补0；
真是一点技巧都没有
```
class Solution {
    public String addBinary(String a, String b) {
       
		//寻找a和b的最大长度
		int alen = a.length();
		int blen = b.length();
		int max = alen>=blen?alen:blen ;
		//将a字符串转换为字符数组fromA
		char[] formA = a.toCharArray();
		//声明一个数组aArr  长度为最大值+1
		char[] aArr = new char[max+1];
		//将fromA由低位到高位按序存储到aArr
		for (int i = max; i > 0; i--) {
			if(alen > 0){
				aArr[i] = formA[alen-1];
			}
			alen--;
		}
        //高位补0
		for (int i = 0; i < aArr.length; i++) {
			if(aArr[i] == '\0'){
				aArr[i] = '0';
			}
		}
		
		//将b字符串转换为字符数组fromB
		char[] formB = b.toCharArray();
		//声明一个数组bArr  长度为最大值+1
		char[] bArr = new char[max+1];
		//将fromB由低位到高位按序存储到bArr
		for (int i = max; i > 0; i--) {
			if(blen > 0 ){
				bArr[i] = formB[blen-1];
			}
			blen--;
		}
		for (int i = 0; i < bArr.length; i++) {
			if(bArr[i] == '\0'){
				bArr[i] = '0';
			}
		}
        //开始计算
    	int up = 0;//进位标识符
    	char[] endCharArr = new char[max+1];
    	for (int i = max; i >= 0 ; i--) {
    		int ac = charToInt(aArr[i]);
    		int bc = charToInt(bArr[i]);
    		int temp = ac + bc + up;
	    		if(temp == 0){
	    			up = 0;
	    			endCharArr[i] = '0';
	    		}else if(temp == 1){
	    			up = 0;
	    			endCharArr[i] = '1';
	    		}else if(temp == 2){
	    			up = 1;
	    			endCharArr[i] = '0';
	    		}else if(temp == 3){
	    			up = 1;
	    			endCharArr[i] = '1';
	    		}  			
		}
    	String endStr = new String(endCharArr);
    	if(count0(endStr)){
    		return "0";
    	}
    	//记录第一个不为0的下标，从高位开始
    	int c0 = 0;
    	for (int i = 0; i < endCharArr.length; i++) {
			if(endCharArr[i] != '0'){
				c0 = i;
				break;
			}
		}
        if(c0>0){
    		 return new String(Arrays.copyOfRange(endCharArr, c0, endCharArr.length));
    	}
		return new String(endCharArr);
    }
     
    //该方法实现字符转换数字
    public  int charToInt(Character c){
    	return Integer.parseInt(c.toString());
    }
    
    //该方法实现数字转换字符
    public  char intToChar(Integer c){
    	return c.toString().toCharArray()[0];
    }
    
    //判断字符串是否全为0
    public  boolean count0(String str){
        int count = 0;
        boolean flag = false;
        char[] arrStr = str.toCharArray();
        for (int i = 0; i < arrStr.length; i++) {
            if(arrStr[i] == '0'){
                count++;
            }
        }
        if(count == arrStr.length){
            flag = true;
        }
        return flag;
    }
}
```
