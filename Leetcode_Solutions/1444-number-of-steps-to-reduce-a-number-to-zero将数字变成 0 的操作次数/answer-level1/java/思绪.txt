### 解题思路
此处撰写解题思路
我的思路:
    先创建一个统计步数的变量，
    再死循环里面判断这个num的值是否是偶数，还是奇数，最后当num的值小于等于0的时候跳出循环，直接返回len；
### 代码

```java
class Solution {
    public int numberOfSteps (int num) {
        int len=0;

        while(true){
            len++;
            if(num%2==0){
                num=num/2;
            }else{
                num=num-1;
            }
            if(num<=0){
                break;
            }
        }
        return len;
    }
}
```