### 解题思路
求next数组

### 代码

```c

void get_next(char *needle,int *next,int len){
    next[0]=-1;
    int i=0;
    int j=-1;
    while(i<len){
        if(j==-1||needle[i]==needle[j]){
            ++i;
            ++j;
            next[i]=j;
        }
        else j=next[j];
    }
}
int kmp(char *haystack,char *needle,int *next){
    int i=0;
    int j=0;
    int lenh=strlen(haystack);
    int lenn=strlen(needle);
    while(i<lenh&&j<lenn){
        if(j<lenn&&haystack[i]!=needle[j]){
           if(j!=0){	
        		j=next[j];	
			}
            else {
            	i++;	
			}
        }
        else if(j<lenn&&haystack[i]==needle[j]){
            i++;
            j++;          
        }
        if(j==lenn){
                return i-lenn;
                break;
            }
        
    }
    return -1;
}
int strStr(char * haystack, char * needle){
    
    int len=strlen(needle);
    int len2=strlen(haystack);
    if(len==0&&len2==0)return 0;
    if(len==0)return 0;
    if(len2==0)return -1;
    int next[len+3];
    int position=-1;
    get_next(needle,next,len);
    position=kmp(haystack,needle,next);
    return position;
}


```