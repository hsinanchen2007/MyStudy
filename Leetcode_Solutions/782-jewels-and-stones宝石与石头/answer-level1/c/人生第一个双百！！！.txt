### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/7ac233be2c70cf2a567fa2f0397b472a7d8d694a28825f4dfa8e8deaf4e1c9ac-image.png)

### 代码

```c
int numJewelsInStones(char * J, char * S){
    int i,j,ret=0,a=strlen(S),b=strlen(J);

    for(j=0;j<b;j++)
    {
        for(i=0;i<a;i++)
        {
            if(S[i]==J[j])
            ret++;
        }
    }
    return ret;
}
```