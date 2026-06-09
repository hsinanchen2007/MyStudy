```
class Solution {
    public String intToRoman(int num) {
	int[] number={1,4,5,9,10,40,50,90,100,400,500,900,1000};
	
	String[] Roman={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	
	StringBuilder code=new StringBuilder();
	while(num>0){
		for(int i=0;i<number.length;i++){
			if((i+1)<=number.length-1&&num>=number[i+1]){
				continue;
			}else{
				num-=number[i];
				
				code.append(Roman[i]);
				break;
			}
		}
	}
	
	return code.toString();
    }
}
```
我是先把组合情况列出来，再进行减值计算.
//	用StringBuilder来应对字符串的连接时比较提高性能，因为String反编译的时候也是转换成stringbuilder


