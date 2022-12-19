### 解题思路
用哈希map写的，
主要是通过比较左边的值和右边的值大小来决定是加还是减，
当多个数字相等的时候，要一直判断到最后一个不相等数字的时候，是左边大还是右边大，
如果左边大，那循环的所有相等的数是正号，如果是小的话就是负号

### 代码

```java
class Solution {
    public int romanToInt(String s) {
     Map<Character,Integer> map = new HashMap<>();
        map.put('I',1);
        map.put('V',5);
        map.put('X',10);
        map.put('L',50);
        map.put('C',100);
        map.put('D',500);
        map.put('M',1000);
        char[] s1 = s.toCharArray();
        int num=0;
        int i,num1 = 0;
        int size = s.length();
        for (i = 0; i < size-1; i++) {
            if (map.get(s1[i]) > map.get(s1[i + 1])) {
                num += map.get(s1[i]);
            }
            else  if(map.get(s1[i])==map.get(s1[i + 1])){
                while((i<size-1)&&map.get(s1[i])==map.get(s1[i + 1])){
                    num1 += map.get(s1[i]);
                    i++;
                }
                if((i<size-1)&&map.get(s1[i])>map.get(s1[i + 1])) {
                    num1 += map.get(s1[i]);
                    num +=num1;
                }
                else if((i<size-1)&&map.get(s1[i])<map.get(s1[i + 1])) {
                    num1 += map.get(s1[i]);
                    num -= num1;
                }
                else if(i==size-1){
                    num +=num1;
                    break;
                }

            }
            else{
                num -= map.get(s1[i]);
            }
            num1 = 0;
        }

        num += map.get(s1[i]);


        return num;
    }
}
```