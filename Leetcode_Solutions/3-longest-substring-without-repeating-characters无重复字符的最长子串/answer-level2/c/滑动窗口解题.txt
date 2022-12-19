### 解题思路
left标志窗口左端，right标志窗口右端，i,j控制左右窗口移动，分以下情况

s[i]!=s[j]时，判断i与j之间的元素与j是否相等，

设s[k]==s[j],left=k+1,right=j+1;
s[k]!=s[j],k++

s[i]==s[j]时，left左移，right不变
i++


### 代码

```c
int lengthOfLongestSubstring(char * s){
    //滑动窗口
    int left,right,n=1,max=1,i=0,j=1,k;
    if(strlen(s)==0)
    {
        return 0;
    }
    if(strlen(s)==1)
    {
        return 1;
    }
    while(i<strlen(s)&&j<strlen(s))
    {
        if(s[i]!=s[j])//当i，j不等
        {
            n=1;//计数器置位i-j
            for(k=i;k<j;k++)//判断i，j之间的数是否相等
            {
                if(s[k]==s[j])//如果找到相等的
                {
                    left=k+1;//令left=位置加一
                    right=j+1;//right不变
                    break;
                }
                else 
                {
                    left=i;//否则left不变，right+1
                    right=j+1;
                    n++;//从i开始不相等的计数
                }
            }
            i=left;//令i=left
            j=right;//j=right
        }
        else{//若i，j相等
            
            i++;
            j++;
            n=j-i;
        }
        if(max<n)
            {
                max=n;
            }
    }
    return max;

}
```