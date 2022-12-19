### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int a=0;
        while (num!=0){
            if(num%2==0){
                num=num/2;
                a++;
            }else {
                num-=1;
                a++;
            }
        }
        return a;

    }
}
```