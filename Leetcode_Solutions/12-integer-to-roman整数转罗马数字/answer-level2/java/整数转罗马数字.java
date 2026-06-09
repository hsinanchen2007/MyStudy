有点暴力，但是运行时间和内存还说的过去。

```
class Solution {
    public String intToRoman(int num) {
        String d1000[]={"","M","MM","MMM"};
        String d100[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
		String d10[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
		String d1[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
		int divide=1,numcopy=num,numkey=-1;
		String str = "";
		//计算最高位
		while(numcopy >= 10) {
			divide *= 10;
			numcopy /=10;
		};
		//除数不为0的时候结束
		while(divide != 0){
			numkey = num/divide;
			if(divide == 1000){
				str += d1000[numkey];
				num %= divide;
				divide /= 10;
				continue;
			}else if(divide == 100){
				str += d100[numkey];
				num %= divide;
				divide /= 10;
				continue;
			}else if(divide == 10){
				str += d10[numkey];
				num %= divide;
				divide /= 10;
				continue;
			}
			str += d1[numkey];
			num %= divide;
			divide /= 10;
		}
        return str;
    }
}
```
