### 解题思路
暂时想不到什么方便的方法，就直接暴力法了。


tips:此处代码非源码，作者为了方便浏览而对一些阅读不顺畅的代码进行了一些小修改，修改后没有进行测试（明天有课，要早点休息，现在都还没洗澡呢）。
如有人踩坑了欢迎评论区指正。 2020-04-08 23:12

### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        int i=0,j=0,time=0;
        int n=first.length(),m=second.length();
        if(n-m>1||n-m<-1) return false;//长度差大于1直接结束
        char[] firstString=first.toCharArray(),secondString=second.toCharArray();
        while(i<n&&j<m){
            if(time>1)return false;//增加跳出限制，有两次即退出
            if(firstString[i]==secondString[j]){//相同则继续循环
                i++;
                j++;
                continue;
            }
            if(j+1<m&&firstString[i]==secondString[j+1]){//如遇插入（即second的j+1字符等于first的i字符）则把second的指针j加一；
                j++;
            }
            else if(i+1<n&&firstString[i+1]==secondString[j]){//如遇删除（即first的i+1字符等于second的j字符）则把first的指针i加一；
                i++;
            }else if(i+1<n&&j+1<m&&firstString[i+1]==secondString[j+1]){//如遇替换（即first的i+1字符等于second的j+1字符）则把两者的指针i和j加一；
                i++;
                j++;
            }
            time++;//修改次数+1；
            i++;
            j++;
        }
        if(time==0){
            return true;
        }else if(time==1&&i==n&&j==m){//可能会遇到指针“i”或“j”还没到队尾的情况，此情况代表后面必定还有错误所以需要在这加个检查
            return true;
        }else return false;
    }
}
```