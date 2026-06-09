### 解题思路
首先做的就是双指针的事情，建立索引，while循环，比较字符串中的字符值
第二步：如果首尾遍历相同，i++，j--转向下一个比较，
        如果i,j遍历不同的话，开始调用huiwen函数（自定义）
第三步：这两个元素不相同，我就要比较i+1，j或者是i,j-1两种情况,
         两种情况的结果都可以作为返回
第四步：huiwen函数中其实和前三步做的工作差不多，如果传入的两个参数依旧找不到相同的，那说删除后还不是回文串，返回一个false;
有一点特殊的在于：中间值最后也都是相同了，所以也不影响

### 代码

```java
class Solution {
    public boolean validPalindrome(String s) {
        int i=0;
        int j=s.length()-1;

        while(i<j){
            if(s.charAt(i)!=s.charAt(j)){
                return huiwen(s,i+1,j)||huiwen(s,i,j-1);  
                //调用这个huiwen函数，有两种删除的结果，一个是i+,一个是j+
            }
            i++;
            j--;
        }
        return true;
    }

    private boolean huiwen(String s,int i,int j){
        //回文函数里面其实写的和主函数的方法差不多，其实就是参数穿递发生了变化
        while(i<j){
            if(s.charAt(i)!=s.charAt(j)){
                return false;
                }
            i++;
            j--;
            }       
        return true;
    }
}
//这道题的重点在于如何删除，因为删除的那个元素不确定
```