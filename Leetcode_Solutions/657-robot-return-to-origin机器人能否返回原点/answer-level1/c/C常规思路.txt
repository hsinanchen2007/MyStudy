### 解题思路
![Snipaste_2020-03-07_15-54-26.png](https://pic.leetcode-cn.com/162697a67db2923988c02c24d0fed4492ea22ed219e6295346412f01b6c7c7e1-Snipaste_2020-03-07_15-54-26.png)

只要水平和垂直方向的操作相互抵消就可回到原点。因此操作次数必为偶数次。分别记录两方向上的移动，如水平方向向右加一向左减一，最后只要两方向值均为0即可

### 代码

```c
bool judgeCircle(char * moves){
    int vertic=0,level=0;
    int len=strlen(moves);
    if(len==0) return true;
    if(len%2!=0) return false;
    int i;
    for(i=0;i<len;i++){
        switch(moves[i]){
            case 'R':
                level++;
                break;
            case 'L':
                level--;
                break;
            case 'U':
                vertic++;
                break;
            case 'D':
                vertic--;
                break;
        }
    }
    if(vertic==0&&level==0) return true;
    else return false;
}
```