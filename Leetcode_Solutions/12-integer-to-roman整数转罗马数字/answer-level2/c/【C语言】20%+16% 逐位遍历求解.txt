### 解题思路
1.思路比较简单：逐位遍历求解。
2.corner condition：
边界条件比较多，4、9、40、90、400、900等，都是特殊条件，所以选择了逐位遍历；
3.知识点总结：
无特殊知识点需要记录。
4.耗时：24mins，比较满意，哈~~。主要耗时点：
（1）尽量取大的单位来实现数的表示-----读题理解题意是这道题的关键；
![image.png](https://pic.leetcode-cn.com/83a6bbfbbabf9e100276596baeb8edc68bd4fea6efb6f7612dd91e6c795473a4-image.png)


### 代码

```c
char * intToRoman(int num){
    int k = 0;
    int h = 0;
    int t = 0;
    int s = 0;
    int temp = 0;
    char *ret = NULL;
    int i = 0;
    ret = (char *)malloc(100 * sizeof(char));
    memset(ret, '\0', 100 * sizeof(char));
    k = (int)(num / 1000);
    //printf("k = %d\n",k);
    if(k != 0) {
        for(i = 0; i < k; i++) {
            ret[i] = 'M';
        }
    }
    h = (int)((num - k * 1000)/100);
    //printf("h = %d\n",h);
    if(h != 0) {
        if(h == 4) {
            ret[i] = 'C';
            i++;
            ret[i] = 'D';
            i++;
        }
        else if(h == 9){
            ret[i] = 'C';
            i++;
            ret[i] = 'M';
            i++;
        }
        else if(1 <= h && h < 4) {
            temp = i;
            for(i; i < temp + h; i++) {
                ret[i] = 'C';
            }
        }
        else if(5 <= h && h < 9) {
            ret[i] = 'D';
            i++;
            temp = i + h - 5;
            for(i; i < temp; i++) {
                ret[i] = 'C';
            }
        }
    }
    t = (int)((num - k * 1000 - h * 100)/10);
    //printf("t = %d\n",t);
    if(t != 0) {
        if(t == 4) {
            ret[i] = 'X';
            i++;
            ret[i] = 'L';
            i++;
        }
        else if(t == 9){
            ret[i] = 'X';
            i++;
            ret[i] = 'C';
            i++;
        }
        else if(1 <= t && t < 4) {
            temp = i;
            for(i; i < temp + t; i++) {
                ret[i] = 'X';
            }
        }
        else if(5 <= t && t < 9) {
            ret[i] = 'L';
            i++;
            temp = i + t - 5;
            for(i; i < temp; i++) {
                ret[i] = 'X';
            }
        }
    }

    s = (int)((num - k * 1000 - h * 100 - t * 10)/1);
    //printf("s = %d\n",s);
    if(s != 0) {
        if(s == 4) {
            ret[i] = 'I';
            i++;
            ret[i] = 'V';
            i++;
        }
        else if(s == 9){
            ret[i] = 'I';
            i++;
            ret[i] = 'X';
            i++;
        }
        else if(1 <= s && s < 4) {
            temp = i;
            for(i; i < temp + s; i++) {
                ret[i] = 'I';
            }
        }
        else if(5 <= s && s < 9) {
            ret[i] = 'V';
            i++;
            temp = i + s - 5;
            for(i; i < temp; i++) {
                ret[i] = 'I';
            }
        }
    }    

    return ret;
}
```