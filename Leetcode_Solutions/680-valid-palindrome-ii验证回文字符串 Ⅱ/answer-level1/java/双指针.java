### 解题思路
此处撰写解题思路
双指针问题，只是这里要解决一个问题，就是删除一个元素后仍然是回文数的判断问题。
因为不是道是删除左边的还是右边的元素，所以要都判断一下，当其中有一个是回文数时，就是回文数了
### 代码

```java
class Solution {
    public boolean validPalindrome(String s) {
        int i=0,j=s.length()-1;
        while(i<j){
            char ci=s.charAt(i);
            char cj=s.charAt(j);
            if(ci!=cj){
                return isPa(s,i+1,j)||isPa(s,i,j-1);
 
            }
            i++;
            j--;
        }
        return true;
    }
    private boolean isPa(String s,int i,int j){
        while(i<j){
            char ci=s.charAt(i);
            char cj=s.charAt(j);
            if(ci!=cj) return false;
            i++;
            j--;
        }
        return true;
    }
}
```