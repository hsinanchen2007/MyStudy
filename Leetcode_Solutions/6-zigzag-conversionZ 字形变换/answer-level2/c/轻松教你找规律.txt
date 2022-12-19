### 解题思路
此处撰写解题思路
这题明显是个找规律的题， 观察图形可以知道“循环体”为一个"Z"字，即0-7，8-15是一个循环
![图片1.png](https://pic.leetcode-cn.com/f482ccb6dd69ec097a54611463490640a41282e351fc6cd9da9b87f833b68e17-%E5%9B%BE%E7%89%871.png)

对于循环最常用的就是取%运算，通过简单观察可知，循环体的长度为2*numSize -2
有了循环体长度之后，自然是对s[i]取模了，即s[i] % (2*numSize -2)
现在开始分类
0 % （2*numSize -2） = 0；  
1 %  （2*numSize -2）= 1；             
.........                    
numSize % （2*numSize -2） = numSize;    

判断条件：j % （2*numSize -2) == i  || j %（2*numSize -2) == 2*numSize - 2 - i

### 代码

```c
char * convert(char * s, int numRows){
    int n = strlen(s);
    if (numRows == 1) return s;
    char* res = (char*)malloc(sizeof(char) * (n + 1));
    int k = 0;
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < n; j++) {
            if (j % (2 * numRows - 2) == i || 
            j % (2 * numRows - 2) == 2 * numRows - 2 - i) {
                res[k++] = s[j];
            }
        }
    }
    res[k] = '\0';
    return res;
}
```