思路：indexOf
循环石头S，定义count,石头遇到宝石count++

```
public static int numJewelsInStones(String J, String S) {
    int count = 0;
    for (int i = 0; i < S.toCharArray().length; i++) {
        if(J.indexOf(S.toCharArray()[i])!=-1){
            count++;
        }
    }
    return count;
}
```
