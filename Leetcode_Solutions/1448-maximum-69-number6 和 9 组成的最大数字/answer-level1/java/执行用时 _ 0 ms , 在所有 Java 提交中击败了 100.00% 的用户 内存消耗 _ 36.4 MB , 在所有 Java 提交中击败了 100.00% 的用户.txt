### 解题思路
找6

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        if(num/1000 == 6){
            return num+3000;
        }else if(num/100 == 96 || num/100 == 6){
            return num+300;
        }else if(num/10 == 996 || num/10 == 96 || num/10 == 6){
            return num+30;
        }else if(num == 6 || num == 96 || num == 996 || num == 9996){
            return num+3;
        }else{
            return num;
        }
    }
}
```