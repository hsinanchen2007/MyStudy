### 解题思路
此处撰写解题思路

### 代码

```java小白，欢迎同学指点，感激不尽
class Solution {
    public int romanToInt(String s) {
        char a[] = s.toCharArray();
        int num = 0;
        int t;
      Map<Character,Integer> MoveToNum = new HashMap<Character,Integer>();
      MoveToNum.put('I',1);
      MoveToNum.put('V',5);
      MoveToNum.put('X',10);
      MoveToNum.put('L',50);
      MoveToNum.put('C',100);
      MoveToNum.put('D',500);
      MoveToNum.put('M',1000);
     for(int i = 0; i < a.length - 1; i++){
         if(MoveToNum.get(a[i]) < MoveToNum.get(a[i+1]))
           t = MoveToNum.get(a[i]) *-1;
         else
           t = MoveToNum.get(a[i]) *1;
        num +=  t;
     }
     return num + MoveToNum.get(a[a.length - 1]);

    }
}
```