### 解题思路
此处撰写解题思路

### 代码

```c
bool isAnagram(char * s, char * t){
    int sArray[26] = {0};
    //int tArray[26] = {0};

    int sNum = strlen(s);
    int tNum = strlen(t);
    int i,j;
    
    if(sNum != tNum)//如果二者数量不同，肯定不是
        return false;

     if(sNum == tNum)
     {
        for(i= 0;i < sNum;i++)
        {
            for(j = 0;j < 26;j++)
            {
                if(s[i] == 'a'+j)
                sArray[ s[i] - 'a' ]++; 
                if(t[i] == 'a'+j) 
                sArray[ t[i] - 'a' ]--;
            }
        }
     }

    for(i = 0;i < 26; i++)
    {
        if(sArray[i] != 0) //只有在二者字符完全相等时，数组元素都为0；
            return false;
    }
    return true;
}

```