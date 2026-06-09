### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        int m = 1000;
        StringBuilder res = new StringBuilder();
        while(num != 0 && m != 0) {
            int c = num / m, tmp = c;
            if (c >= 5) {
                if(c== 9) {
                    res.append(getCharOfNum(m)).append(getCharOfNum(10*m));
                } else {
                    res.append(getCharOfNum(5*m));
                    c -= 5;
                    while (c != 0) {
                        res.append(getCharOfNum(m));
                        c--;
                    }
                }
            }else if (c < 5) { // 
                if(c<=3) {
                    while(c != 0) {
                        res.append(getCharOfNum(m));
                        c--;
                    }
                } else if (c==4) {
                    res.append(getCharOfNum(m)).append(getCharOfNum(5*m));
                } 
                
            } 
            num -= tmp * m;
            m /= 10;        
        }

        return res.toString();
    }

    public char getCharOfNum(int m) {
        switch (m) {
            case 1000:
                return 'M';
            case 500:
                return 'D';
            case 100:
                return 'C';
            case 50:
                return 'L';
            case 10:
                return 'X';
            case 5:
                return 'V';
            case 1:
                return 'I';
            default:
                return 'I';    
        }
    }

}
```

从高位到低位每次读取十进制的一位，分四种情况：
1. 当前位数是9
2. 当前位数是5到8
3. 当前位数是4
4. 当前位数是1到3
第一、三种情况则是当前位数权重（如十位则是10）对应的罗马字符加上高一位或者当前位数权重的5倍对应的多码字符（如9则是‘I’+‘X’，4是‘I’+‘V’）；
第二种情况是当前位数权重的5倍对应的字符加上剩余几个当前位数的字符（如8是‘V’+‘I’*3）
第四种情况是当前位数权重对应的字符×n（如3是‘I’*3）