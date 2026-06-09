题目简单，思路也很简单。

双指针指向头尾，相等就继续往中间走，不相等，就判断是左边删一个元素还是右边删一个元素往中间走，但是需要

注意只能发生一次删除。

这里需要注意的是先判断两个数不相等的情况，因为后者while循环可能会导致high<low，这显然会出错。
```
bool validPalindrome(char * s){
    int length=strlen(s);
    int low=0,high=length-1;//双指针
    int posi,posj;//删除的元素个数
    while(low<high)
    {
        if(s[low]!=s[high])//两个数不相等,删除一个数
        {
            
            if((high-low)==1)
            return true;
            posi=low+1,posj=high;//删除左边的
            while(posi<posj)
            {
                if(s[posi]!=s[posj])
                {
                    break;
                }
                posi++;
                posj--;
            }
            
            if(posi==posj||posi>posj)
            return true;
             posi=low,posj=high-1;//删除左边的
            while(posi<posj)
            {
                if(s[posi]!=s[posj])
                {
                    break;
                }
                posi++;
                posj--;
            }
            if(posi==posj||posi>posj)
            return true;
            return false;
        }
        while(low<high&&s[low]==s[high])
        {
            low++;
            high--;
        }
    }
    return true;
}
```
