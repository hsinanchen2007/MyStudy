### 解题思路
难点在于：条件的判断

### 代码

```c
bool repeatedSubstringPattern(char * s){
    int repeatLength = 1;
    int len,i;
    bool inc;

    len = strlen(s);
    if(len == 1) 
        return false;

    for(repeatLength = 1; repeatLength <= len / 2; repeatLength++) 
    {
        inc = false;
        if(len % repeatLength != 0) {
            continue;                //一步步循环遍历找到步数
        }
        for(i = 0; i < len - repeatLength; i += repeatLength )
        {
            if(memcmp(&s[i], &s[i+repeatLength], repeatLength)) {   //memcmp判断是否相等：这位不相等
                inc = true;
                break;
            }
        }

        if(inc) {
            continue;   //不相等则继续
        }
        return true;    //当inc没被再次赋值为true，那么就说明一直重复
    }
    return false;       //循环没有进行下去，一直未x重复跳出循环返回false
}


```