1. 使用map映射roman 和 int <br>
2. 解析roman串，从末位向前逐一映射成int然后相加，有三种特殊情况时进行减法操作，最终得到结果 <br>
3. 特殊情况分析，从题目描述可以看出特殊情况时前后两数之和分别是 6/11，60/110，600/1100，
    可抽象为 (i1+i2)%6 == 0 || (i1+i2)%11 == 0 <br>
4. 具体实现代码:
```java
public class Solution {

    private HashMap<Character, Integer> romanMap = new HashMap<Character, Integer>();

    {
        romanMap.put('I',1);
        romanMap.put('V',5);
        romanMap.put('X',10);
        romanMap.put('L',50);
        romanMap.put('C',100);
        romanMap.put('D',500);
        romanMap.put('M',1000);
    }

    public int romanToInt(String s){
        int len = s.length() - 1;
        int res = romanMap.get(s.charAt(len));
        for(int i = len; i > 0; i--){
            res = sumTwoRoman(s.charAt(i),s.charAt(i - 1),res);
        }
        return res;
    }

    private int sumTwoRoman(Character r1,Character r2,int res){
        int i1 = romanMap.get(r1);
        int i2 = romanMap.get(r2);
        int i3 = i1+i2;

        if(i2 < i1 && (i3 % 6 == 0 || i3 % 11 == 0)){
            res -= i2;
        } else{
            res += i2;
        }

        return res;
    }
}
```
5.复杂度分析<br>
- 空间复杂度 = O(1)
-  romanToInt()的时间复杂度 = O(n)
- sumTwoRoma()时间复杂度 = O(1)
- 总时间复杂度 =  O(n) * O(1) = O(n)

备注：如果有您认为不对的地方请指出

