### 解题思路
此处撰写解题思路
判断当前位与下一位的大小，当前位大于下一位：当前位为正数；
                        当前问小于下一位：当前位为负数；
将每一位全加起来就行，最后一位不用判断，直接加；
如例题 MCMXCIV：1994    
                第一位M： M>C 为+1000；
	            第二位C：  C< M 为-100；
		        第三位M： M>X 为+1000；
		        第四位X:    X < C 为-10；
		        第五位C： C > I 为+100；
		        第六位I ： I< V 为-1；
		        第七位：最后一位直接加 ：+5；
1000- 100 + 1000 -10 + 100 - 1 +5 = 1994； 

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int preNum = getValue(s.charAt(0));
        int sum = 0;
        for(int i = 1;i < s.length(); i ++) {
            int nextNum = getValue(s.charAt(i));
            if(preNum >= nextNum){
                sum +=preNum;
            }else{
                sum -=preNum;
            }
            preNum = nextNum;
        }
        sum +=preNum;
        return sum;
    }

    private int getValue(char ch){
        switch (ch){
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
             default: return 0;
        }
    }
}
```