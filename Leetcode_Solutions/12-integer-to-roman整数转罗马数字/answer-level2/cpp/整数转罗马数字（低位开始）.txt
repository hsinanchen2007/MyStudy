一看到这道题，我首先想到的是罗马数字的取值范围其实很小，只有从
# 1~3999
这不到4000个数（可能奴隶主没有那么多奴隶需要管理蛤蛤LOL）。
那么其实我们完全可以用暴力的方法查表求解。

但是为了挑战一下自己，我想用整除获得低位的方式完成。获得低位数
字后，除4，5和9需要特殊处理以外，其它数字每输出一个该分位对应的单位
一（个位对应“I”，十位对应“X”），就自减一，重复循环，0跳出循环。

最后，为了最后顺序输出字符串，我们申请一个字符数组进行逆序存储。
罗马数在
# 3888
时取得最长的15位，为了节省空间，我们申请一个16位的数组。

```
char * intToRoman(int num){
    char * ret = NULL;
    if (num <= 0 || num > 3999) return ret;
    ret = (char *) malloc (sizeof(char) * 16);
    if (ret == NULL) {
        printf("申请内存出错");
        exit(0);
    }
    ret[15] = 0; // memset(ret, 0, 16);
    
    char Rome[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    char i = 14, j = 0, m = 0;
    
    while(num) {
        m = num % 10;
        num /= 10;
        while (1) {
            if (m == 9) {ret[i--] = Rome[j+2]; m = 1;}
            else if (m == 8) {ret[i--] = Rome[j]; m--;}
            else if (m == 7) {ret[i--] = Rome[j]; m--;}
            else if (m == 6) {ret[i--] = Rome[j]; m--;}
            else if (m == 5) {ret[i--] = Rome[j+1]; break;}
            else if (m == 4) {ret[i--] = Rome[j+1]; m=1;}
            else if (m == 3) {ret[i--] = Rome[j]; m--;}
            else if (m == 2) {ret[i--] = Rome[j]; m--;}
            else if (m == 1) {ret[i--] = Rome[j]; break;}
            else break;
        }
        j += 2;
    }
    return (ret + i + 1);
}
```
    这样，我们就完成了一个跑的比香港记者还快的解法(=·w·=)
![图片.png](https://pic.leetcode-cn.com/1d5d2c34c2d3297b7c2fc7b91b8e683c06b873e2232d7eaea987de2e535a2c40-%E5%9B%BE%E7%89%87.png)

![图片.png](https://pic.leetcode-cn.com/17eccfa9d7e405aa1a7d197402af92fb2f2fc5fe5df284c212a270e5b15602ee-%E5%9B%BE%E7%89%87.png)