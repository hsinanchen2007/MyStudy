### 解题思路
前后两个指针;
一个向前，一个向后，依次比较；
比较时注意转换为小写字母；

### 代码

```c

bool isPalindrome(char * s){
    //两个指针，一个向后遍历,一个向前遍历;
    //找到下一个字母或数字，比较是否相同;
    
    if(s==NULL)return false;

    int p1=0;
    int p2=strlen(s)-1; 

    //循环,直到p1>=p2,退出;
    while(p1<p2)
    {
        //第一个指针找到数字或字母;
        while(!isalnum(s[p1])&&p1<p2)p1++; //跳过不是字母或数字的字符;
                                                    //在内部也要判断p1,p2的位置,及时跳出;
        while(!isalnum(s[p2])&&p1<p2)p2--;
        
        //比较两个字符;
        if(tolower(s[p1])!=tolower(s[p2]))  
            return false;
        //更新位置;
        p1++;
        p2--;

    }
    return true;


}

```