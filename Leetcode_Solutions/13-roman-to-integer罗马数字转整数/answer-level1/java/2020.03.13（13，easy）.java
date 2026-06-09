### 解题思路
本题是将罗马数字转成整数字

需要进行for循环逐个遍历，使用**字符转数字**的功能函数用**switch-case**语句将罗马数字转成数字

其中要区分类似 IV,VI 的判断条件，前者是需要减一下，后者则直接相加即可

### 代码

```java
class Solution {
    public int romanToInt(String s) {
        int n = s.length();
        int sum  = 0;
        int preNum = getValue(s.charAt(0));//记录第一个值
        for(int i = 1; i < n; i++){//从第二个数字开始往后遍历
            int num = getValue(s.charAt(i));
            if(preNum < num){
                sum -= preNum;//像IV,IX,XL是需要后一个减前一个
            }else{
                sum += preNum;//像VI,XI,LX是前一个直接加上后一个
            }
            preNum = num;//更新前一个指向，不断往后遍历
        }
        sum += preNum;//for循环里面没有算上最后一个值，这里需要加一下
        return sum;
    }
    
    private int getValue(char ch){//字符转数字 功能函数
        switch(ch){
            case 'I' : return 1;
            case 'V' : return 5;
            case 'X' : return 10;
            case 'L' : return 50;
            case 'C' : return 100;
            case 'D' : return 500;
            case 'M' : return 1000;
            default : return 0;
        } 
    }
}
```