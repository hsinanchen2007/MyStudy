### 解题思路
类似于洗牌的方法，由于数目就26个，可以将每个字母映射到一个大小为26的数组value里去，初始化都为0；

1、通过遍历==的场景（'=' == equations[i][1]），如果第一次遇到某个字母，则将这个字母对应的数组值value[i-'a']赋值为temp(temp从1开始)；

- 如果再次遇到这个字母，则将其他相等的字母对应的数组值赋值为temp；

- 如果遇到两个都是新的字母，且对应数组值都为0，则temp++，将新字母赋值为temp；

- 如果遇到两个字母值都大于0，且不相等，则temp++，遍历value数组，将等于这两个字母原来值的地方都赋值为temp；

2、通过!=检验true或者false，两种情况返回false，其他的默认返回true

- 如果!=的左边大于0，且左边value等于右边value，返回false

- 如果左边跟右边是同一个字母，返回false



### 代码

```c
bool equationsPossible(char ** equations, int equationsSize){
    
    int i,j = 0;
    int temp,val0,val3 = 0;

    // 26个字母，0~25表示a-z，value[x]表示'a'+x的字母
    int value[26] = {0};

    // 遍历所有的==的场景，将相等的字母对应的value都赋值为1
    for( i=0; i<equationsSize; i++)
    {
        val0 = value[equations[i][0]-'a'];
        val3 = value[equations[i][3]-'a'];

        if('=' == equations[i][1])
        {
            if( val0 == 0 && val3 == 0 )
            {
                temp ++;
                value[equations[i][0]-'a'] = temp;
                value[equations[i][3]-'a'] = temp;
            }
            else if(val0 > 0 && val3 == 0)
            {
                value[equations[i][3]-'a'] = val0;
            }
            else if(val3 > 0 && val0 == 0)
            {
                value[equations[i][0]-'a'] = val3;
            }
            else if(val0 > 0 && val3 > 0 && val0!=val3)
            {
                temp ++;

                for(j=0;j<26;j++)
                {
                    
                    if(value[j] == val0 || value[j] == val3)
                    {
                        value[j] = temp;
                    }
                }
            }
        }
    } 

    // 遍历!=的场景，如果两边确实不相等，就不返回，如果两边相等，就返回false
    for( i=0; i<equationsSize; i++)
    {
        val0 = value[equations[i][0]-'a'];
        val3 = value[equations[i][3]-'a'];

        if('!' == equations[i][1])
        {
            if(val0 > 0)
            {
                if(value[equations[i][0]-'a'] == val3)
                {
                    return false;
                }
            }
            else
            {
                if(equations[i][0] == equations[i][3])
                {
                    return false;
                }
            }
        }
    }

    return true;
}
```