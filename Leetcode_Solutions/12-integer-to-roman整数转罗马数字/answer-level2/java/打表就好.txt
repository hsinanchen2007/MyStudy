### 解题思路
既然说了。规则。数字从大到小拆分，按照表打印对于项即可。

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        String reps[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        StringBuilder res = new StringBuilder();
        for(int i=0; i<13; i++){
            while(num>=values[i]){
                num -= values[i];
                res.append(reps[i]) ;
            }
        }
        return res.toString();
    }
}
```