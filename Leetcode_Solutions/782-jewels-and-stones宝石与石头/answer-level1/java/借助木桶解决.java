牺牲空间换时间
本来只想到暴力求解的，但两个for循环真的太菜了，看了另一位兄台的解答，发现可以使用木桶解决法。即设置58个木桶代表26个大写和26个小写字母，遍历J将宝石标记为1，再遍历S将是宝石用计数变量count表示

### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        byte[]  bow = new byte[58];   
        int count = 0;
        for(char ch : J.toCharArray()){
            bow[ch-65] = 1;
        }                          //宝石标志置1
        for(char ch : S.toCharArray()){
            if(bow[ch-65] == 1){
                count ++ ;
            }                      //在石头中找到宝石计时器count加1
        }
        
        return count;
    }
}
```