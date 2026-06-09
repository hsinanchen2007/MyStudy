![image.png](https://pic.leetcode-cn.com/8ba33c5b6192e812a5112aa4770a00189e4d1977088777e5ab7d34042ed96cb5-image.png)

![image.png](https://pic.leetcode-cn.com/0be4668c5814c78169bb0aa2be6d09d27008a918794417f68d76b93495d91386-image.png)

```
    public int minimumSwap(String s1, String s2) {  
        int cnty = 0;
        int cntx = 0;
        for(int i = 0; i < s1.length(); i++) {
            char c = s1.charAt(i);
            if(c == s2.charAt(i)) {
                continue;
            }
            //统计第一个字符串的对应位不同的x、y数量即可
            if(c == 'x') {
                cntx++;
            } else {
                cnty++;
            }
        }
        if(cntx % 2 == cnty % 2) {
            return (cntx % 2 == 0) ? (cntx + cnty) / 2 : (cntx + cnty) / 2 + 1;
        }
        return -1;
    }
```
